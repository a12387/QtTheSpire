#include "FeelNoPain.h"
#include "game/powers/FeelNoPain_.h"

FeelNoPain::FeelNoPain() :
    AbstractCard(
        (std::string)"FeelNoPain",
        (std::string)"无惧疼痛",
        (std::string)":/game/resource/cards/feel_no_pain.png",
        1,
        (std::string)"能力\n每当有一张牌被消耗时，获得3点格挡。",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void FeelNoPain::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->ApplyPower(new FeelNoPain_(3));
}
AbstractCard *FeelNoPain::makeCopy()
{
    return new FeelNoPain;
}
