#include "usecard.h"
#include "ui_usecard.h"
#include "combatroom.h"
#include "mainwindow.h"
UseCard::UseCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UseCard)
{
    ui->setupUi(this);

    mw = ((CombatRoom*)parent)->mw;

    selectedCard = nullptr;
    ui->confirmButton->hide();
    ui->cancelButton->hide();
    ui->scrollArea->setStyleSheet("QScrollBar:horizontal{height:15px;}");
}

UseCard::~UseCard()
{
    delete ui;
}

void UseCard::update()
{
    int n = mw->d.player->hand.group.size();
    ui->scrollAreaWidgetContents->setMinimumWidth(150 * n);
    for(int i = 0; i < n; i++)
    {
        cards.push_back(new CardButton(ui->scrollAreaWidgetContents,143,200));
        auto c = cards.back();
        c->move(i * 150,0);
        connect(c,&CardButton::chooseCard,this,
                [=]()
                {
                    if(selectedCard == nullptr)
                    {
                        c->bg->setStyleSheet("border:5px solid rgb(255,255,0)");
                        selectedCard = c;
                    }
                    else if(selectedCard == c)
                    {
                        selectedCard->bg->setStyleSheet("");
                        selectedCard = nullptr;
                    }
                    else
                    {
                        selectedCard->bg->setStyleSheet("");
                        c->bg->setStyleSheet("border:5px solid rgb(255,255,0)");
                        selectedCard = c;
                    }
                });
        connect(c,&CardButton::chooseCard,this,&UseCard::confirm);
        c->show();
    }
}

void UseCard::clear()
{
    for(auto &i : cards)
    {
        i->close();
    }
}

void UseCard::confirm(AbstractCard *c)
{
    if(selectedCard != nullptr)
    {
        ui->confirmButton->show();
        ui->cancelButton->show();
        if(c->target == AbstractCard::ENEMY)
        {
            ui->confirmButton->setDisabled(true);
            AbstractMonster *target;
            for(auto &i : ((CombatRoom*)parentWidget())->monstersWidget)
            {
                i->choose = true;
            }
        }
    }
    else
    {
        ui->confirmButton->hide();
        ui->cancelButton->hide();
    }
}
