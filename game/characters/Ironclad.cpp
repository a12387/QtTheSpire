#include "Ironclad.h"
#include "../cards/red/Strike_Red.h"
Ironclad::Ironclad()
    :AbstractPlayer(std::string(":/game/resource/creature/ironclad.png"),
                    std::string("Ironclad"),
                    std::string("Ironclad"),
                    80)
{
    this->isPlayer  = true;
    this->gold = 300;

    for(int i=0;i<100;i++)masterDeck.addToTop(new Strike_Red);
}
