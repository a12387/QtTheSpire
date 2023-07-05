#include "BodySlam.h"

BodySlam::BodySlam() :
    AbstractCard(
        (std::string)"BodySlam",
        (std::string)"全身撞击",
        (std::string)":/game/resource/cards/body_slam.png",
        1,
        (std::string)"攻击\n造成基础数值为你当前格挡值的伤害",
        AbstractCard::ATTACK,
        AbstractCard::RED,
        AbstractCard::COMMON,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 0;
}

void BodySlam::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    DamageInfo tmp = DamageInfo(p,p->currentBlock,this->dType);
    m->damage(tmp);
}
AbstractCard *BodySlam::makeCopy()
{
    return new BodySlam;
}
