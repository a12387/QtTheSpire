#include "Defend_Red.h"

Defend_Red::Defend_Red() :
    AbstractCard(
        (std::string)"Defend_Red",
        (std::string)"防御",
        (std::string)":/game/resource/cards/defend.png",
        1,
        (std::string)"技能\n获得基础数值为5点的格挡",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::BASIC,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseBlock = 5;
}

void Defend_Red::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->addBlock(baseBlock);
}
AbstractCard *Defend_Red::makeCopy()
{
    return new Defend_Red;
}
