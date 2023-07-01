#include "usecard.h"
#include "ui_usecard.h"
#include "combatroom.h"
#include "mainwindow.h"
#include "game/powers/BackAttackLeft.h"
#include "game/powers/BackAttackRight.h"
UseCard::UseCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UseCard)
{
    ui->setupUi(this);

    cr = (CombatRoom*)parent;
    mw = cr->mw;

    selectedCard = nullptr;
    ui->confirmButton->hide();
    connect(ui->confirmButton,&QPushButton::clicked,this,&UseCard::useSelectedCard);
    ui->cancelButton->hide();
    connect(ui->cancelButton,&QPushButton::clicked,this,[=](){cancelSelect();});
    ui->scrollArea->setStyleSheet("QScrollBar:horizontal{height:15px;}");

    connect(ui->endTurnButton,&QPushButton::clicked,this,
            [=]()
            {
                for(auto &i: mw->d.player->hand.group)
                {
                    mw->d.player->discardPile.addToTop(i);

                }
                mw->d.player->hand.clear();
                update();
                emit endTurn();
            }
            );
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
            for(auto &i : cr->monstersWidget)
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

    mw->d.player->discardPile.addToTop(selectedCard->card);
    mw->d.player->hand.removeCard(selectedCard->card);

    switch(mw->d.floor){
    case 2:if(!selectedCreature->c->isPlayer){
            if(selectedCreature->c->id=="SpireShield"){
                cr->playerWidget->turnLeft();
                for(auto &i:mw->d.rooms[2]->monsters.monsters){
                    if(i->id=="SpireShield")i->buff.pop_front();
                    else if(i->id=="SpireSpear")i->buff.push_front(new BackAttackRight);
                }
            }
            else if(selectedCreature->c->id=="SpireSpear"){
                cr->playerWidget->turnRight();
                for(auto &i:mw->d.rooms[2]->monsters.monsters){
                    if(i->id=="SpireSpear")i->buff.pop_front();
                    else if(i->id=="SpireShield")i->buff.push_front(new BackAttackLeft);
                }
            }
        }break;
    case 3:mw->d.player->damage(mw->d.rooms[3]->monsters.monsters.front()->buff.front()->amount);break;
    default:break;
    }

    cancelSelect();

    cr->update();
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
    for(auto &i:cr->monstersWidget)
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
