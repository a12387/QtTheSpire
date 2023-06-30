#include "Inflame_Red.h"

Inflame_Red::Inflame_Red() :
    AbstractCard(
        (std::string)"Inflame_R",
        (std::string)"Inflame",
        (std::string)":/game/resource/cards/inflame.png",
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

void Inflame_Red::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Inflame_Red::makeCopy()
{
    return new Inflame_Red;
}
