#include "BurningPact.h"
#include "mainwindow.h"
#include "combatroom.h"
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
    baseMagicNumber = 2;
}

void BurningPact::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    ((CombatRoom*)(mw->d.rooms[mw->d.floor - 1]->screen))->uc->callCardMultiSelection(&p->hand,1,1);
}
void BurningPact::effect(AbstractCard *c)
{
    mw->d.player->hand.removeCard(c);
    mw->d.player->exhaustPile.addToTop(c);
    mw->d.player->drawCard(baseMagicNumber);
}

AbstractCard *BurningPact::makeCopy()
{
    return new BurningPact;
}
