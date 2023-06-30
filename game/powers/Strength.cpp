
#include "Strength.h"

Strength::Strength(int a):AbstractPower(a,"Strength")
{
    if(amount>0)type=BUFF;
    else type=DEBUFF;
    imgPath=":/game/resource/powers/Strength.png";
}
