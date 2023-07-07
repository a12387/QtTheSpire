#include "Anger.h"

Anger::Anger() :
    AbstractCard(
        (std::string)"Anger",
        (std::string)"愤怒",
        (std::string)":/game/resource/cards/anger.png",
        0,
        (std::string)"攻击\n造成基础数值为8点的伤害\n在弃牌堆放入一张此牌的复制品",
        AbstractCard::ATTACK,
        AbstractCard::RED,
        AbstractCard::COMMON,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 8;
}

void Anger::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    DamageInfo tmp = DamageInfo(p,this->baseDamage,this->dType);
    m->damage(tmp);

    p->discardPile.addToTop(makeCopy());
}
AbstractCard *Anger::makeCopy()
{
    return new Anger;
}
