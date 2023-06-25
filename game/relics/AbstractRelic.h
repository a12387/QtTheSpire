#ifndef _ABSTRACTRELIC_H_
#define _ABSTRACTRELIC_H_

#include <iostream>
#include <string.h>

class RelicStrings {
public: std::string NAME;
        std::string FLAVOR;
        std::string DESCRIPTIONS;
};

class AbstractRelic{
public:
    std::string name, relicId ,description, DESCRIPTIONS;
    int cost;
    RelicStrings relicStrings;
    enum RelicTier{ STARTER , COMMON , UNCOMMON , RARE , BOSS , SHOP };
    RelicTier tier;
    AbstractRelic(std::string , RelicTier ) ;
    int getPrice();
    std::string getUpdatedDescription() ;
};


#endif