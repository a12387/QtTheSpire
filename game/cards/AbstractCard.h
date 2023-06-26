#ifndef _ABSTRACTCARD_H_
#define _ABSTRACTCARD_H_

#include <iostream>
#include <list>
#include "DamageInfo.h"
class AbstractPlayer;
class AbstractMonster;

class AbstractCard
{
public:
    enum CardColor
    {
        RED,
        BLUE,
        GREEN,
        PURPLE,
        COLORLESS,
        CURSE_COLOR
    };

    enum CardRarity
    {
        BASIC,
        SPECIAL,
        COMMON,
        UNCOMMON,
        RARE,
        CURSE_RARITY
    };

    enum CardTags
    {
        HEALING,
        STRIKE,
        EMPTY,
        STARTER_DEFEND,
        STARTER_STRIKE
    };

    enum CardTarget
    {
        ENEMY,
        ALL_ENEMY,
        SELF,
        NONE,
        SELF_AND_ENEMY,
        ALL
    };

    enum CardType
    {
        ATTACK,
        SKILL,
        POWER,
        STATUS,
        CURSE_TYPE
    };
    
    std::string id;
    std::string name;
    std::string imgUrl;
    int cost;
    std::string description;
    CardColor color;
    CardRarity rarity;
    CardTarget target;
    CardType type;
    DamageInfo::DamageType dType;

    bool upgraded = false; // 升级
    bool retain  = false;  // 保留
    bool innate  = false;  // 固有
    bool exhaust = false;  // 消耗
    bool ethereal= false;  // 虚无

    std::list<CardTags> tags;

    //base为原始数值，不受buff影响，受升级影响
    int baseDamage      = -1;  // 伤害
    int baseBlock       = -1;  // 格挡
    int baseMagicNumber = -1;  // 特殊效果
    int baseHeal        = -1;  // 治疗
    int baseDraw        = -1;  // 抽牌
    int baseDiscard     = -1;  // 弃牌
    int damage          = -1;
    int block           = -1;
    int magicNumber     = -1;
    int heal            = -1;
    int draw            = -1;
    int discard         = -1;

    virtual void upgrade();

    virtual void use(AbstractPlayer *abstractPlayer, AbstractMonster *AbstractMonster) = 0;

    AbstractCard(std::string id, std::string name, std::string imgUrl, int cost, std::string description, CardType type, CardColor color, CardRarity rarity, CardTarget target, DamageInfo::DamageType dType);

    virtual ~AbstractCard();

    bool operator==(const AbstractCard &c);

    virtual AbstractCard *makeCopy() = 0;
};

#endif
