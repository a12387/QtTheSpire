#include "DarkEmbrace.h"
#include "game/powers/DarkEmbrace_.h"

DarkEmbrace::DarkEmbrace() :
    AbstractCard(
        (std::string)"DarkEmbrace",
        (std::string)"黑暗之拥",
        (std::string)":/game/resource/cards/dark_embrace.png",
        1,
        (std::string)"能力\n每当有一张牌被消耗时，抽1张牌。",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{

}

void DarkEmbrace::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->ApplyPower(new DarkEmbrace_());
}
AbstractCard *DarkEmbrace::makeCopy()
{
    return new DarkEmbrace;
}
