#include "DamageInfo.h"
#include "../core/AbstractCreature.h"
#include "../powers/AbstractPower.h"

DamageInfo::DamageInfo(AbstractCreature*damageSource, int baseValue_, DamageType type_)
    : type(type_), baseValue(baseValue_), owner(damageSource)
{
    outputValue=baseValue;
    for(auto i=owner->buff.begin();i!=owner->buff.end();++i){
        if((*i)->name=="Strength")outputValue+=(*i)->amount;
    }
    for(auto i=owner->buff.begin();i!=owner->buff.end();++i){
        if((*i)->name=="BackAttackLeft"||(*i)->name=="BackAttackRight")outputValue*=1.5;
        if((*i)->name=="Weak")outputValue*=0.75;
    }
}
