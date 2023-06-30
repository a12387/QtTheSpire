#include "Demon_form.h"

Demon_form::Demon_form() :
    AbstractCard(
        (std::string)"Demon_form_R",
        (std::string)"Demon_form",
        (std::string)":/game/resource/cards/demon_form.png",
        1,
        (std::string)"攻击\n造成6点伤害",
        AbstractCard::POWER,
        AbstractCard::RED,
        AbstractCard::BASIC,
        AbstractCard::ENEMY,
        DamageInfo::DamageType::NORMAL)
{
    baseDamage = 6;
    tags.push_back(CardTags::STARTER_STRIKE);
    tags.push_back(CardTags::STRIKE);
}

void Demon_form::use(AbstractPlayer *p,AbstractMonster *m)
{
    DamageInfo tmp = DamageInfo(p,this->damage,this->dType);
    m->damage(tmp);
}
AbstractCard *Demon_form::makeCopy()
{
    return new Demon_form;
}
