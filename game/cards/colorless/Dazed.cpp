
#include "Dazed.h"

Dazed::Dazed():
    AbstractCard(
        (std::string)"Dazed",
        (std::string)"晕眩",
        (std::string)":/game/resource/cards/dazed.png",
        999,
        (std::string)"状态\n不能被打出。\n虚无。",
        AbstractCard::STATUS,
        AbstractCard::COLORLESS,
        AbstractCard::COMMON,
        AbstractCard::NONE,
        DamageInfo::DamageType::NORMAL)
{
    ethereal = true;
}
AbstractCard* Dazed::makeCopy(){
    return new Dazed;
}
