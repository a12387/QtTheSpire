#include "SecondWind.h"

SecondWind::SecondWind() :
    AbstractCard(
        (std::string)"SecondWind",
        (std::string)"重振精神",
        (std::string)":/game/resource/cards/second_wind.png",
        1,
        (std::string)"技能\n消耗手牌中所有非攻击牌，每张获得5点格挡。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void SecondWind::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *SecondWind::makeCopy()
{
    return new SecondWind;
}
