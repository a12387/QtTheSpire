#ifndef TRUE_GRIT_RED_H
#define TRUE_GRIT_RED_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class True_grit_Red : public AbstractCard
{
public:
    True_grit_Red();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};

#endif // TRUE_GRIT_RED_H
