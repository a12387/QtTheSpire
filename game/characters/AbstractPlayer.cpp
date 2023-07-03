#include "AbstractPlayer.h"
#include "mainwindow.h"
#include "../powers/Surrounded.h"

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
    for(int i = 0; i < num && hand.group.size()<=10; i++)
    {
        if(drawPile.group.empty()){
            discardPile.shuffle(discardPile.group.size());
            drawPile.group.merge(discardPile.group);
        }
        hand.addToBottom(*(drawPile.group.begin()));
        drawPile.group.pop_front();
    }
}
