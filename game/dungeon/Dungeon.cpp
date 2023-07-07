#include "Dungeon.h"
#include "../rooms/CampfireRoom.h"
#include "../rooms/ShopRoom.h"
#include "../rooms/EliteRoom.h"
#include "../rooms/BossRoom.h"
#include "../characters/Ironclad.h"
Dungeon::Dungeon()
{
    init();
}

Dungeon::~Dungeon()
{
    for(auto &i : rooms)
    {
        delete i;
    }
    delete player;
}

void Dungeon::init()
{
    rooms.clear();
    rooms.push_back(new CampfireRoom);
    rooms.push_back(new ShopRoom);
    rooms.push_back(new EliteRoom);
    rooms.push_back(new BossRoom);
    delete player;
    player = new Ironclad;
    floor = 0;
}
