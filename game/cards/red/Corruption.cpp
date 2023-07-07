#include "Corruption.h"
#include "game/powers/Corruption_.h"

Corruption::Corruption() :
    AbstractCard(
        (std::string)"Corruption",
        (std::string)"腐化",
        (std::string)":/game/resource/cards/corruption.png",
        2,
        (std::string)"能力\n所有技能牌耗能变为0。\n所有技能牌在被打出时被消耗。",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{

}

void Corruption::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->ApplyPower(new Corruption_());
    for(auto i:p->hand.group){
        if(i->type==SKILL){
            i->cost=0;
            i->exhaust=true;
        }
    }
    for(auto i:p->drawPile.group){
        if(i->type==SKILL){
            i->cost=0;
            i->exhaust=true;
        }
    }
    for(auto i:p->discardPile.group){
        if(i->type==SKILL){
            i->cost=0;
            i->exhaust=true;
        }
    }
    for(auto i:p->exhaustPile.group){
        if(i->type==SKILL){
            i->cost=0;
            i->exhaust=true;
        }
    }
}
AbstractCard *Corruption::makeCopy()
{
    return new Corruption;
}
