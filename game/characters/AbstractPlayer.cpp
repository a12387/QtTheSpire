#include "AbstractPlayer.h"

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

    for(auto &i : masterDeck.group)
    {
        drawPile.addToBottom(i->makeCopy());
    }


    //relic;
}

void AbstractPlayer::drawCard(int num)
{
    for(int i = 0; i < num && hand.group.size()<=10; i++)
    {
        hand.addToBottom(*(drawPile.group.begin()));
        drawPile.group.pop_front();
    }
}
