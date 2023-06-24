#include "EliteRoom.h"
#include "../monsters/SpireShield.h"
EliteRoom::EliteRoom()
{
    type = AbstractRoom::MONSTER;
    monsters.addMonster(new SpireShield);
}

