#include "SpireShield.h"

SpireShield::SpireShield():
    AbstractMonster(
        std::string(":/game/resource/creature/shield.png"),
        std::string("Spire Shield"),
        std::string("SpireShield"),
        110)
{

}
void SpireShield::createIntent(){
    switch(round%3){
    case 0:intent=rand()%2?DEFEND :ATTACK;break;
    case 1:intent=lastMove?DEFEND :ATTACK;break;
    case 2:intent=ATTACK;break;
    }
}
void SpireShield::attack(AbstractPlayer&p){
    if(intent==DEFEND){

    }
}
