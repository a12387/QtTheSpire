#include "Bash.h"

Bash::Bash() :
    AbstractCard(
        (std::string)"Bash",
        (std::string)"痛击",
        (std::string)":/game/resource/cards/bash.png",
        2,
        (std::string)"攻击\n造成基础数值为8点的伤害\n给予2层易伤",
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

void Bash::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Bash::makeCopy()
{
    return new Bash;
}
