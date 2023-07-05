#include "Exhume.h"

Exhume::Exhume() :
    AbstractCard(
        (std::string)"Exhume",
        (std::string)"Exhume",
        (std::string)":/game/resource/cards/exhume.png",
        1,
        (std::string)"技能\n选择一张已消耗的牌，将其放入你的手牌。\n消耗。",
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

void Exhume::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Exhume::makeCopy()
{
    return new Exhume;
}
