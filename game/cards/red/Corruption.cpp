#include "Corruption.h"
#include "game/powers/Corruption_.h"

Corruption::Corruption() :
    AbstractCard(
        (std::string)"Corruption",
        (std::string)"腐化",
        (std::string)":/game/resource/cards/corruption.png",
        3,
        (std::string)"能力\n所有技能牌耗能变为0。\n所有技能牌在被打出时被消耗。",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::RARE,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Corruption::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->ApplyPower(new Corruption_());
}
AbstractCard *Corruption::makeCopy()
{
    return new Corruption;
}
