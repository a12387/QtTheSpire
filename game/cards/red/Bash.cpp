#include "Bash.h"
#include "../../powers/Vulnerable.h"
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
    baseDamage = 8;
    baseMagicNumber = 2;
}

void Bash::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    DamageInfo tmp = DamageInfo(p,this->baseDamage,this->dType);
    m->damage(tmp);
    m->ApplyPower(new Vulnerable(baseMagicNumber));
}
AbstractCard *Bash::makeCopy()
{
    return new Bash;
}
