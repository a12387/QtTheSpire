#ifndef _STRIKE_RED_H_
#define _STRIKE_RED_H_

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Strike_Red : public AbstractCard
{
public:
    Strike_Red();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};

#endif
