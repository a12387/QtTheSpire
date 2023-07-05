#include "ShrugItOff.h"

ShrugItOff::ShrugItOff() :
    AbstractCard(
        (std::string)"ShrugItOff",
        (std::string)"耸肩无视",
        (std::string)":/game/resource/cards/shrug_it_off.png",
        1,
        (std::string)"技能\n获得基础数值为8的格挡\n抽1张牌",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::COMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void ShrugItOff::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *ShrugItOff::makeCopy()
{
    return new ShrugItOff;
}
