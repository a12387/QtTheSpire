#ifndef _MONSTERGROUP_H_
#define _MONSTERGROUP_H_

#include <list>
#include "AbstractMonster.h"

class MonsterGroup
{
public:
    std::list<AbstractMonster *> monsters;

    ~MonsterGroup();

    void addMonster(AbstractMonster* m);

    void showIntent();

    void init();

    void preBattleAction();

    void preTurnAction();
};

#endif
