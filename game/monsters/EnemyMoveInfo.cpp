#include "EnemyMoveInfo.h"

EnemyMoveInfo::EnemyMoveInfo(int nextMove_, AbstractMonster::Intent intent_, int intentBaseDmg, int multiplier_, bool isMultiDamage_)
{
    nextMove = nextMove_;
    intent = intent_;
    baseDamage = intentBaseDmg;
    multiplier = multiplier_;
    isMultiDamage = isMultiDamage_;
}
