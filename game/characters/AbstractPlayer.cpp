#include "AbstractPlayer.h"
#include "mainwindow.h"
#include "../powers/Surrounded.h"
#include "../cards/colorless/Wound.h"

AbstractPlayer::AbstractPlayer(std::string imgUrl,std::string name, std::string id, int health)
    :AbstractCreature(imgUrl,name,id, health)
{
    //potions.clear();
}

void AbstractPlayer::preBattle()
{
    this->drawPile.clear();
    this->hand.clear();
    this->discardPile.clear();
    this->exhaustPile.clear();
    this->buff.clear();
    direction=1;

    for(auto &i : masterDeck.group)
    {
        drawPile.addToBottom(i->makeCopy());
    }
    drawPile.shuffle(drawPile.group.size());
    if(mw->d.floor==2)ApplyPower(new Surrounded);
    //relic;
}

void AbstractPlayer::drawCard(int num)
{
    for(auto i=buff.begin();i!=buff.end();++i){
        if((*i)->name=="NoDraw")return;
    }
    for(int i = 0; i < num && hand.group.size()<=10; i++)
    {
        if(drawPile.group.empty()){
            discardPile.shuffle(discardPile.group.size());
            drawPile.group.merge(discardPile.group);
        }
        if(drawPile.group.empty()){
            break;
        }
        hand.addToBottom(*(drawPile.group.begin()));
        drawPile.group.pop_front();
    }
}

void AbstractPlayer::damage(DamageInfo&info){
    int damageAmount = info.outputValue;

    if (damageAmount <= 0)
        damageAmount = 0;

    if(info.type != DamageInfo::HP_LOSS)
        damageAmount = decrementBlock(info, damageAmount);

    damageAmount = damageAmount < currentHealth ? damageAmount : currentHealth;

    for(auto i:info.owner->buff){
        if(i->name=="PainfulStabs"){
            discardPile.addToTop(new Wound);
            break;
        }
    }
    currentHealth -= damageAmount;
    //healthbarupdate;

    if(currentHealth <= 0)
    {
        isDead = true;

        if(currentBlock > 0)
            loseBlock(currentBlock);
    }
}
void AbstractPlayer::damage(int dmg){
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
