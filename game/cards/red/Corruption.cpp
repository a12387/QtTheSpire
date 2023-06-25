#include "Corruption.h"

Corruption::Corruption() :
    AbstractCard(
        (std::string)"Corruption_R",
        (std::string)"Strike",
        (std::string)":/game/resource/cards/strike.png",
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

void Corruption::use(AbstractPlayer &p,AbstractMonster &m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m.damage(tmp);
}
AbstractCard *Corruption::makeCopy()
{
    return new Corruption;
}
