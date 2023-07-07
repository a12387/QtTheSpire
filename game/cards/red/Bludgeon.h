#ifndef BLUDGEON_H
#define BLUDGEON_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Bludgeon : public AbstractCard
{
public:
    Bludgeon();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // BLUDGEON_H
