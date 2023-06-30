#ifndef SPIRESHIELD_H
#define SPIRESHIELD_H

#include "AbstractMonster.h"
#include "../cards/DamageInfo.h"
#include "../powers/Artifact.h"
#include "../powers/BackAttackLeft.h"
#include "../powers/Strength.h"
#include "../powers/Surrounded.h"

class SpireShield : public AbstractMonster
{
public:
    SpireShield();
    void createIntent();
    void act(AbstractPlayer*);
};

#endif // SPIRESHIELD_H
