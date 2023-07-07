#include "Barricade.h"
#include "game/powers/Barricade_.h"

Barricade::Barricade() :
    AbstractCard(
        (std::string)"Barricade",
        (std::string)"壁垒",
        (std::string)":/game/resource/cards/barricade.png",
        2,
        (std::string)"能力\n格挡不再在你的回合开始时消失。",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
}

void Barricade::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->ApplyPower(new Barricade_());
}
AbstractCard *Barricade::makeCopy()
{
    return new Barricade;
}
