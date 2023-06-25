#include "Burning_pact.h"

Burning_pact::Burning_pact() :
    AbstractCard(
        (std::string)"Burning_pact_R",
        (std::string)"Burning_pact",
        (std::string)":/game/resource/cards/Burning_pact.png",
        1,
        (std::string)"攻击\n造成6点伤害",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::BASIC,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Burning_pact::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(*p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Burning_pact::makeCopy()
{
    return new Burning_pact;
}
