#include "AbstractRelic.h"

int AbstractRelic::getPrice(){
        switch(tier){
            case COMMON:return 150;
            case UNCOMMON:return 250;
            case RARE:return 300;
            case SHOP:return 150;
            default:return -1;
        }
}
AbstractRelic::AbstractRelic(std::string setId, RelicTier tier) {
        relicId = setId;
        DESCRIPTIONS = relicStrings.DESCRIPTIONS;
        name = relicStrings.NAME;
        description = getUpdatedDescription();
        tier = tier;
        
}
std::string AbstractRelic::getUpdatedDescription() {
        return " ";
}