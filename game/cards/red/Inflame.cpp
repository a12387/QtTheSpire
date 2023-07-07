#include "Inflame.h"
#include "../../powers/Strength.h"
Inflame::Inflame() :
    AbstractCard(
        (std::string)"Inflame",
        (std::string)"燃烧",
        (std::string)":/game/resource/cards/inflame.png",
        1,
        (std::string)"能力\n获得3点力量",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseMagicNumber = 3;
}

void Inflame::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->ApplyPower(new Strength(baseMagicNumber));
}
AbstractCard *Inflame::makeCopy()
{
    return new Inflame;
}
