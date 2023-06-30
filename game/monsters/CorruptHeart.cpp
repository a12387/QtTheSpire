
#include "CorruptHeart.h"

CorruptHeart::CorruptHeart():
    AbstractMonster(
        std::string(":/game/resource/creature/CorruptHeart.png"),
        std::string("Corrupt Heart"),
        std::string("CorruptHeart"),
        750)
{
    ApplyPower(new BeatOfDeath(1));
    ApplyPower(new Invincible());
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
                DamageInfo dmg(this,2,DamageInfo::NORMAL);
                for(int i=0;i<12;i++)p->damage(dmg);
            }
            else{
                DamageInfo dmg(this,40,DamageInfo::NORMAL);
                p->damage(dmg);
            }
            lastMove=0;
        }
        else if(rand()%2){
            lastMove=1;
            DamageInfo dmg(this,40,DamageInfo::NORMAL);
            p->damage(dmg);
        }
        else{
            lastMove=2;
            DamageInfo dmg(this,2,DamageInfo::NORMAL);
            for(int i=0;i<12;i++)p->damage(dmg);
        }
    }
    else{
        if(round==0){
            p->ApplyPower(new Frail(2));
            p->ApplyPower(new Weak(2));
            p->ApplyPower(new Vulnerable(2));
        //抽牌堆加5张牌
        }
        else{
            for(auto i=buff.begin();i!=buff.end();++i){
                if((*i)->name=="Strength")
                    if((*i)->amount<0)buff.erase(i);
            }
            ApplyPower(new Strength(2));
            switch(round/3){
            case 1:ApplyPower(new Artifact(2));break;
            case 2:ApplyPower(new BeatOfDeath(1));break;
            case 3:ApplyPower(new PainfulStabs);break;
            case 4:ApplyPower(new Strength(10));break;
            default:ApplyPower(new Strength(50));break;
            }
        }
    }
    round++;
}
