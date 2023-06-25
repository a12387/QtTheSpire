#ifndef DEMON_FORM_H
#define DEMON_FORM_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Demon_form : public AbstractCard
{
public:
    Demon_form();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};

#endif // DEMON_FORM_H
