#include "DemonForm.h"
#include "game/powers/DemonForm_.h"

DemonForm::DemonForm() :
    AbstractCard(
        (std::string)"DemonForm",
        (std::string)"恶魔形态",
        (std::string)":/game/resource/cards/demon_form.png",
        3,
        (std::string)"能力\n在每回合开始时获得\n3点力量。",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseMagicNumber = 3;
}

void DemonForm::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->ApplyPower(new DemonForm_(baseMagicNumber));
}
AbstractCard *DemonForm::makeCopy()
{
    return new DemonForm;
}
