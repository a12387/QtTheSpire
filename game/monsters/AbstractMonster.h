#ifndef _ABSTRACTMONSTER_
#define _ABSTRACTMONSTER_
#include "../core/AbstractCreature.h"
#include "../cards/DamageInfo.h"
//#include "AbstractPower.h"
#include <vector>
class EnemyMoveInfo;
class AbstractMonster:public AbstractCreature
{
public:
    int nextMove,lastMove;
    std::string moveName;
    std::vector<DamageInfo*> damages;
    enum EnemyType
    {
        ELITE,
        BOSS
    };
    enum Intent
    {
        ATTACK,
        ATTACK_BUFF,
        ATTACK_DEBUFF,
        ATTACK_DEFEND,
        BUFF,
        DEBUFF,
        STRONG_DEBUFF,
        DEBUG,
        DEFEND,
        DEFEND_DEBUFF,
        DEFEND_BUFF,
        MAGIC,
        NONE,
        UNKNOWN
    };
    EnemyType type;
    Intent intent ,tipIntent;
    int intentBaseDmg,intentMultiAmt;
    bool isMultiDmg;
    EnemyMoveInfo *move;
    AbstractMonster(std::string ,std::string ,std::string ,int );
    void createIntent();
    void calculateDamage(int);
    void setMove(int ,Intent ,int ,int ,bool );
    void die(bool);
    void applyPowers();
};

#endif
