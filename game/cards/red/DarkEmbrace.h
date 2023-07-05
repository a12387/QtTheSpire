#ifndef DARKEMBRACE_H
#define DARKEMBRACE_H

#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class DarkEmbrace : public AbstractCard
{
public:
    DarkEmbrace();
    void use(AbstractPlayer *p,AbstractMonster *m);
    AbstractCard *makeCopy();
};

#endif // DARKEMBRACE_H
