#include "User.h"

namespace persistence {
User::User(bool _a,
           std::string _l,
           std::string _p,
           std::string _n,
           std::string _s,
           std::string _ph,
           std::string _e,
           double _r) :
    super(_a),
    login(_l),
    pass(_p),
    name(_n),
    surname(_s),
    phone(_ph),
    email(_e),
    rang(_r)
{ }

// Getters:
bool User::GetSuper(){return super;}
std::string User::GetLogin(){return login;}
std::string User::GetPass(){return pass;}
std::string User::GetName() {return name;}
std::string User::GetSurname() {return surname;}
std::string User::GetPhone() {return phone;}
std::string User::GetEmail() {return email;}
double User::GetRang() {return rang;}

//Setters:
void User::SetSuper(bool s) {super = s;}
void User::SetLogin(const std::string& l) {login = l;}
void User::SetPass(const std::string& p) {pass = p;}
void User::SetName(const std::string& n) {name= n;}
void User::SetSurname(const std::string& sn) {surname = sn;}
void User::SetPhone(const std::string& ph) {phone = ph;}
void User::SetEmail(const std::string& e) {email = e;}
void User::SetRang(double r) {rang = r;}

QDataStream &operator>>(QDataStream &in, User& u)
{
    bool b;
    in >> b;
    u.SetSuper(b);
    QString l, p, n, s, ph, e;
    in >> l >> p >> n >> s >> ph >> e;
    u.SetLogin(l.toStdString());
    u.SetPass(p.toStdString());
    u.SetName(n.toStdString());
    u.SetSurname(s.toStdString());
    u.SetPhone(ph.toStdString());
    u.SetEmail(e.toStdString());
    QString temp;
    in >> temp;
    u.SetRang(temp.toDouble());
    return in;
}

QDataStream &operator<<(QDataStream &out, const User& u)
{
    out << (bool)u.super;
    out << QString::fromStdString(u.login);
    out << QString::fromStdString(u.pass);
    out << QString::fromStdString(u.name);
    out << QString::fromStdString(u.surname);
    out << QString::fromStdString(u.phone);
    out << QString::fromStdString(u.email);
    QString temp = QString::number(u.rang);
    out << temp;//(double)u.rang;
    return out;
}

} // persistence
