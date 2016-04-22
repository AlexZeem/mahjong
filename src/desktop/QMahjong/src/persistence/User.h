#pragma once
#include <string>
#include <iostream>

namespace persistence {

class User
{
public:
    User()
    { }

    User(const boolean& _a) :
        super(_a)
    { }

    User(const std::string& _l) :
        login(_l)
    { }

    User(const std::string& _p) :
        pass(_p)
    { }

    User(const std::string& _n) :
        name(_n)
    { }

    User(const std::string& _s) :
        surname(_s)
    { }

    User(const std::string& _p) :
        phone(_p)
    { }

    User(const std::string& _e) :
        email(_e)
    { }

    User(const double& _r) :
        rang(_r)
    { }

private:
    boolean super;
    std::string login;
    std::string pass;
    std::string name;
    std::string surname;
    std::string phone;
    std::string email;
    double rang;

};

} //persistence
