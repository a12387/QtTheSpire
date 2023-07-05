#include "Limit_break_Red.h"

Limit_break_Red::Limit_break_Red() :
    AbstractCard(
        (std::string)"Limit_break_R",
        (std::string)"Limit_break",
        (std::string)":/game/resource/cards/limit_break.png",
        1,
        (std::string)"攻击\n造成6点伤害",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Limit_break_Red::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Limit_break_Red::makeCopy()
{
    return new Limit_break_Red;
}
