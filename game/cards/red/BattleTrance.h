
#ifndef BATTLETRANCE_H
#define BATTLETRANCE_H




#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class BattleTrance : public AbstractCard
{
public:
    BattleTrance();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // BATTLETRANCE_H
