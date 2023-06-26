#include "DamageInfo.h"

DamageInfo::DamageInfo(AbstractCreature &damageSource, int baseValue_, DamageType type_)
    : type(type_), baseValue(baseValue_), owner(damageSource)
{
    //Apply some buff
    //And calculate outputValue
    this->outputValue = this->baseValue;
}
