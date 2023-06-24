#include "AbstractMonster.h"
#include "EnemyMoveInfo.h"

AbstractMonster::AbstractMonster(std::string imgUrl, std::string name_,std::string id_,int health)
    :AbstractCreature(imgUrl,name_,id_,health)
{
        isPlayer=false;
        nextMove=-1;
        moveName="";
        intent=DEBUG;
        tipIntent=DEBUG;
}

void AbstractMonster::createIntent()
{
    intent=move->intent;
    nextMove=move->nextMove;
    intentBaseDmg=move->baseDamage;
    if(move->baseDamage>-1){
        calculateDamage(intentBaseDmg);
        if(move->isMultiDamage){
            intentMultiAmt=move->multiplier;
            isMultiDmg=true;
        }
        else{
            intentMultiAmt=-1;
            isMultiDmg=false;
        }
    }
    tipIntent=intent;
}
void AbstractMonster::calculateDamage(int dmg)
{

}
void AbstractMonster::setMove(int ,AbstractMonster::Intent ,int ,int ,bool )
{

}
void AbstractMonster::die(bool triggerRelics)
{

}
//void applyPowers()
//{

//}
