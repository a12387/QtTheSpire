
#ifndef BATTLE_TRANCE_H
#define BATTLE_TRANCE_H




#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Battle_trance : public AbstractCard
{
public:
    Battle_trance();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};

#endif // BATTLE_TRANCE_H
