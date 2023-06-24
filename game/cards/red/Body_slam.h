#ifndef BODY_SLAM_H
#define BODY_SLAM_H
#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Body_slam : public AbstractCard
{
public:
    Body_slam();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};
#endif // BODY_SLAM_H
