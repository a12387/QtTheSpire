#include "Exhume.h"
#include "mainwindow.h"
#include "combatroom.h"
Exhume::Exhume() :
    AbstractCard(
        (std::string)"Exhume",
        (std::string)"Exhume",
        (std::string)":/game/resource/cards/exhume.png",
        1,
        (std::string)"技能\n选择一张已消耗的牌，将其放入你的手牌。\n消耗。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    exhaust = true;
}

void Exhume::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    ((CombatRoom*)(mw->d.rooms[mw->d.floor - 1]->screen))->uc->callCardMultiSelection(&p->exhaustPile,1,1);
}
void Exhume::effect(AbstractCard *c)
{
    mw->d.player->hand.addToBottom(c);
}
AbstractCard *Exhume::makeCopy()
{
    return new Exhume;
}
