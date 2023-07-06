
#ifndef WOUND_H
#define WOUND_H
#include "../AbstractCard.h"



class Wound:public AbstractCard
{
public:
    Wound();
    AbstractCard *makeCopy();
};

#endif // WOUND_H
