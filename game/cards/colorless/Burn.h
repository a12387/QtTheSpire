
#ifndef BURN_H
#define BURN_H

#include "../AbstractCard.h"


class Burn:public AbstractCard
{
public:
    Burn();
    AbstractCard *makeCopy();
};

#endif // BURN_H
