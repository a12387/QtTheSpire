#include "FeelNoPain.h"
#include "game/powers/FeelNoPain_.h"

FeelNoPain::FeelNoPain() :
    AbstractCard(
        (std::string)"FeelNoPain",
        (std::string)"无惧疼痛",
        (std::string)":/game/resource/cards/feel_no_pain.png",
        1,
        (std::string)"能力\n每当有一张牌被消耗时，获得4点格挡。",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseMagicNumber = 4;
}

void FeelNoPain::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    p->ApplyPower(new FeelNoPain_(baseMagicNumber));
}
AbstractCard *FeelNoPain::makeCopy()
{
    return new FeelNoPain;
}
