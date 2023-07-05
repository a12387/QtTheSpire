#ifndef FEELNOPAIN_H
#define FEELNOPAIN_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class FeelNoPain : public AbstractCard
{
public:
    FeelNoPain();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // FEELNOPAIN_H
