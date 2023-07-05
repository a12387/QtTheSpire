#include "Bash.h"

Bash::Bash() :
    AbstractCard(
        (std::string)"Bash_R",
        (std::string)"Bash",
        (std::string)":/game/resource/cards/bash.png",
        1,
        (std::string)"攻击\n造成6点伤害",
        AbstractCard::ATTACK,
        AbstractCard::RED,
        AbstractCard::COMMON,
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
