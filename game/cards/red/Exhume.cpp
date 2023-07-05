#include "Exhume.h"

Exhume::Exhume() :
    AbstractCard(
        (std::string)"Exhume_R",
        (std::string)"Exhume",
        (std::string)":/game/resource/cards/exhume.png",
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

void Exhume::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Exhume::makeCopy()
{
    return new Exhume;
}
