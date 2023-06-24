#ifndef _ABSTRACTCREATURE_H_
#define _ABSTRACTCREATURE_H_

#include "../cards/DamageInfo.h"
#include <list>

class AbstractCreature
{
public:
    std::string imgUrl;
    std::string name;
    std::string id;
    bool isPlayer;
    int currentHealth;
    int maxHealth;
    int currentBlock;
    int gold;
    bool isDying = false;
    bool isDead  = false;
    bool halfDead= false;
    //std::list<AbstractPower> buff;

    AbstractCreature(std::string imgUrl,std::string name, std::string id, int health);

    void damage(DamageInfo &damageInfo);

    int decrementBlock(DamageInfo &damageInfo, int damageAmount);

    void loseBlock(int amount);

    void addBlock(int amount);

    //void addPower(AbstractPower &power);

    void loseGold(int amount);

    void gainGold(int amount);

    void heal(int amount);
};

#endif
