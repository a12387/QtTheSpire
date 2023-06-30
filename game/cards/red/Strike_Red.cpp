#include "Strike_Red.h"

Strike_Red::Strike_Red() :
    AbstractCard(
        (std::string)"Strike_R",
        (std::string)"Strike",
        (std::string)":/game/resource/cards/strike.png",
        1,
        (std::string)"攻击\n造成6点伤害",
        AbstractCard::ATTACK,
        AbstractCard::RED,
        AbstractCard::BASIC,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Strike_Red::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->baseDamage,this->dType);
    m->damage(tmp);
}
AbstractCard *Strike_Red::makeCopy()
{
    return new Strike_Red;
}
