#ifndef ARMAMENTS_RED_H
#define ARMAMENTS_RED_H
#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Armaments_Red : public AbstractCard
{
public:
    Armaments_Red();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};
#endif // ARMAMENTS_RED_H
