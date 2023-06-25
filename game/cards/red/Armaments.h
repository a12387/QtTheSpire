#ifndef ARMAMENTS_H
#define ARMAMENTS_H
#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Armaments : public AbstractCard
{
public:
    Armaments();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};
#endif // ARMAMENTS_H
