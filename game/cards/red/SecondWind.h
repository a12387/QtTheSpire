#ifndef SECONDWIND_H
#define SECONDWIND_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class SecondWind : public AbstractCard
{
public:
    SecondWind();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // SECONDWIND_H
