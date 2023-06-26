#include "Armaments.h"

Armaments::Armaments() :
    AbstractCard(
        (std::string)"Armaments_R",
        (std::string)"Armaments",
        (std::string)":/game/resource/cards/armaments.png",
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

void Armaments::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(*p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Armaments::makeCopy()
{
    return new Armaments;
}
