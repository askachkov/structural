#include "flyweight.h"

#include <iostream>
#include <map>

std::map<std::string, std::shared_ptr<StringNode> > CASH;

std::shared_ptr<StringNode> createFlyweightString(const std::string & s)
{
    auto it = CASH.find(s);
    if ( it != CASH.end() ){
        return it->second;
    }
    std::cout << "LOG: added str: " << s << std::endl;
    auto res = createString(s);
    CASH[s] = res;
    return res;
}