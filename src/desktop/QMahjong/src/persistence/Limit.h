#pragma once
#include <string>
#include <iostream>
#include "Serializable.h"

namespace persistence {

class Limit : public Serializable
{
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */)
    {
        std::cout << "serialize Limit" << std::endl;
        ar & name;
    }

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
