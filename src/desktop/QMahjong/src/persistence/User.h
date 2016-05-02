#pragma once

#include <string>
#include <QDataStream>

namespace persistence {

class User
{
public:

    User(bool _a = "true",
         std::string _l = "a",
         std::string _p = "a",
         std::string _n = "Player",
         std::string _s = "First",
         std::string _ph = "000 123 45 67",
         std::string _e = "some@email.com",
         double _r = 0.10);

    // Getters:
    bool GetSuper();
    QString GetLogin();
    std::string GetPass();
    std::string GetName();
    std::string GetSurname();
    std::string GetPhone();
    std::string GetEmail();
    double GetRang();

    //Setters:
    void SetSuper(bool);
    void SetLogin(const std::string&);
    void SetPass(const std::string&);
    void SetName(const std::string&);
    void SetSurname(const std::string&);
    void SetPhone(const std::string&);
    void SetEmail(const std::string&);
    void SetRang(double);

    //reddifine in/out operators
    friend QDataStream& operator << (QDataStream& out, const User&);
    friend QDataStream& operator >> (QDataStream& in, User&);

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
