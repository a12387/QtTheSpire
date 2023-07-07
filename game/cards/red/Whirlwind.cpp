#include "Whirlwind.h"
#include "mainwindow.h"
Whirlwind::Whirlwind() :
    AbstractCard(
        (std::string)"Whirlwind",
        (std::string)"旋风斩",
        (std::string)":/game/resource/cards/whirlwind.png",
        -1,
        (std::string)"攻击\n对所有敌人造成基础数值为8点的伤害X次",
        AbstractCard::ATTACK,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::ALL_ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 8;
}

void Whirlwind::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,baseDamage,dType);
    while(p->energy > 0)
    {
        p->energy--;
        for(auto & i:mw->d.rooms[mw->d.floor - 1]->monsters.monsters)
        {
            i->damage(tmp);
        }
    }
}
AbstractCard *Whirlwind::makeCopy()
{
    return new Whirlwind;
}
