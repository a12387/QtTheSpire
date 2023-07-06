#include "AbstractCard.h"
#include "mainwindow.h"
#include "../powers/AbstractPower.h"
MainWindow *AbstractCard::mw = nullptr;

AbstractCard::AbstractCard(std::string id, std::string name, std::string imgUrl, int cost, std::string description, CardType type, CardColor color, CardRarity rarity, CardTarget target, DamageInfo::DamageType dType = DamageInfo::NORMAL) :
    id(id),name(name),imgUrl(imgUrl),cost(cost),description(description),type(type),color(color),rarity(rarity),target(target),dType(dType){}
AbstractCard::~AbstractCard(){}
void AbstractCard::upgrade() {}
void AbstractCard::effect(AbstractCard *c){}
void AbstractCard::use(AbstractPlayer *abstractPlayer, AbstractMonster *abstractMonster) {}

bool AbstractCard::operator==(const AbstractCard &c)
{
    return (id == c.id)&&(upgraded == c.upgraded);
}
void AbstractCard::exhaustCard(){
    mw->d.player->drawPile.removeCard(this);
    mw->d.player->discardPile.removeCard(this);
    mw->d.player->hand.removeCard(this);
    mw->d.player->exhaustPile.addToTop(this);
    for(auto i=mw->d.player->buff.begin();i!=mw->d.player->buff.end();++i){
        if((*i)->name=="DarkEmbrace")mw->d.player->drawCard((*i)->amount);
        else if((*i)->name=="FeelNoPain")mw->d.player->currentBlock+=(*i)->amount;
    }
}
