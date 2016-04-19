#pragma once

#include <boost/serialization/access.hpp>
namespace persistence {

class Serializable
{
    friend class boost::serialization::access;
public:
    Serializable() {}
};

} //persistence
