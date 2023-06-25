#ifndef LIMIT_BREAK_RED_H
#define LIMIT_BREAK_RED_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Limit_break_Red : public AbstractCard
{
public:
    Limit_break_Red();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // LIMIT_BREAK_RED_H
