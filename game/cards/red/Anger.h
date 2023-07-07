#ifndef ANGER_H
#define ANGER_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Anger : public AbstractCard
{
public:
    Anger();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // ANGER_H
