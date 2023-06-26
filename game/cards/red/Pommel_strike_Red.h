#ifndef POMMEL_STRIKE_RED_H
#define POMMEL_STRIKE_RED_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Pommel_strike_Red : public AbstractCard
{
public:
    Pommel_strike_Red();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // POMMEL_STRIKE_RED_H
