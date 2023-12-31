#include "AbstractCreature.h"
#include "../characters/AbstractPlayer.h"
#include "../powers/AbstractPower.h"
#include "../powers/Strength.h"
#include "../cards/colorless/Wound.h"
#include <QSoundEffect>

AbstractCreature::AbstractCreature(std::string imgUrl,std::string name,std::string id,int health)
    :imgUrl(imgUrl),name(name),id(id),currentHealth(health),maxHealth(health),currentBlock(0)
{

}

void AbstractCreature::damage(DamageInfo& info)
{
    if(!isPlayer) {
        QSoundEffect*e=new QSoundEffect();
        e->setSource(QUrl("qrc:/game/resource/audio/sound/IronClad_Atk.wav"));
        e->play();
    }


    int damageAmount = info.outputValue;

    if (damageAmount <= 0)
        damageAmount = 0;

    if(info.type != DamageInfo::HP_LOSS)
        damageAmount = decrementBlock(info, damageAmount);

    damageAmount = damageAmount < currentHealth ? damageAmount : currentHealth;

    if(name=="Corrupt Heart"){
        auto i=buff.begin();
        ++i;
        damageAmount=damageAmount<(*i)->amount?damageAmount:(*i)->amount;
        currentHealth-=damageAmount;
        (*i)->amount-=damageAmount;
    }

    else currentHealth -= damageAmount;

    //healthbarupdate;

    if(currentHealth <= 0)
    {
        isDead = true;

        if(currentBlock > 0)
            loseBlock(currentBlock);
    }
}
void AbstractCreature::damage(int dmg){
    if(currentBlock>0){
        if(dmg>currentBlock){
            dmg-=currentBlock;
            loseBlock();
        }
        else {
            loseBlock(dmg);
            dmg=0;
        }
    }
    currentHealth-=dmg;
}
int AbstractCreature::decrementBlock(DamageInfo &damageInfo, int damageAmount)
{
    for(auto i=buff.begin();i!=buff.end();++i){
        if((*i)->name=="Vulnerable"){
            damageAmount*=1.5;break;
        }
    }
    if(damageInfo.type != DamageInfo::HP_LOSS && currentBlock > 0)
    {
        if(damageAmount >= currentBlock)
        {
            damageAmount -= currentBlock;
            if(damageAmount < 0)
                damageAmount = 0;

            loseBlock(currentBlock); // 失去格挡
            //brokeBlock() : 破盾时执行的遗物效果 - not released
        } 
        else
        {
            loseBlock(damageAmount);
            damageAmount = 0;
        }
    }
    return damageAmount;
}

void AbstractCreature::loseBlock(int amount)
{
    currentBlock -= amount;

    if(currentBlock < 0)
        currentBlock = 0;
}
void AbstractCreature::loseBlock()
{
    for(auto i=buff.begin();i!=buff.end();++i){
        if((*i)->name=="Barricade")return;
    }
    loseBlock(currentBlock);
}

void AbstractCreature::addBlock(int amount)
{
    QSoundEffect*e=new QSoundEffect();
    e->setSource(QUrl("qrc:/game/resource/audio/sound/GainDefense.wav"));
    e->play();
    float tmp = amount;
    if(isPlayer)
    {
        for(auto i=buff.begin();i!=buff.end();++i){
            if((*i)->name=="Frail")tmp*=0.75;
        }
    }
    currentBlock += int(tmp);
    if(currentBlock > 999)
        currentBlock = 999;
}

void AbstractCreature::ApplyPower(AbstractPower *power)
{
    if(power->type==AbstractPower::DEBUFF){
        QSoundEffect*e=new QSoundEffect();
        e->setSource(QUrl("qrc:/game/resource/audio/sound/Debuff.wav"));
        e->play();
        bool offset=false;
        for(auto i=buff.begin();i!=buff.end();++i){
            if((*i)->name=="Artifact"){
                offset=true;
                (*i)->amount--;
                break;
            }
        }
        if(!offset){
            int tag=0;
            for(auto i=buff.begin();i!=buff.end();++i){
                if((*i)->name==power->name){
                    (*i)->amount+=power->amount;
                    if((*i)->amount>999)(*i)->amount=999;
                    tag++;break;
                }
            }
            if(!tag)buff.push_back(power);
        }
    }
    else{
        int tag=0;
        if(isPlayer){
            QSoundEffect*e=new QSoundEffect();
            e->setSource(QUrl("qrc:/game/resource/audio/sound/Buff.wav"));
            e->play();
        }
        for(auto i=buff.begin();i!=buff.end();++i){
            if((*i)->name==power->name){
                (*i)->amount+=power->amount;
                if((*i)->amount>999)(*i)->amount=999;
                tag++;break;
            }
        }
        if(!tag)buff.push_back(power);
    }
    for(auto i=buff.begin();i!=buff.end();){
        if((*i)->amount==0&&(*i)->name!="Invincible")i=buff.erase(i);
        else ++i;
    }
}

void AbstractCreature::changePower(){
    for(auto i=buff.begin();i!=buff.end();++i){
        if((*i)->name=="DemonForm")ApplyPower(new Strength((*i)->amount));
        else if((*i)->name=="NoDraw")(*i)->amount=0;
        //else if((*i)->name=="Frail"||(*i)->name=="Vulnerable"||(*i)->name=="Weak")(*i)->amount--;
        else if((*i)->name=="Invincible")(*i)->amount=300;
    }
    for(auto i=buff.begin();i!=buff.end();){
        if((*i)->amount==0)i=buff.erase(i);
        else ++i;
    }
}
void AbstractCreature::changeDebuff(){
    for(auto i=buff.begin();i!=buff.end();++i){
        if((*i)->name=="Frail"||(*i)->name=="Vulnerable"||(*i)->name=="Weak")(*i)->amount--;
    }
    for(auto i=buff.begin();i!=buff.end();){
        if((*i)->amount==0)i=buff.erase(i);
        else ++i;
    }
}
void AbstractCreature::loseGold(int amount)
{
    gold -= amount;
    if(gold < 0)
        gold = 0;
}

void AbstractCreature::gainGold(int amount)
{
    gold += amount;
}

void AbstractCreature::heal(int amount)
{
    if(isDying){
        return ;
    }
    /*iterator<AbstractPower> it = powers.iterator();
    while (it.hasNext()) {
        AbstractPower p = it.next();
        healAmount = p.onHeal(healAmount);
    }*/
    currentHealth+=amount;
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
}
