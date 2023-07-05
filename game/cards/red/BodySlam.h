#ifndef BODYSLAM_H
#define BODYSLAM_H
#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class BodySlam : public AbstractCard
{
public:
    BodySlam();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};
#endif // BODYSLAM_H
