#pragma once
#include <string>
#include <iostream>

namespace persistence {

class Limit
{
public:
    Limit()
    { }

    Limit(const std::string& _n) :
        name(_n)
    { }

private:
    std::string name;
};

} //persistence
