#pragma once
#include <string>
#include <iostream>

namespace persistence {

class Limit
{
public:
    Limit();
    Limit(const std::string&);

private:
    std::string name;
};

} //persistence
