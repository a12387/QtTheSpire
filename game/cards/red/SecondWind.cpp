#include "SecondWind.h"

SecondWind::SecondWind() :
    AbstractCard(
        (std::string)"SecondWind",
        (std::string)"重振精神",
        (std::string)":/game/resource/cards/second_wind.png",
        1,
        (std::string)"技能\n消耗手牌中所有非攻击牌，每张获得5点格挡。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseBlock = 5;
}

void SecondWind::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    std::list<AbstractCard*> l;
    auto it = p->hand.group.begin();
    while(it != p->hand.group.end())
    {
        if((*it)->type != AbstractCard::ATTACK)
        {
            l.push_back((*it));
            p->addBlock(baseBlock);
        }
        it++;
    }
    for(auto &i:l)
    {
        i->exhaustCard();
    }
}
AbstractCard *SecondWind::makeCopy()
{
    return new SecondWind;
}
