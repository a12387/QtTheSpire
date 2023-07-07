#include "Bludgeon.h"

Bludgeon::Bludgeon() :
    AbstractCard(
        (std::string)"Bludgeon",
        (std::string)"重锤",
        (std::string)":/game/resource/cards/bludgeon.png",
        3,
        (std::string)"攻击\n造成基础数值为42点的伤害",
        AbstractCard::ATTACK,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 42;
}

void Bludgeon::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    DamageInfo tmp = DamageInfo(p,this->baseDamage,this->dType);
    m->damage(tmp);
}
AbstractCard *Bludgeon::makeCopy()
{
    return new Bludgeon;
}
