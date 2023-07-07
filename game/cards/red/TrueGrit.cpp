#include "TrueGrit.h"
#include "mainwindow.h"
#include "combatroom.h"
TrueGrit::TrueGrit() :
    AbstractCard(
        (std::string)"TrueGrit",
        (std::string)"坚毅",
        (std::string)":/game/resource/cards/true_grit.png",
        1,
        (std::string)"技能\n获得基础数值为9的格挡，消耗一张手牌",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::COMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseBlock = 9;
}

void TrueGrit::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->addBlock(baseBlock);
    ((CombatRoom*)(mw->d.rooms[mw->d.floor - 1]->screen))->uc->callCardMultiSelection(&p->hand,1,1);
}
void TrueGrit::effect(AbstractCard *c)
{
    c->exhaustCard();
    mw->d.player->drawCard(baseMagicNumber);
}
AbstractCard *TrueGrit::makeCopy()
{
    return new TrueGrit;
}
