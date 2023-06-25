#include "AbstractMonster.h"

AbstractMonster::AbstractMonster(std::string imgUrl, std::string name_,std::string id_,int health)
    :AbstractCreature(imgUrl,name_,id_,health)
{
        isPlayer=false;
        round=0;
        lastMove=-1;
        moveName="";
        intent=DEBUG;
}
void AbstractMonster::die(bool triggerRelics)
{

}
//void applyPowers()
//{

//}
