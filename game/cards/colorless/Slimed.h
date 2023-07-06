
#ifndef SLIMED_H
#define SLIMED_H

#include "../AbstractCard.h"


class Slimed:public AbstractCard
{
public:
    Slimed();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // SLIMED_H
