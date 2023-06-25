#ifndef FINESSE_H
#define FINESSE_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Finesse : public AbstractCard
{
public:
    Finesse();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};

#endif // FINESSE_H
