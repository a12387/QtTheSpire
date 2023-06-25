#ifndef CORRUPTION_H
#define CORRUPTION_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Corruption : public AbstractCard
{
public:
    Corruption();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // CORRUPTION_H
