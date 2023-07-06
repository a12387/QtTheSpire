#include "usecard.h"
#include "ui_usecard.h"
#include "combatroom.h"
#include "mainwindow.h"
#include "cardgroupwidget.h"
#include "game/powers/BackAttackLeft.h"
#include "game/powers/BackAttackRight.h"
#include "map.h"
#include <algorithm>

UseCard::UseCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UseCard)
{
    ui->setupUi(this);



    cr = (CombatRoom*)parent;
    mw = cr->mw;

    setStyleSheet("background:transparent;");

    ui->confirmButton->hide();
    connect(ui->confirmButton,&QPushButton::clicked,this,&UseCard::useSelectedCard);
    ui->cancelButton->hide();
    connect(ui->cancelButton,&QPushButton::clicked,this,
            [=]()
            {
                cancelSelect();
            }
    );
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
    ui->energy->setText(QString("%1/3").arg(mw->d.player->energy));

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
    if(mw->d.player->energy >= c->card->cost)
    {
        if(selectedCard == nullptr)
            cardSelect(c);
        else if(selectedCard == c)
            cancelSelect();
        else
            changeSelect(c);
        if(selectedCard != nullptr)
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
    //else show Energy Not Enough



}
void UseCard::useSelectedCard()
{
    c = selectedCard->card;
    mw->d.player->hand.removeCard(c);
    mw->d.player->discardPile.addToTop(c);

    if(c->target == AbstractCard::ENEMY)
    {
        c->use(mw->d.player,(AbstractMonster*)(selectedCreature->c));
        if(selectedCreature->c->currentHealth <= 0)
            selectedCreature = nullptr;
    }
    else
        c->use(mw->d.player,nullptr);

    if(c->exhaust)
        c->exhaustCard();

    for(int i = 0; i < cr->monstersWidget.size(); i++ )
    {
        if(cr->monstersWidget[i]->c->currentHealth <= 0)
        {
            delete cr->monstersWidget[i];
            cr->monstersWidget.remove(i);
            i--;
        }
    }
    if(cr->monstersWidget.empty())
    {
        cr->showContinueButton();
    }

    switch(mw->d.floor-1){
    case 2:
        if(c->target == AbstractCard::ENEMY){
            if(selectedCreature == nullptr )
            {
                if(cr->monstersWidget.size()==1)
                {
                    if(cr->monstersWidget[0]->c->id == "SpireShield")
                    {
                        cr->playerWidget->turnLeft();
                        if(mw->d.player->direction == 1)
                        {
                            mw->d.player->direction = 0;
                            cr->monstersWidget[0]->c->buff.pop_front();
                        }
                    }
                    else
                    {
                        cr->playerWidget->turnRight();
                        if(mw->d.player->direction == 0)
                        {
                            mw->d.player->direction = 1;
                            cr->monstersWidget[0]->c->buff.pop_front();
                        }
                    }
                }
            }
            else if(selectedCreature->c->id=="SpireShield"){
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

        }
        break;
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
    selectedCard->bg->setStyleSheet("");
    selectedCard = nullptr;

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


void UseCard::changeSelect(CardButton *c)
{
    selectedCard->bg->setStyleSheet("");
    c->bg->setStyleSheet("border:5px solid rgb(255,255,0)");
    selectedCard = c;
}

void UseCard::callCardMultiSelection(CardGroup *c,int min_,int max_)
{
    CardGroupWidget *selectionScreen = new CardGroupWidget(true,c,parentWidget(),min_,max_);
    selectionScreen->show();
}

void UseCard::on_drawPileButton_clicked()
{
    mw->subScreen = new CardGroupWidget(false,&(mw->d.player->drawPile),mw->currentScreen);
    mw->subScreen->show();
}
void UseCard::on_discardPile_clicked()
{
    mw->subScreen = new CardGroupWidget(false,&(mw->d.player->discardPile),mw->currentScreen);
    mw->subScreen->show();
}
void UseCard::on_exhaustPile_clicked()
{
    mw->subScreen = new CardGroupWidget(false,&(mw->d.player->exhaustPile),mw->currentScreen);
    mw->subScreen->show();
}


