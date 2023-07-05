#include "Barricade.h"
#include "game/powers/Barricade_.h"

Barricade::Barricade() :
    AbstractCard(
        (std::string)"Barricade",
        (std::string)"壁垒",
        (std::string)":/game/resource/cards/barricade.png",
        3,
        (std::string)"能力\n格挡不再在你的回合开始时消失。",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Barricade::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->ApplyPower(new Barricade_());
}
AbstractCard *Barricade::makeCopy()
{
    return new Barricade;
}
