#include "Offering_Red.h"

Offering_Red::Offering_Red() :
    AbstractCard(
        (std::string)"Offering_R",
        (std::string)"Offering",
        (std::string)":/game/resource/cards/offering.png",
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

void Offering_Red::use(AbstractPlayer &p,AbstractMonster &m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m.damage(tmp);
}
AbstractCard *Offering_Red::makeCopy()
{
    return new Offering_Red;
}
