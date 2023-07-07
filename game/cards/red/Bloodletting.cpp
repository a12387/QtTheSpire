#include "Bloodletting.h"

Bloodletting::Bloodletting() :
    AbstractCard(
        (std::string)"Bloodletting",
        (std::string)"放血",
        (std::string)":/game/resource/cards/bloodletting.png",
        0,
        (std::string)"技能\n获得3点能量\n失去3点生命",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::HP_LOSS)
{
    baseMagicNumber = 3;
}

void Bloodletting::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    DamageInfo tmp = DamageInfo(p,3,this->dType);
    p->damage(tmp);

    p->energy += baseMagicNumber;
}
AbstractCard *Bloodletting::makeCopy()
{
    return new Bloodletting;
}
