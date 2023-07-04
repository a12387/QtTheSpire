#include "usecard.h"
#include "ui_usecard.h"
#include "combatroom.h"
#include "mainwindow.h"
#include "cardgroupwidget.h"
#include "game/powers/BackAttackLeft.h"
#include "game/powers/BackAttackRight.h"
#include <algorithm>

UseCard::UseCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UseCard)
{
    ui->setupUi(this);

    cr = (CombatRoom*)parent;
    mw = cr->mw;

    ui->confirmButton->hide();
    connect(ui->confirmButton,&QPushButton::clicked,this,&UseCard::useSelectedCard);
    ui->cancelButton->hide();
    connect(ui->cancelButton,&QPushButton::clicked,this,
            [=]()
            {
                cancelSingleSelect();
            }
    );
    ui->multiConfirmButton->hide();
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
        connect(c,&CardButton::chooseCardButton,this,&UseCard::selectCardButton);

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

void UseCard::selectCardButton(CardButton *c)
{
    if(multiSelect == false)
    {
        if(selectedSingleCard == nullptr)
            cardSelect(c);
        else if(selectedSingleCard == c)
            cancelSingleSelect();
        else
            changeSelect(c);
        if(selectedSingleCard != nullptr)
        {
            ui->confirmButton->show();
            ui->cancelButton->show();
            if(c->card->target == AbstractCard::ENEMY)
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
    else
    {

        if(selectedMultiCard.indexOf(c) != -1)
            cancelMultiSelect(c);
        else if(selectedMultiCard.size() < maxNum)
            cardSelect(c);
    }
}
void UseCard::useSelectedCard()
{
    mw->d.player->discardPile.addToTop(selectedSingleCard->card);
    mw->d.player->hand.removeCard(selectedSingleCard->card);

    c = selectedSingleCard->card;

    c->use(mw->d.player,(AbstractMonster*)(selectedCreature->c));

    switch(mw->d.floor-1){
    case 2:if(!selectedCreature->c->isPlayer){
            if(selectedCreature->c->id=="SpireShield"){
                if(mw->d.player->direction==1){
                cr->playerWidget->turnLeft();
                mw->d.player->direction=0;
                for(auto &i:mw->d.rooms[2]->monsters.monsters){
                    if(i->id=="SpireShield")i->buff.pop_front();
                    else if(i->id=="SpireSpear")i->buff.push_front(new BackAttackRight);
                }
                }
            }
            else if(selectedCreature->c->id=="SpireSpear"){
                if(mw->d.player->direction==0){
                cr->playerWidget->turnRight();
                mw->d.player->direction=1;
                for(auto &i:mw->d.rooms[2]->monsters.monsters){
                    if(i->id=="SpireSpear")i->buff.pop_front();
                    else if(i->id=="SpireShield")i->buff.push_front(new BackAttackLeft);
                }
                }
            }
        }break;
    case 3:mw->d.player->damage(mw->d.rooms[3]->monsters.monsters.front()->buff.front()->amount);break;
    default:break;
    }

    if(!multiSelect)
        cancelSingleSelect();

    cr->update();
}


void UseCard::cardSelect(CardButton *c)
{
    c->bg->setStyleSheet("border:5px solid rgb(255,255,0)");
    if(multiSelect)
    {
        selectedMultiCard.push_back(c);
        if(selectedMultiCard.size()>=minNum)
        {
            ui->multiConfirmButton->setEnabled(true);
        }
    }

    else
        selectedSingleCard = c;
}
void UseCard::cancelSingleSelect()
{
    selectedSingleCard->bg->setStyleSheet("");
    selectedSingleCard = nullptr;

    ui->confirmButton->hide();
    ui->cancelButton->hide();
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

void UseCard::cancelMultiSelect(CardButton *c)
{
    c->bg->setStyleSheet("");
    selectedMultiCard.removeAll(c);

    if(selectedMultiCard.size() < minNum)
    {
        ui->multiConfirmButton->setDisabled(true);
    }
}
void UseCard::changeSelect(CardButton *c)
{
    selectedSingleCard->bg->setStyleSheet("");
    c->bg->setStyleSheet("border:5px solid rgb(255,255,0)");
    selectedSingleCard = c;
}

void UseCard::callCardMultiSelection(int min_,int max_)
{
    multiSelect = true;
    minNum = min_;
    maxNum = max_;
    ui->confirmButton->hide();
    ui->cancelButton->hide();
    ui->multiConfirmButton->show();
    ui->multiConfirmButton->setDisabled(true);
    ui->endTurnButton->setDisabled(true);
}

void UseCard::on_drawPileButton_clicked()
{
    mw->subScreen = new CardGroupWidget(&(mw->d.player->drawPile),mw->currentScreen);
    mw->subScreen->show();
}
void UseCard::on_discardPile_clicked()
{
    mw->subScreen = new CardGroupWidget(&(mw->d.player->discardPile),mw->currentScreen);
    mw->subScreen->show();
}
void UseCard::on_exhaustPile_clicked()
{
    mw->subScreen = new CardGroupWidget(&(mw->d.player->exhaustPile),mw->currentScreen);
    mw->subScreen->show();
}
void UseCard::on_multiConfirmButton_clicked()
{
    for(auto &i : selectedMultiCard)
    {
        c->effect(i);
    }
}

