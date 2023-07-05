#ifndef OFFERING_H
#define OFFERING_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Offering : public AbstractCard
{
public:
    Offering();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // OFFERING_H
