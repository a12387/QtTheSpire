#include "Spot_weakness_Red.h"

Spot_weakness_Red::Spot_weakness_Red() :
    AbstractCard(
        (std::string)"Spot_weakness_R",
        (std::string)"Spot_weakness",
        (std::string)":/game/resource/cards/spot_weakness.png",
        1,
        (std::string)"攻击\n造成6点伤害",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Spot_weakness_Red::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Spot_weakness_Red::makeCopy()
{
    return new Spot_weakness_Red;
}
