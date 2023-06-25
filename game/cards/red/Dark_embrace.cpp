#include "Dark_embrace.h"

Dark_embrace::Dark_embrace() :
    AbstractCard(
        (std::string)"Dark_embrace_R",
        (std::string)"Dark_embrace",
        (std::string)":/game/resource/cards/dark_embrace.png",
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

void Dark_embrace::use(AbstractPlayer &p,AbstractMonster &m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m.damage(tmp);
}
AbstractCard *Dark_embrace::makeCopy()
{
    return new Dark_embrace;
}
