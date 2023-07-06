#include "shop.h"
#include "ui_shop.h"
#include "mainwindow.h"
#include "map.h"
#include "game/cards/RandomCard.h"
#include "statebar.h"


using namespace std;
Shop::Shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
    move(0,50);

    mw = (MainWindow*)parentWidget();

    RandomCard* cards[7]={};
    for(int i=0;i<7;i++){
        cards[i]=new RandomCard(this);
        if(i<5)cards[i]->c->move(220*i+10,0);
        else cards[i]->c->move(220*(i-5)+10,330);
        connect(cards[i]->c,&CardButton::chooseCardButton,this,&Shop::buyCard);
    }
}

Shop::~Shop()
{
    delete ui;
}

void Shop::on_continue_2_clicked()
{
    mw->subScreen = new Map(true,this);
    mw->subScreen->show();
}
void Shop::buyCard(CardButton*c){
    int price;
    switch(c->card->rarity)
    {
    case AbstractCard::COMMON:
        price = 50;
        break;
    case AbstractCard::UNCOMMON:
        price = 100;
        break;
    case AbstractCard::RARE:
        price = 150;
        break;
    default:
        price = 999;
        break;
    }
    if(mw->d.player->gold >= price)
    {
        mw->d.player->masterDeck.addToTop(c->card);
        mw->d.player->gold-=price;
        delete c;
        mw->stateBar->update();
    }
}
