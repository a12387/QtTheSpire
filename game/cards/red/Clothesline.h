#ifndef CLOTHESLINE_H
#define CLOTHESLINE_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Clothesline : public AbstractCard
{
public:
    Clothesline();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // CLOTHESLINE_H
