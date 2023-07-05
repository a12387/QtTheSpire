#include "FeelNoPain.h"

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
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *FeelNoPain::makeCopy()
{
    return new FeelNoPain;
}
