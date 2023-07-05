#include "Inflame.h"
#include "game/powers/Strength.h"

Inflame::Inflame() :
    AbstractCard(
        (std::string)"Inflame",
        (std::string)"燃烧",
        (std::string)":/game/resource/cards/inflame.png",
        1,
        (std::string)"能力\n获得2点力量",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Inflame::use(AbstractPlayer *p,AbstractMonster *m)
{
    p->ApplyPower(new Strength(2));
}
AbstractCard *Inflame::makeCopy()
{
    return new Inflame;
}
