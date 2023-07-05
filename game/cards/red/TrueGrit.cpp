#include "TrueGrit.h"

TrueGrit::TrueGrit() :
    AbstractCard(
        (std::string)"TrueGrit",
        (std::string)"坚毅",
        (std::string)":/game/resource/cards/true_grit.png",
        1,
        (std::string)"技能\n获得基础数值为7的格挡，随机消耗一张手牌",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::COMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void TrueGrit::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *TrueGrit::makeCopy()
{
    return new TrueGrit;
}
