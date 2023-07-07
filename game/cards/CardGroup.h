#ifndef _CARDGROUP_H_
#define _CARDGROUP_H_

#include "AbstractCard.h"


class CardGroup
{
public:
    enum CardGroupType
    {
        DRAW_PILE,   // 抽牌堆
        MASTER_DECK, // 牌组
        HAND,        // 手牌
        DISCARD_PILE,// 弃牌堆
        EXHAUST_PILE,// 烧牌堆
        CARD_POOL,   // 牌库
        UNSPECIFIED  // 临时用
    };
    CardGroupType type;
    QVector<AbstractCard*> group;

    CardGroup(CardGroupType type);

    void clear();//清除牌堆

    void removeCard(AbstractCard *card);//通过Card移出卡牌
    bool removeCard(std::string id);//通过ID移出卡牌

    void addToTop(AbstractCard *card);

    void addToBottom(AbstractCard *card);
    
    void shuffle(int);
};

#endif
