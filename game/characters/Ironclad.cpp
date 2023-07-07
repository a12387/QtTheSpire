#include "Ironclad.h"
#include "../cards/red/Strike_Red.h"
#include "../cards/red/Defend_Red.h"
#include "../cards/red/Bash.h"
Ironclad::Ironclad()
    :AbstractPlayer(std::string(":/game/resource/creature/ironclad.png"),
                    std::string("Ironclad"),
                    std::string("Ironclad"),
                    80)
{
    this->isPlayer  = true;
    this->gold = 300;
    masterDeck.addToBottom(new Strike_Red);
    masterDeck.addToBottom(new Strike_Red);
    masterDeck.addToBottom(new Strike_Red);
    masterDeck.addToBottom(new Defend_Red);
    masterDeck.addToBottom(new Defend_Red);
    masterDeck.addToBottom(new Bash);
}
