
#include "Burn.h"

Burn::Burn():
    AbstractCard(
        (std::string)"Burn",
        (std::string)"灼伤",
        (std::string)":/game/resource/cards/burn.png",
        999,
        (std::string)"状态\n不能被打出。\n在你的回合结束时，你受到2点伤害。",
        AbstractCard::STATUS,
        AbstractCard::COLORLESS,
        AbstractCard::COMMON,
        AbstractCard::NONE,
        DamageInfo::DamageType::NORMAL)
{

}

AbstractCard*Burn::makeCopy(){
    return new Burn;
}
