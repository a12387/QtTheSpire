#ifndef _ABSTRACTPOWER_H_
#define _ABSTRACTPOWER_H_
#include <iostream>
class AbstractPower{
public:
    enum PowerType {
        BUFF,DEBUFF
    };
    std::string name;
    int amount;
    PowerType type;
    std::string imgPath;
    AbstractPower(int,std::string);
};

#endif
