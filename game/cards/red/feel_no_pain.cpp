#include "Feel_no_pain.h"

Feel_no_pain::Feel_no_pain() :
    AbstractCard(
        (std::string)"Feel_no_pain",
        (std::string)"Feel_no_pain",
        (std::string)":/game/resource/cards/feel_no_pain.png",
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

void Feel_no_pain::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Feel_no_pain::makeCopy()
{
    return new Feel_no_pain;
}
