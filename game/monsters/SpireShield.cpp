#include "SpireShield.h"
#include "mainwindow.h"

SpireShield::SpireShield():
    AbstractMonster(
        std::string(":/game/resource/creature/shield.png"),
        std::string("Spire Shield"),
        std::string("SpireShield"),
        110)


{
    ApplyPower(new BackAttackLeft());
    ApplyPower(new Artifact(1));
}
void SpireShield::createIntent(){
    switch(round%3){
    case 0:intent=rand()%2?DEFEND :ATTACK_DEBUFF;break;
    case 1:intent=lastMove?DEFEND :ATTACK_DEBUFF;break;
    case 2:intent=ATTACK_DEFEND;break;
    }
}
void SpireShield::act(AbstractPlayer*p){
    if(intent==DEFEND){
        lastMove=0;
        for(auto &i:mw->d.rooms[mw->d.floor - 1]->monsters.monsters)i->addBlock(30);
    }
    else if(intent==ATTACK_DEBUFF){
        lastMove=1;
        DamageInfo dmg(this,12,DamageInfo::NORMAL);
        p->damage(dmg);
        p->ApplyPower(new Strength(-1));
    }
    else{
        int block_=p->currentHealth;
        DamageInfo dmg(this,34,DamageInfo::NORMAL);
        p->damage(dmg);
        block_-=p->currentHealth;
        addBlock(block_);
    }
    round++;
}
