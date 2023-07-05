#ifndef SHRUGITOFF_H
#define SHRUGITOFF_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class ShrugItOff : public AbstractCard
{
public:
    ShrugItOff();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // SHRUGITOFF_H
