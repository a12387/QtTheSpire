#include "CardGroup.h"
#include <algorithm>
CardGroup::CardGroup(CardGroupType type) : type(type) {}

void CardGroup::clear()
{
//    auto i = group.begin();
//    while(i != group.end())
//    {
//        delete (*i);
//        i++;
//    }
    group.clear();
}

void CardGroup::removeCard(AbstractCard *card)
{
    group.remove(card);
}

bool CardGroup::removeCard(std::string id)
{
    auto it = group.begin();
    while(it != group.end())
    {
        if((*it)->id == id)
        {
            group.erase(it);
            return true;
        }
        it++;
    }
    return false;
}

void CardGroup::addToTop(AbstractCard *card)
{
    group.push_front(card);
}

void CardGroup::addToBottom(AbstractCard *card)
{
    group.push_back(card);
}
void CardGroup::shuffle(int n){
    if(n<=2)return;
    auto i=group.begin(),j=group.end();
    std::advance(i,rand()%(n-1));
    j--;
    std::iter_swap(i,j);
    shuffle(n-1);
}
