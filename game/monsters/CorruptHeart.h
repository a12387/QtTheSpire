
#ifndef CORRUPTHEART_H
#define CORRUPTHEART_H

#include "AbstractMonster.h"
#include "../powers/Artifact.h"
#include "../powers/BeatOfDeath.h"
#include "../powers/Frail.h"
#include "../powers/Invincible.h"
#include "../powers/PainfulStabs.h"
#include "../powers/Strength.h"
#include "../powers/Vulnerable.h"
#include "../powers/Weak.h"


class CorruptHeart:public AbstractMonster
{
public:
    CorruptHeart();
    void createIntent();
    void act(AbstractPlayer*);
};

#endif // CORRUPTHEART_H
