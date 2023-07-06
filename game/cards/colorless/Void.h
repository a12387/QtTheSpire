
#ifndef VOID_H
#define VOID_H
#include "../AbstractCard.h"



class Void:public AbstractCard
{
public:
    Void();
    AbstractCard *makeCopy();
};

#endif // VOID_H
