#ifndef SHRUG_IT_OFF_RED_H
#define SHRUG_IT_OFF_RED_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Shrug_it_off_Red : public AbstractCard
{
public:
    Shrug_it_off_Red();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};

#endif // SHRUG_IT_OFF_RED_H
