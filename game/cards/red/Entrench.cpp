
#include "Entrench.h"
#include "QSoundEffect"
Entrench::Entrench():
    AbstractCard(
        (std::string)"Entrench",
        (std::string)"巩固",
        (std::string)":/game/resource/cards/entrench.png",
        1,
        (std::string)"技能\n将你当前的格挡翻倍。",
        AbstractCard::SKILL,
        AbstractCard::RED,
        AbstractCard::UNCOMMON,
        AbstractCard::SELF,
        DamageInfo::DamageType::NORMAL)
{

}
void Entrench::use(AbstractPlayer *p,AbstractMonster *m){

    QSoundEffect*e=new QSoundEffect();
    e->setSource(QUrl("qrc:/game/resource/audio/sound/GainDefense.wav"));
    e->play();
    p->energy-=cost;
    p->currentBlock*=2;
}
AbstractCard* Entrench::makeCopy(){
    return new Entrench;
}
