#ifndef BLOODLETTING_H
#define BLOODLETTING_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"

class Bloodletting : public AbstractCard
{
public:
    Bloodletting();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // BLOODLETTING_H
