#include "Finesse.h"

Finesse::Finesse() :
    AbstractCard(
        (std::string)"Finesse",
        (std::string)"Finesse",
        (std::string)":/game/resource/cards/finesse.png",
        1,
        (std::string)"攻击\n造成6点伤害",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::BASIC,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Finesse::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(*p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Finesse::makeCopy()
{
    return new Finesse;
}
