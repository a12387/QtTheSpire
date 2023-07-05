#ifndef SPOTWEAKNESS_H
#define SPOTWEAKNESS_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class SpotWeakness : public AbstractCard
{
public:
    SpotWeakness();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // SPOTWEAKNESS_H
