
#ifndef SPIRESPEAR_H
#define SPIRESPEAR_H

#include "AbstractMonster.h"
#include "creaturewidget.h"
#include "../cards/DamageInfo.h"
#include "../powers/Artifact.h"
#include "../powers/BackAttack.h"
#include "../powers/Strength.h"
#include "../powers/Surrounded.h"


class SpireSpear:public AbstractMonster
{
public:
    SpireSpear();
    void createIntent();
    void attack(AbstractPlayer&);
};

#endif // SPIRESPEAR_H
