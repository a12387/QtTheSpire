
#include "PowerThrough.h"
#include "game/cards/colorless/Wound.h"

PowerThrough::PowerThrough():
    AbstractCard(
        (std::string)"PowerThrough",
        (std::string)"硬撑",
        (std::string)":/game/resource/cards/power_through.png",
        1,
        (std::string)"技能\n增加2张伤口到你的手牌。\n获得20点格挡。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseBlock=20;
}

void PowerThrough::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy-=cost;
    p->addBlock(baseBlock);
    for(int i=0;i<2;i++){
        if(p->hand.group.size()<10)p->hand.addToBottom(new Wound);
        else p->drawPile.addToTop(new Wound);
    }
}
AbstractCard*PowerThrough::makeCopy(){
    return new PowerThrough;
}
