#pragma once

#include <string>

namespace persistence {

class User
{
public:

    User(bool _a = "true", std::string _l = "a", std::string _p = "a", std::string _n = "Player",
         std::string _s = "First", std::string _ph = "000 123 45 67", std::string _e = "some@email.com", double _r = 0.10) :
        super(_a),
        login(_l),
        pass(_p),
        name(_n),
        surname(_s),
        phone(_ph),
        email(_e),
        rang(_r)
    { }

    //in favor of project structure get/set also in header.
    bool GetSuper() {
        return super;
    }
    void SetSuper(bool s) {
        super = s;
    }
    std::string GetLogin() {
        return login;
    }
    void SetLogin(const std::string& l) {
        login = l;
    }
    std::string GetPass() {
        return pass;
    }
    void SetPass(const std::string& p) {
        pass = p;
    }
    std::string GetName() {
        return name;
    }
    void SetName(const std::string& n) {
        name = n;
    }
    std::string GetSurname() {
        return surname;
    }
    void SetSurname(const std::string& sn) {
        surname = sn;
    }
    std::string GetPhone() {
        return phone;
    }
    void SetPhone(const std::string& ph) {
        phone = ph;
    }
    std::string GetEmail() {
        return email;
    }
    void SetEmail(const std::string& e) {
        email = e;
    }
    double GetRang() {
        return rang;
    }
    void SetRang(double r) {
        rang = r;
    }

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
