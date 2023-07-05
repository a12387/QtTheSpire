#include "LimitBreak.h"
#include "../../powers/Strength.h"
LimitBreak::LimitBreak() :
    AbstractCard(
        (std::string)"LimitBreak",
        (std::string)"突破极限",
        (std::string)":/game/resource/cards/limit_break.png",
        1,
        (std::string)"技能\n将你的力量翻倍。\n消耗。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    exhaust = true;
}

void LimitBreak::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    auto it = p->buff.begin();
    while(it != p->buff.end())
    {
        if((*it)->name == "Strength")
            p->ApplyPower(new Strength((*it)->amount));
        it++;
    }
}
AbstractCard *LimitBreak::makeCopy()
{
    return new LimitBreak;
}
