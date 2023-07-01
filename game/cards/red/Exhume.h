#ifndef EXHUME_H
#define EXHUME_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Exhume : public AbstractCard
{
public:
    Exhume();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};
#endif // EXHUME_H
