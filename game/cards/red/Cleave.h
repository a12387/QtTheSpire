#ifndef CLEAVE_H
#define CLEAVE_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Cleave : public AbstractCard
{
public:
    Cleave();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // CLEAVE_H
