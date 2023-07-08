#include "game/cards/red/PommelStrike.h"
#include "game/cards/red/Bludgeon.h"
#include "game/cards/red/Cleave.h"
#include "game/cards/red/Anger.h"
#include "game/cards/red/Clothesline.h"
#include "game/cards/red/Bloodletting.h"
#include "game/cards/red/ShrugItOff.h"
#include "game/cards/red/TrueGrit.h"
#include "game/cards/red/BodySlam.h"
#include "game/cards/red/BattleTrance.h"
#include "game/cards/red/BurningPact.h"
#include "game/cards/red/Inflame.h"
#include "game/cards/red/SpotWeakness.h"
#include "game/cards/red/DarkEmbrace.h"
#include "game/cards/red/PowerThrough.h"
#include "game/cards/red/Entrench.h"
#include "game/cards/red/SecondWind.h"
#include "game/cards/red/FeelNoPain.h"
#include "game/cards/red/Whirlwind.h"
#include "game/cards/red/Corruption.h"
#include "game/cards/red/DemonForm.h"
#include "game/cards/red/Offering.h"
#include "game/cards/red/Barricade.h"
#include "game/cards/red/LimitBreak.h"
#include "game/cards/red/Exhume.h"
#include "RandomCard.h"

std::vector<AbstractCard*> RandomCard::attack =  {
    new BodySlam,
    new PommelStrike,
    new Whirlwind,
    new Bludgeon,
    new Cleave,
    new Anger,
    new Clothesline
};

std::vector<AbstractCard*> RandomCard::skill  = {
    new BurningPact,
    new BattleTrance,
    new Exhume,
    new LimitBreak,
    new Offering,
    new PowerThrough,
    new SecondWind,
    new Entrench,
    new ShrugItOff,
    new SpotWeakness,
    new TrueGrit,
    new Bloodletting
};

std::vector<AbstractCard*> RandomCard::power =  {
    new Barricade,
    new Corruption,
    new DarkEmbrace,
    new DemonForm,
    new FeelNoPain,
    new Inflame
};

std::vector<AbstractCard*> RandomCard::pool  =  {
    new BodySlam,
    new PommelStrike,
    new Whirlwind,
    new Bludgeon,
    new Cleave,
    new Anger,
    new Clothesline,
    new BurningPact,
    new BattleTrance,
    new Exhume,
    new LimitBreak,
    new Offering,
    new SecondWind,
    new PowerThrough,
    new Entrench,
    new ShrugItOff,
    new SpotWeakness,
    new TrueGrit,
    new Bloodletting,
    new Barricade,
    new Corruption,
    new DarkEmbrace,
    new DemonForm,
    new FeelNoPain,
    new Inflame
};
RandomCard::RandomCard()
{
}

AbstractCard *RandomCard::getAttackCard()
{
    return attack[rand() % attack.size()];
}
AbstractCard *RandomCard::getPowerCard()
{
    return power[rand() % power.size()];
}
AbstractCard *RandomCard::getSkillCard()
{
    return skill[rand() % skill.size()];
}
AbstractCard *RandomCard::getAnyCard()
{
    return pool[rand() % pool.size()];
}
