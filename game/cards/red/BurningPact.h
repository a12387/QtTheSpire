#ifndef BURNINGPACT_H
#define BURNINGPACT_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class BurningPact : public AbstractCard
{
public:
    BurningPact();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // BURNINGPACT_H
