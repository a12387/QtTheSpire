#include "LimitBreak.h"

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
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void LimitBreak::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *LimitBreak::makeCopy()
{
    return new LimitBreak;
}
