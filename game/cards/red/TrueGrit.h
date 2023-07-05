#ifndef TRUEGRIT_H
#define TRUEGRIT_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class TrueGrit : public AbstractCard
{
public:
    TrueGrit();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // TRUEGRIT_H
