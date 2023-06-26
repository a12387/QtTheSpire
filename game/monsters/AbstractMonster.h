#ifndef _ABSTRACTMONSTER_
#define _ABSTRACTMONSTER_
#include "../core/AbstractCreature.h"
#include "../characters/AbstractPlayer.h"
#include "../cards/DamageInfo.h"
//#include "AbstractPower.h"
#include <vector>
class AbstractMonster:public AbstractCreature
{
public:
    int round,lastMove;
    std::string moveName;
    std::vector<DamageInfo*> damages;

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
    Intent intent;
    int intentBaseDmg,intentMultiAmt;
    bool isMultiDmg;
    AbstractMonster(std::string ,std::string ,std::string ,int );
    virtual void createIntent()=0;
    void calculateDamage(int);
    virtual void act(AbstractPlayer*)=0;
    void die(bool);
    void applyPowers();
};

#endif
