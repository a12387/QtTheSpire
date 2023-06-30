#include "mainwindow.h"
#include "SpireSpear.h"

SpireSpear::SpireSpear():
    AbstractMonster(
        std::string(":/game/resource/creature/spear.png"),
        std::string("Spire Spear"),
        std::string("SpireSpear"),
        160)
{
    ApplyPower(new Artifact(1));
}
void SpireSpear::createIntent(){
    switch(round%3){
    case 1:intent=ATTACK;break;
    case 2:if(rand()%2)intent=BUFF;
        else intent=ATTACK_DEBUFF;break;
    case 0:if(lastMove==-1||lastMove==1)intent=ATTACK_DEBUFF;
        else if(lastMove==0)intent=BUFF;break;
    }
}
void SpireSpear::act(AbstractPlayer*p){
    if(intent== ATTACK)
    {
        DamageInfo dmg=DamageInfo(this,10,DamageInfo::NORMAL);
        for(int i=0;i<3;i++)p->damage(dmg);
    }
    else if(intent==BUFF){
        lastMove=1;
        for(auto &i:mw->d.rooms[mw->d.floor]->monsters.monsters)i->ApplyPower(new Strength(2));
    }
    else if(intent==ATTACK_DEBUFF){
        lastMove=0;
        DamageInfo dmg(this,5,DamageInfo::NORMAL);
        for(int i=0;i<2;i++)p->damage(dmg);
        //将2张灼伤洗入弃牌堆
    }
    round++;
}

