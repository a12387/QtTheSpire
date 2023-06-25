#ifndef SECOND_WIND_RED_H
#define SECOND_WIND_RED_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Second_wind_Red : public AbstractCard
{
public:
    Second_wind_Red();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};

#endif // SECOND_WIND_RED_H
