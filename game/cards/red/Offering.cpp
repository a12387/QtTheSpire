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
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Offering::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Offering::makeCopy()
{
    return new Offering;
}
