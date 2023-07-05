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
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void BodySlam::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *BodySlam::makeCopy()
{
    return new BodySlam;
}
