#include "Dungeon.h"
#include "../rooms/CampfireRoom.h"
#include "../rooms/ShopRoom.h"
#include "../rooms/EliteRoom.h"
#include "../rooms/BossRoom.h"
#include "../characters/Ironclad.h"
Dungeon::Dungeon() : player(new Ironclad)
{
    rooms.push_back(new CampfireRoom);
    rooms.push_back(new ShopRoom);
    rooms.push_back(new EliteRoom);
    rooms.push_back(new BossRoom);
}

Dungeon::~Dungeon()
{
    for(auto &i : rooms)
    {
        delete i;
    }
    delete player;
}
