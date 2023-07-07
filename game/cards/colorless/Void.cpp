
#include "Void.h"

Void::Void():
    AbstractCard(
        (std::string)"Void",
        (std::string)"虚空",
        (std::string)":/game/resource/cards/void.png",
        999,
        (std::string)"状态\n不能被打出。\n抽到这张牌时失去一点能量。\n虚无。",
        AbstractCard::STATUS,
        AbstractCard::COLORLESS,
        AbstractCard::COMMON,
        AbstractCard::NONE,
        DamageInfo::DamageType::NORMAL)

{
    ethereal = true;
}
AbstractCard*Void::makeCopy(){
    return new Void;
}
