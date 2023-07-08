
#ifndef POWERTHROUGH_H
#define POWERTHROUGH_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"


class PowerThrough:public AbstractCard
{
public:
    PowerThrough();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // POWERTHROUGH_H
