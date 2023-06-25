#ifndef OFFERING_RED_H
#define OFFERING_RED_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Offering_Red : public AbstractCard
{
public:
    Offering_Red();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // OFFERING_RED_H
