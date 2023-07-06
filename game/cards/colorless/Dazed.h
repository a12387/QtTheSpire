
#ifndef DAZED_H
#define DAZED_H


#include "../AbstractCard.h"

class Dazed:public AbstractCard
{
public:
    Dazed();
    AbstractCard *makeCopy();
};

#endif // DAZED_H
