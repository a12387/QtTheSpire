#include "Barricade.h"

Barricade::Barricade() :
    AbstractCard(
        (std::string)"Barricade_R",
        (std::string)"Barricade",
        (std::string)":/game/resource/cards/barricade_Red.png",
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

void Barricade::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Barricade::makeCopy()
{
    return new Barricade;
}
