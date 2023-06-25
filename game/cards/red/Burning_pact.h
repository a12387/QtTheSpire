#ifndef BURNING_PACT_H
#define BURNING_PACT_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Burning_pact : public AbstractCard
{
public:
    Burning_pact();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // BURNING_PACT_H
