#include "Body_slam.h"

Body_slam::Body_slam() :
    AbstractCard(
        (std::string)"Body_slam_R",
        (std::string)"Body_slam",
        (std::string)":/game/resource/cards/body_slam.png",
        1,
        (std::string)"攻击\n造成6点伤害",
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

void Body_slam::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Body_slam::makeCopy()
{
    return new Body_slam;
}
