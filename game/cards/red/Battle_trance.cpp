#include "Battle_trance.h"

Battle_trance::Battle_trance() :
    AbstractCard(
        (std::string)"Battle_trance_R",
        (std::string)"Battle_trance",
        (std::string)":/game/resource/cards/battle_trance.png",
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

void Battle_trance::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Battle_trance::makeCopy()
{
    return new Battle_trance;
}
