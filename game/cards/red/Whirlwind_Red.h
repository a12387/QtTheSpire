#ifndef WHIRLWIND_RED_H
#define WHIRLWIND_RED_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Whirlwind_Red : public AbstractCard
{
public:
    Whirlwind_Red();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // WHIRLWIND_RED_H
