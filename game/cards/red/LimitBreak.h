#ifndef LIMITBREAK_H
#define LIMITBREAK_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class LimitBreak : public AbstractCard
{
public:
    LimitBreak();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // LIMITBREAK_H
