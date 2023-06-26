
#include "CorruptHeart.h"

CorruptHeart::CorruptHeart():
    AbstractMonster(
        std::string(":/game/resource/creature/CorruptHeart.png"),
        std::string("Corrupt Heart"),
        std::string("CorruptHeart"),
        750)
{

}

void CorruptHeart::createIntent(){
    switch(round%3){
    case 1:case 2:intent=ATTACK;break;
    case 0:intent=round?BUFF:DEBUFF;break;
    }
}
void CorruptHeart::act(AbstractPlayer*p){
    if(intent==ATTACK){
        if(lastMove){
            if(lastMove==1){
                DamageInfo dmg(*this,2,DamageInfo::NORMAL);
                for(int i=0;i<12;i++)p->damage(dmg);
            }
            else{
                DamageInfo dmg(*this,40,DamageInfo::NORMAL);
                p->damage(dmg);
            }
            lastMove=0;
        }
        else if(rand()%2){
            lastMove=1;
            DamageInfo dmg(*this,40,DamageInfo::NORMAL);
            p->damage(dmg);
        }
        else{
            lastMove=2;
            DamageInfo dmg(*this,2,DamageInfo::NORMAL);
            for(int i=0;i<12;i++)p->damage(dmg);
        }
    }
    else{
        //2层易伤、虚弱、脆弱
        //抽牌堆加5张牌
    }
}
