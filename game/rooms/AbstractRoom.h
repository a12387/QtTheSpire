#ifndef _ABSTRACTROOM_H_
#define _ABSTRACTROOM_H_

#include "../monsters/MonsterGroup.h"
class QWidget;
class AbstractRoom
{
public:
    enum RoomType
    {
        SHOP,   //商店
        CAMPFIRE, //营火
        MONSTER,//普通、精英
        BOSS    //BOSS
    };
    RoomType type;
    MonsterGroup monsters;

    QWidget *screen;

    AbstractRoom(QWidget *screen = nullptr);

    //void update();

    virtual ~AbstractRoom();
};

#endif
