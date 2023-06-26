#ifndef INFLAME_RED_H
#define INFLAME_RED_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Inflame_Red : public AbstractCard
{
public:
    Inflame_Red();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // INFLAME_RED_H
