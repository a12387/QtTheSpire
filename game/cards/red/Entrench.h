
#ifndef ENTRENCH_H
#define ENTRENCH_H


#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"

class Entrench:public AbstractCard
{
public:
    Entrench();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // ENTRENCH_H
