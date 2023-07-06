
#include "Wound.h"

Wound::Wound():
    AbstractCard(
        (std::string)"Wound",
        (std::string)"伤口",
        (std::string)":/game/resource/cards/wound.png",
        999,
        (std::string)"状态\n不能被打出。",
        AbstractCard::STATUS,
        AbstractCard::COLORLESS,
        AbstractCard::COMMON,
        AbstractCard::NONE,
        DamageInfo::DamageType::NORMAL)
{

}

AbstractCard*Wound::makeCopy(){
    return new Wound;
}
