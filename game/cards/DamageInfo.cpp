#include "DamageInfo.h"

DamageInfo::DamageInfo(AbstractCreature &damageSource, int baseValue, DamageType type)
    : owner(damageSource), baseValue(baseValue), type(type)
{
    //Apply some buff
    //And calculate outputValue
    outputValue = baseValue;
}
