#ifndef BASH_H
#define BASH_H
#include "../AbstractCard.h"
#include "../../characters/AbstractPlayer.h"
#include "../../monsters/AbstractMonster.h"
class Bash : public AbstractCard
{
public:
    Bash();
    void use(AbstractPlayer &p,AbstractMonster &m);
    AbstractCard *makeCopy();
};
#endif // BASH_H
