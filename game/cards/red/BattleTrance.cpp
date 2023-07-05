#include "BattleTrance.h"

BattleTrance::BattleTrance() :
    AbstractCard(
        (std::string)"BattleTrance",
        (std::string)"战斗专注",
        (std::string)":/game/resource/cards/battle_trance.png",
        0,
        (std::string)"技能\n抽3张牌。\n你在这个回合内不能再抽任何牌。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void BattleTrance::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *BattleTrance::makeCopy()
{
    return new BattleTrance;
}
