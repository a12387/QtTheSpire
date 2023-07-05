#include "Finesse.h"

Finesse::Finesse() :
    AbstractCard(
        (std::string)"Finesse",
        (std::string)"妙计",
        (std::string)":/game/resource/cards/finesse.png",
        0,
        (std::string)"技能\n获得基础数值为2的格挡\n抽1张牌",
        AbstractCard::POWER,
        AbstractCard::COLORLESS,
        AbstractCard::UNCOMMON,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseBlock = 2;
    baseMagicNumber = 1;
}

void Finesse::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
}
AbstractCard *Finesse::makeCopy()
{
    return new Finesse;
}
