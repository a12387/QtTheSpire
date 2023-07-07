#ifndef DEFEND_RED_H
#define DEFEND_RED_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"

class Defend_Red : public AbstractCard
{
public:
    Defend_Red();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // DEFEND_RED_H
