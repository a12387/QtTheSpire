#ifndef _ABSTRACTPLAYER_H_
#define _ABSTRACTPLAYER_H_

#include "../core/AbstractCreature.h"
#include "../cards/CardGroup.h"
#include <list>

class AbstractPlayer : public AbstractCreature
{
public:
    CardGroup masterDeck = CardGroup(CardGroup::MASTER_DECK);
    CardGroup drawPile   = CardGroup(CardGroup::DRAW_PILE);
    CardGroup hand       = CardGroup(CardGroup::HAND);
    CardGroup discardPile= CardGroup(CardGroup::DISCARD_PILE);
    CardGroup exhaustPile= CardGroup(CardGroup::EXHAUST_PILE);
    int direction;

    //std::list<AbstractRelic> relics;
    //std::list<AbstractPotion> potions;

    AbstractPlayer(std::string imgUrl,std::string name, std::string id, int health);


    void useCard(AbstractCard &card,AbstractMonster &m,int energyUse);

    void preBattle();

    void drawCard(int num);
};

#endif
