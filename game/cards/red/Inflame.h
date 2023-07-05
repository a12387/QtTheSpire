#ifndef INFLAME_H
#define INFLAME_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Inflame : public AbstractCard
{
public:
    Inflame();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // INFLAME_H
