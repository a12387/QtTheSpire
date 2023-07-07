#include "Cleave.h"
#include "mainwindow.h"
Cleave::Cleave() :
    AbstractCard(
        (std::string)"Cleave",
        (std::string)"顺劈斩",
        (std::string)":/game/resource/cards/cleave.png",
        1,
        (std::string)"攻击\n对全体敌人造成基础数值为11点的伤害",
        AbstractCard::ATTACK,
        AbstractCard::RED,
        AbstractCard::COMMON,
        AbstractCard::ALL_ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 11;
}

void Cleave::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    DamageInfo tmp = DamageInfo(p,this->baseDamage,this->dType);
    for(auto & i:mw->d.rooms[mw->d.floor - 1]->monsters.monsters)
    {
        i->damage(tmp);
    }
}
AbstractCard *Cleave::makeCopy()
{
    return new Cleave;
}
