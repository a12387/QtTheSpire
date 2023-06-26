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
    connect(ui->confirmButton,&QPushButton::clicked,this,&UseCard::useSelectedCard);
    ui->cancelButton->hide();
    connect(ui->cancelButton,&QPushButton::clicked,this,[=](){cancelSelect();});
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
    auto it = mw->d.player->hand.group.begin();
    for(auto &i:ui->scrollAreaWidgetContents->children())
    {
        if(dynamic_cast<CardButton*>(i)!=nullptr)
        {
            delete i;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cards.push_back(new CardButton(*it,ui->scrollAreaWidgetContents,143,200));
        it++;
        auto c = cards.back();
        c->move(i * 150,0);
        connect(c,&CardButton::chooseCard,this,
                [=]()
                {
                    if(selectedCard == nullptr)
                        cardSelect(c);
                    else if(selectedCard == c)
                        cancelSelect();
                    else
                        changeSelect(c);
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
void UseCard::setConfirmState(bool b)
{
    ui->confirmButton->setEnabled(b);
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
void UseCard::useSelectedCard()
{
    selectedCard->card->use(mw->d.player,(AbstractMonster*)(selectedCreature->c));

    qDebug()<<selectedCreature->c->currentHealth;

    mw->d.player->discardPile.addToTop(selectedCard->card);
    mw->d.player->hand.removeCard(selectedCard->card);

    cancelSelect();

    update();
}


void UseCard::cardSelect(CardButton *c)
{
    c->bg->setStyleSheet("border:5px solid rgb(255,255,0)");
    selectedCard = c;
}
void UseCard::cancelSelect()
{
    ui->confirmButton->hide();
    ui->cancelButton->hide();
    selectedCard->bg->setStyleSheet("");
    selectedCard = nullptr;
    if(selectedCreature)
    {
        selectedCreature->setFrameState(false);
        selectedCreature = nullptr;
    }
    for(auto &i:((CombatRoom*)parentWidget())->monstersWidget)
    {
        if(i->choose)
            i->choose = false;
    }
}
void UseCard::changeSelect(CardButton *c)
{
    selectedCard->bg->setStyleSheet("");
    c->bg->setStyleSheet("border:5px solid rgb(255,255,0)");
    selectedCard = c;
}
