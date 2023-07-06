
#include "Slimed.h"
#include "../../characters/AbstractPlayer.h"

Slimed::Slimed():
    AbstractCard(
        (std::string)"Slimed",
        (std::string)"黏液",
        (std::string)":/game/resource/cards/slimed.png",
        1,
        (std::string)"状态\n消耗。",
        AbstractCard::STATUS,
        AbstractCard::COLORLESS,
        AbstractCard::COMMON,
        AbstractCard::NONE,
        DamageInfo::DamageType::NORMAL)
{
    exhaust=true;
}
AbstractCard*Slimed::makeCopy(){
    return new Slimed;
}
void Slimed::use(AbstractPlayer *p,AbstractMonster *m){
    p->energy-=cost;
  }
