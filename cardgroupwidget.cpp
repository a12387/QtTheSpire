#include "cardgroupwidget.h"
#include "ui_cardgroupwidget.h"
#include "game/cards/CardGroup.h"
#include "cardbutton.h"
#include "mainwindow.h"
#include "combatroom.h"
CardGroupWidget::CardGroupWidget(bool selectable,CardGroup *cg, QWidget *parent,int min,int max) :selectable(selectable),
    QWidget(parent),min(min),max(max),
    ui(new Ui::CardGroupWidget)
{
    ui->setupUi(this);

    if(!selectable)
    {
        btn = new QPushButton(this);
        btn->setGeometry(40,500,180,75);
        btn->setText("Back");
        btn->setStyleSheet("font:bold 20px;");
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
        btn = new QPushButton(this);
        btn->setGeometry(480,500,180,75);
        btn->setText("Confirm");
        btn->setStyleSheet("font:bold 20px;");
        connect(btn,&QPushButton::clicked,this,
                [=]()
                {
                    CombatRoom *cr = ((CombatRoom*)parent);
                    for(auto &i:selectedCards)
                    {
                        cr->uc->c->effect(i->card);
                    }
                    cr->update();
                    close();
                });
        btn->setDisabled(true);
    }

    int s = cg->group.size();
    cg->group.sort();
    ui->scrollAreaWidgetContents->setMinimumHeight((s/5+1) * 282 + 30 );
    auto it = cg->group.begin();
    for(int i = 0; i < cg->group.size(); i++)
    {
        CardButton *c = new CardButton(*it,ui->scrollAreaWidgetContents);
        c->move(210 * (i%5) + 30,282 * (i/5) + 30);
        it++;
        connect(c,&CardButton::chooseCardButton,this,&CardGroupWidget::select);
    }

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
