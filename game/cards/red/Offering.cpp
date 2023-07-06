#include "Offering.h"

Offering::Offering() :
    AbstractCard(
        (std::string)"Offering",
        (std::string)"祭品",
        (std::string)":/game/resource/cards/offering.png",
        0,
        (std::string)"技能\n失去6点生命。\n获得2点能量。\n抽3张牌。\n消耗 。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    exhaust = true;
    baseMagicNumber = 3;
}

void Offering::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;

    DamageInfo tmp = DamageInfo(p,6,DamageInfo::HP_LOSS);
    p->damage(6);

    p->energy += 2;

    p->drawCard(baseMagicNumber);
}
AbstractCard *Offering::makeCopy()
{
    return new Offering;
}
