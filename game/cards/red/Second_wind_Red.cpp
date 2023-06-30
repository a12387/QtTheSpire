#include "Second_wind_Red.h"

Second_wind_Red::Second_wind_Red() :
    AbstractCard(
        (std::string)"Second_wind_R",
        (std::string)"Second_wind",
        (std::string)":/game/resource/cards/second_wind.png",
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

void Second_wind_Red::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Second_wind_Red::makeCopy()
{
    return new Second_wind_Red;
}
