#include "EliteRoom.h"
#include "../monsters/SpireShield.h"
#include "../monsters/SpireSpear.h"
EliteRoom::EliteRoom()
{
    type = AbstractRoom::MONSTER;
    monsters.addMonster(new SpireShield);
    monsters.addMonster(new SpireSpear);
}
