#include "Whirlwind.h"

Whirlwind::Whirlwind() :
    AbstractCard(
        (std::string)"Whirlwind",
        (std::string)"旋风斩",
        (std::string)":/game/resource/cards/whirlwind.png",
        -1,
        (std::string)"攻击\n对所有敌人造成基础数值为5点的伤害X次",
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

void Whirlwind::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Whirlwind::makeCopy()
{
    return new Whirlwind;
}
