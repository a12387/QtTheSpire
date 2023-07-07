#include "Offering.h"

Offering::Offering() :
    AbstractCard(
        (std::string)"Offering",
        (std::string)"祭品",
        (std::string)":/game/resource/cards/offering.png",
        0,
        (std::string)"技能\n失去6点生命。\n获得2点能量。\n抽5张牌。\n消耗 。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::SELF,
        DamageInfo::DamageType::HP_LOSS)
{
    exhaust = true;
    baseMagicNumber = 5;
}

void Offering::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;

    DamageInfo tmp = DamageInfo(p,6,this->dType);
    p->damage(tmp);

    p->energy += 2;

    p->drawCard(baseMagicNumber);
}
AbstractCard *Offering::makeCopy()
{
    return new Offering;
}
