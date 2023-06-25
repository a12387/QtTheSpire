#include "Pommel_strike_Red.h"

Pommel_strike_Red::Pommel_strike_Red() :
    AbstractCard(
        (std::string)"Pommel_strike_R",
        (std::string)"Pommel_strike",
        (std::string)":/game/resource/cards/pommel_strike.png",
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

void Pommel_strike_Red::use(AbstractPlayer &p,AbstractMonster &m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m.damage(tmp);
}
AbstractCard *Pommel_strike_Red::makeCopy()
{
    return new Pommel_strike_Red;
}
