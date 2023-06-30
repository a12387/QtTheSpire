
#include "BossRoom.h"
#include "game/monsters/CorruptHeart.h"

BossRoom::BossRoom()
{
    type=AbstractRoom::BOSS;
    monsters.addMonster(new CorruptHeart);
}
