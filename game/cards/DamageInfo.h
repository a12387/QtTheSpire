#ifndef _DAMAGEINFO_H_
#define _DAMAGEINFO_H_

#include <iostream>

class AbstractCreature;

class DamageInfo 
{
public:
    enum DamageType
    {
        NORMAL,
        THORNS,
        HP_LOSS
    };

    DamageType type;
    int baseValue;
    int outputValue;
    AbstractCreature *owner;

    DamageInfo(AbstractCreature *damageSource, int baseValue, DamageType type);
};

#endif
