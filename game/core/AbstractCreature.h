#ifndef _ABSTRACTCREATURE_H_
#define _ABSTRACTCREATURE_H_

#include "../cards/DamageInfo.h"
#include <QVector>

class MainWindow;
class AbstractPower;
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
    MainWindow *mw;
    QVector<AbstractPower*> buff;

    AbstractCreature(std::string imgUrl,std::string name, std::string id, int health);

    virtual void damage(DamageInfo &damageInfo);
    void damage(int dmg);

    int decrementBlock(DamageInfo &damageInfo, int damageAmount);

    void loseBlock(int amount);
    void loseBlock();

    void addBlock(int amount);

    void ApplyPower(AbstractPower *power);

    void changePower();

    void loseGold(int amount);

    void gainGold(int amount);

    void heal(int amount);
};

#endif
