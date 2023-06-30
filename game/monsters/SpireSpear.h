
#ifndef SPIRESPEAR_H
#define SPIRESPEAR_H

#include "AbstractMonster.h"
#include "../powers/Artifact.h"
#include "../powers/BackAttackRight.h"
#include "../powers/Strength.h"
#include "../powers/Surrounded.h"


class SpireSpear:public AbstractMonster
{
public:
    SpireSpear();
    void createIntent();
    void act(AbstractPlayer*);
};

#endif // SPIRESPEAR_H
