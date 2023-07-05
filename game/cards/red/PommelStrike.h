#ifndef POMMELSTRIKE_H
#define POMMELSTRIKE_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class PommelStrike : public AbstractCard
{
public:
    PommelStrike();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // POMMELSTRIKE_H
