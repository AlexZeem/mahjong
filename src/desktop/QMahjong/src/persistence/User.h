#pragma once
#include <string>
#include <iostream>

namespace persistence {

class User
{
public:
    User()
    { }

    User(const bool& _a) :
        super(_a)
    { }

    User(const std::string& _l, const std::string& _p, const std::string& _n, const std::string& _s, const std::string& _ph, const std::string& _e) :
        login(_l),
        pass(_p),
        name(_n),
        surname(_s),
        phone(_ph),
        email(_e)
    { }

    User(const double& _r) :
        rang(_r)
    { }

private:
    bool super;
    std::string login;
    std::string pass;
    std::string name;
    std::string surname;
    std::string phone;
    std::string email;
    double rang;

};

} //persistence
