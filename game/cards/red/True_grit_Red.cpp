#include "True_grit_Red.h"

True_grit_Red::True_grit_Red() :
    AbstractCard(
        (std::string)"True_grit_R",
        (std::string)"True_grit",
        (std::string)":/game/resource/cards/true_grit.png",
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

void True_grit_Red::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(*p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *True_grit_Red::makeCopy()
{
    return new True_grit_Red;
}
