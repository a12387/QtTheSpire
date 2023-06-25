#ifndef FEEL_NO_PAIN_H
#define FEEL_NO_PAIN_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Feel_no_pain : public AbstractCard
{
public:
    Feel_no_pain();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};

#endif // FEEL_NO_PAIN_H
