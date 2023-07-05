#include "PommelStrike.h"

PommelStrike::PommelStrike() :
    AbstractCard(
        (std::string)"PommelStrike",
        (std::string)"剑柄打击",
        (std::string)":/game/resource/cards/pommel_strike.png",
        1,
        (std::string)"攻击\n造成基础数值为9点的伤害\n抽1张牌",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::COMMON,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 9;
    baseMagicNumber = 1;
}

void PommelStrike::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    DamageInfo tmp = DamageInfo(p,this->baseDamage,this->dType);
    m->damage(tmp);
    p->drawCard(baseMagicNumber);
}
AbstractCard *PommelStrike::makeCopy()
{
    return new PommelStrike;
}
