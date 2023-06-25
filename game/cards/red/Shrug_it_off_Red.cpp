#include "Shrug_it_off_Red.h"

Shrug_it_off_Red::Shrug_it_off_Red() :
    AbstractCard(
        (std::string)"Shrug_it_off_R",
        (std::string)"Shrug_it_off",
        (std::string)":/game/resource/cards/shrug_it_off.png",
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

void Shrug_it_off_Red::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(*p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Shrug_it_off_Red::makeCopy()
{
    return new Shrug_it_off_Red;
}
