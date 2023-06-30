#include "AbstractCreature.h"
#include "../powers/AbstractPower.h"
AbstractCreature::AbstractCreature(std::string imgUrl,std::string name,std::string id,int health)
    :imgUrl(imgUrl),name(name),id(id),currentHealth(health),maxHealth(health),currentBlock(0)
{

}

void AbstractCreature::damage(DamageInfo& info)
{
    int damageAmount = info.outputValue;

    if (damageAmount <= 0)
        damageAmount = 0;

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
    loseBlock(currentBlock);
}

void AbstractCreature::addBlock(int amount)
{
    float tmp = amount;
    if(isPlayer)
    {
        /*
        遗物加格挡
        buff加格挡
        not released
        */
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
        for(auto i=buff.begin();i!=buff.end();++i){
            if((*i)->name=="Artifact"){
                (*i)->amount--;
                if((*i)->amount==0)buff.erase(i);
                break;
            }
        }
    }
    else{
        int tag=0;
        for(auto i=buff.begin();i!=buff.end();++i){
            if((*i)->name==power->name){
                (*i)->amount+=power->amount;
                if((*i)->amount>999)(*i)->amount=999;
                if((*i)->amount==0)buff.erase(i);
                tag++;break;
            }
        }
        if(!tag)buff.push_back(power);
    }
}

void AbstractCreature::changePower(){
    for(auto i=buff.begin();i!=buff.end();++i){
        if((*i)->name=="Frail"||(*i)->name=="Vulnerable"||(*i)->name=="Weak"){
            (*i)->amount--;
            if((*i)->amount==0)i=buff.erase(i);
        }
        else if((*i)->name=="INvincible")(*i)->amount=300;
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
