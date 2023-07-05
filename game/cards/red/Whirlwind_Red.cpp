#include "Whirlwind_Red.h"

Whirlwind_Red::Whirlwind_Red() :
    AbstractCard(
        (std::string)"Whirlwind_R",
        (std::string)"Whirlwind",
        (std::string)":/game/resource/cards/whirlwind.png",
        1,
        (std::string)"攻击\n造成6点伤害",
        AbstractCard::ATTACK,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Whirlwind_Red::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Whirlwind_Red::makeCopy()
{
    return new Whirlwind_Red;
}
