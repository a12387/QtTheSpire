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

    e=new QSoundEffect(this);
    e->setSource(QUrl("qrc:/game/resource/audio/music/Shop.wav"));
    e->setLoopCount(QSoundEffect::Infinite);
    e->play();

    mw = (MainWindow*)parentWidget();

    AbstractCard* cards[7]={};

    cards[0] = RandomCard::getAttackCard()->makeCopy();

    while(true)
    {
        cards[1] = RandomCard::getAttackCard()->makeCopy();
        if(*cards[1] != *cards[0])
            break;
        delete cards[1];
    }

    cards[2] = RandomCard::getSkillCard()->makeCopy();

    while(true)
    {
        cards[3] = RandomCard::getSkillCard()->makeCopy();
        if(*cards[3] != *cards[2])
            break;
        delete cards[3];
    }
    while(true)
    {
        cards[4] = RandomCard::getSkillCard()->makeCopy();
        if(*cards[4] != *cards[3] && *cards[4] != *cards[2])
            break;
        delete cards[4];
    }

    cards[5] = RandomCard::getPowerCard()->makeCopy();

    while(true)
    {
        cards[6] = RandomCard::getPowerCard()->makeCopy();
        if(*cards[6] != *cards[5])
            break;
        delete cards[6];
    }

    CardButton *cardBtns[7];
    for(int i=0;i<7;i++){
        cardBtns[i]=new CardButton(cards[i],this);
        if(i<5)cardBtns[i]->move(220*i+10,0);
        else cardBtns[i]->move(220*(i-5)+10,330);
        connect(cardBtns[i],&CardButton::chooseCardButton,this,&Shop::buyCard);
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
    QSoundEffect*d=new QSoundEffect();
    if(mw->d.player->gold >= price)
    {
        mw->d.player->masterDeck.addToTop(c->card);
        mw->d.player->gold-=price;
        delete c;
        mw->stateBar->update();
        d->setSource(QUrl("qrc:/game/resource/audio/sound/CardSelect.wav"));
    }
    else d->setSource(QUrl("qrc:/game/resource/audio/sound/CardReject.wav"));
    d->play();
}
