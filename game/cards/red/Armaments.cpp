#include "Armaments.h"
#include "mainwindow.h"
#include "combatroom.h"
Armaments::Armaments() :
    AbstractCard(
        (std::string)"Armaments",
        (std::string)"武装",
        (std::string)":/game/resource/cards/armaments.png",
        1,
        (std::string)"技能\n获得基础数值为5的格挡，在本场战斗中升级手牌中的一张牌",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::COMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseBlock = 5;
}

void Armaments::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->addBlock(baseBlock);
    ((CombatRoom*)(mw->d.rooms[mw->d.floor - 1]->screen))->uc->callCardMultiSelection(&p->hand,1,1);
}
AbstractCard *Armaments::makeCopy()
{
    return new Armaments;
}
