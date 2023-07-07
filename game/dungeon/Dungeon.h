#ifndef _DUNGEON_H_
#define _DUNGEON_H_

#include "../characters/AbstractPlayer.h"
#include "../rooms/AbstractRoom.h"
#include <vector>

class Dungeon
{
public:
    AbstractPlayer *player;
    std::vector<AbstractRoom *> rooms;
    int floor = 0;

    Dungeon();
    ~Dungeon();

    void init();
};

#endif
