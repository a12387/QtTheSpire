#ifndef _ABSTRACTPLAYER_H_
#define _ABSTRACTPLAYER_H_

#include "../core/AbstractCreature.h"
#include "../cards/CardGroup.h"


class AbstractPlayer : public AbstractCreature
{
public:
    CardGroup masterDeck = CardGroup(CardGroup::MASTER_DECK);
    CardGroup drawPile   = CardGroup(CardGroup::DRAW_PILE);
    CardGroup hand       = CardGroup(CardGroup::HAND);
    CardGroup discardPile= CardGroup(CardGroup::DISCARD_PILE);
    CardGroup exhaustPile= CardGroup(CardGroup::EXHAUST_PILE);
    int direction;
    int energy;

    //QVector<AbstractRelic> relics;
    //QVector<AbstractPotion> potions;

    AbstractPlayer(std::string imgUrl,std::string name, std::string id, int health);


    void useCard(AbstractCard &card,AbstractMonster &m,int energyUse);

    void preBattle();

    void drawCard(int num);

    void damage(DamageInfo&);
    void damage(int dmg);
};

#endif
