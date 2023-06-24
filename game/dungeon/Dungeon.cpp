#include "Dungeon.h"
#include "../rooms/CampfireRoom.h"
#include "../rooms/ShopRoom.h"
#include "../rooms/EliteRoom.h"
#include "../characters/Ironclad.h"
Dungeon::Dungeon() : player(new Ironclad)
{
    rooms.push_back(new CampfireRoom);
    rooms.push_back(new ShopRoom);
    rooms.push_back(new EliteRoom);
}

Dungeon::~Dungeon()
{
    for(auto &i : rooms)
    {
        delete i;
    }
    delete player;
}
