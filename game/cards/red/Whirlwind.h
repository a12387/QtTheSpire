#ifndef WHIRLWIND_H
#define WHIRLWIND_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Whirlwind : public AbstractCard
{
public:
    Whirlwind();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // WHIRLWIND_H
