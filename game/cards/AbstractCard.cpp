#include "AbstractCard.h"

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
