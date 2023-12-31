#include "cardgroupwidget.h"
#include "ui_cardgroupwidget.h"
#include "game/cards/CardGroup.h"
#include "cardbutton.h"
#include "mainwindow.h"
#include "combatroom.h"
CardGroupWidget::CardGroupWidget(bool selectable,CardGroup *cg_, QWidget *parent,int min,int max) :selectable(selectable),
    QWidget(parent),min(min),max(max),
    ui(new Ui::CardGroupWidget)
{
    ui->setupUi(this);

    CombatRoom *cr = ((CombatRoom*)parent);
    bool flag = false;

    if(!selectable)
    {
        btn = new QPushButton(this);
        btn->setGeometry(40,500,180,75);
        btn->setText("返回");
        connect(btn,&QPushButton::clicked,this,[=](){
            QWidget *tmp = this->parentWidget();
            while(!dynamic_cast<MainWindow*>(tmp)&&tmp != nullptr)
            {
                tmp = tmp->parentWidget();
            }
            if(tmp)
                ((MainWindow*)tmp)->subScreen = nullptr;
            close();
        });

    }
    else
    {
        if(cg_->group.empty()||cg_->group.size()<=min)
        {
            auto t = cg_->group;
            for(int i = 0;i < t.size(); i++)
            {
                cr->uc->c->effect(t[i]);
            }
            cr->update();
            flag = true;
        }
        btn = new QPushButton(this);
        btn->setGeometry(480,500,180,75);
        btn->setText("确定");
        connect(btn,&QPushButton::clicked,this,
                [=]()
                {

                    for(auto &i:selectedCards)
                    {
                        cr->uc->c->effect(i->card);
                    }
                    cr->update();
                    close();
                });
        btn->setDisabled(true);
    }

    btn->setStyleSheet("font: 20pt;border-image: url(:/game/resource/ui/endturn.png);color: rgb(255, 255, 255);");

    QVector<AbstractCard*> g(cg_->group);
    int s = g.size();
    std::sort(g.begin(),g.end(),[=](AbstractCard* a,AbstractCard* b){return a->id > b->id;});
    ui->scrollAreaWidgetContents->setMinimumHeight(((s-1)/5+1) * 282 + 30 );
    auto it = g.begin();
    for(int i = 0; i < g.size(); i++)
    {
        CardButton *c = new CardButton(*it,ui->scrollAreaWidgetContents);
        c->move(210 * (i%5) + 30,282 * (i/5) + 30);
        it++;
        connect(c,&CardButton::chooseCardButton,this,&CardGroupWidget::select);
    }

    show();
    if(flag)
        close();
}

CardGroupWidget::~CardGroupWidget()
{
    delete ui;
}
void CardGroupWidget::select(CardButton *c)
{
    if(selectable)
    {
        if(selectedCards.indexOf(c)==-1 && selectedCards.size()<max)
        {
            selectedCards.push_back(c);
            c->bg->setStyleSheet("border:5px solid rgb(255,255,0)");
            if(selectedCards.size()>=min)
                btn->setEnabled(true);
        }
        else if(selectedCards.indexOf(c)!=-1)
        {
            c->bg->setStyleSheet("");
            selectedCards.removeAll(c);
            if(selectedCards.size()<min)
                btn->setDisabled(true);
        }


    }
}
