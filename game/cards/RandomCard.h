
#ifndef RANDOMCARD_H
#define RANDOMCARD_H

#include "AbstractCard.h"
#include <vector>

class RandomCard
{
public:
    RandomCard();

    static std::vector<AbstractCard*> attack;
    static std::vector<AbstractCard*> skill;
    static std::vector<AbstractCard*> power;
    static std::vector<AbstractCard*> pool;

    static AbstractCard *getAttackCard();
    static AbstractCard *getSkillCard();
    static AbstractCard *getPowerCard();
    static AbstractCard *getAnyCard();
};

#endif // RANDOMCARD_H
