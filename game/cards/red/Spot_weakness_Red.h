#ifndef SPOT_WEAKNESS_RED_H
#define SPOT_WEAKNESS_RED_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Spot_weakness_Red : public AbstractCard
{
public:
    Spot_weakness_Red();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};

#endif // SPOT_WEAKNESS_RED_H
