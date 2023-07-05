#include "BurningPact.h"

BurningPact::BurningPact() :
    AbstractCard(
        (std::string)"BurningPact",
        (std::string)"燃烧契约",
        (std::string)":/game/resource/cards/burning_pact.png",
        1,
        (std::string)"技能\n消耗一张牌\n抽2张牌",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void BurningPact::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *BurningPact::makeCopy()
{
    return new BurningPact;
}
