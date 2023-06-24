#include "MonsterGroup.h"

MonsterGroup::~MonsterGroup()
{
    for(auto &i : monsters)
    {
        delete i;
    }
}
void MonsterGroup::addMonster(AbstractMonster *m)
{
    monsters.push_back(m);
}
