#include "SpotWeakness.h"
#include "../../powers/Strength.h"
SpotWeakness::SpotWeakness() :
    AbstractCard(
        (std::string)"SpotWeakness",
        (std::string)"观察弱点",
        (std::string)":/game/resource/cards/spot_weakness.png",
        1,
        (std::string)"技能\n如果一名敌人的意图是攻击，你获得4点力量。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseMagicNumber = 4;
}

void SpotWeakness::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->energy -= cost;
    if( m->intent == AbstractMonster::ATTACK_DEBUFF||
        m->intent == AbstractMonster::ATTACK||
        m->intent == AbstractMonster::ATTACK_DEFEND||
        m->intent == AbstractMonster::ATTACK_BUFF)
    {
        p->ApplyPower(new Strength(baseMagicNumber));
    }
}
AbstractCard *SpotWeakness::makeCopy()
{
    return new SpotWeakness;
}
