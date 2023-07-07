#include "ShrugItOff.h"

ShrugItOff::ShrugItOff() :
    AbstractCard(
        (std::string)"ShrugItOff",
        (std::string)"耸肩无视",
        (std::string)":/game/resource/cards/shrug_it_off.png",
        1,
        (std::string)"技能\n获得基础数值为10的格挡\n抽1张牌",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::COMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseBlock = 10;
}

void ShrugItOff::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->addBlock(baseBlock);
    p->drawCard(1);
}
AbstractCard *ShrugItOff::makeCopy()
{
    return new ShrugItOff;
}
