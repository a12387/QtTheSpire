#ifndef ENEMYMOVEINFO_H
#define ENEMYMOVEINFO_H

#include "AbstractMonster.h"

class EnemyMoveInfo {
public:
    int nextMove;
    AbstractMonster::Intent intent;
    int baseDamage;
    int multiplier;
    bool isMultiDamage;

    EnemyMoveInfo(int , AbstractMonster::Intent , int , int , bool ) ;
};

#endif // ENEMYMOVEINFO_H
