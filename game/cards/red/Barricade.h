#ifndef BARRICADE_H
#define BARRICADE_H
#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Barricade: public AbstractCard
{
public:
    Barricade();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};
#endif // BARRICADE_H
