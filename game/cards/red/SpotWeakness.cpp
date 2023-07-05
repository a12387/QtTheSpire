#include "SpotWeakness.h"

SpotWeakness::SpotWeakness() :
    AbstractCard(
        (std::string)"SpotWeakness",
        (std::string)"观察弱点",
        (std::string)":/game/resource/cards/spot_weakness.png",
        1,
        (std::string)"技能\n如果一名敌人的意图是攻击，你获得3点力量。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void SpotWeakness::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *SpotWeakness::makeCopy()
{
    return new SpotWeakness;
}
