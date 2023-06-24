#ifndef DARK_EMBRACE_H
#define DARK_EMBRACE_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Dark_embrace : public AbstractCard
{
public:
    Dark_embrace();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};

#endif // DARK_EMBRACE_H
