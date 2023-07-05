#ifndef DEMONFORM_H
#define DEMONFORM_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class DemonForm : public AbstractCard
{
public:
    DemonForm();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // DEMONFORM_H
