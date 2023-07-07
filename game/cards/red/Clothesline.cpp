#include "Clothesline.h"
#include "../../powers/Weak.h"
Clothesline::Clothesline() :
    AbstractCard(
        (std::string)"Clothesline",
        (std::string)"金刚臂",
        (std::string)":/game/resource/cards/clothesline.png",
        2,
        (std::string)"攻击\n造成基础数值为14点的伤害\n给予3层虚弱",
        AbstractCard::ATTACK,
        AbstractCard::RED,
        AbstractCard::COMMON,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 14;
    baseMagicNumber = 3;
}

void Clothesline::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    DamageInfo tmp = DamageInfo(p,this->baseDamage,this->dType);
    m->damage(tmp);
    m->ApplyPower(new Weak(baseMagicNumber));
}
AbstractCard *Clothesline::makeCopy()
{
    return new Clothesline;
}
