#include <QDebug>
#include "User.h"

namespace persistence {

QDataStream &operator << (QDataStream &out, const User& obj)
{
    out << obj.super;
    out << QString::number(obj.rang);
    out << obj.login;
    out << obj.pass;
    out << obj.name;
    out << obj.surname;
    out << obj.phone;
    out << obj.email;
    return out;
}

QDataStream &operator >> (QDataStream &in, User& obj)
{
    in >> obj.super;
    QString temp;
    in >> temp;
    obj.rang = temp.toDouble();
    in >> obj.login;
    in >> obj.pass;
    in >> obj.name;
    in >> obj.surname;
    in >> obj.phone;
    in >> obj.email;
    return in;
}

User::User(bool _a,
           QString _l,
           QString _p,
           QString _n,
           QString _s,
           QString _ph,
           QString _e,
           double _r)
    : super(_a)
    , rang(_r)
    , login(_l)
    , pass(_p)
    , name(_n)
    , surname(_s)
    , phone(_ph)
    , email(_e)
{ }

bool User::getSuper() const
{
    return super;
}

void User::setSuper(bool value)
{
    if (value != super) super = value;
}

double User::getRang() const
{
    return rang;
}

void User::setRang(double value)
{
    if (value != rang) rang = value;
}

QString User::getLogin() const
{
    return login;
}

void User::setLogin(const QString &value)
{
    if (value != login) login = value;
}

QString User::getPass() const
{
    return pass;
}

void User::setPass(const QString &value)
{
    if (value != pass) pass = value;
}

QString User::getName() const
{
    return name;
}

void User::setName(const QString &value)
{
    if (value != name) name = value;
}

QString User::getSurname() const
{
    return surname;
}

void User::setSurname(const QString &value)
{
    if (value != surname) surname = value;
}

QString User::getPhone() const
{
    return phone;
}

void User::setPhone(const QString &value)
{
    if (value != phone) phone = value;
}

QString User::getEmail() const
{
    return email;
}

void User::setEmail(const QString &value)
{
    if (value != email) email = value;
}

void User::print() const
{
    qDebug() << "User super:" << super;
    qDebug() << "User rang:" << rang;
    qDebug() << "User login:" << login;
    qDebug() << "User pass:" << pass;
    qDebug() << "User name:" << name;
    qDebug() << "User surname:" << surname;
    qDebug() << "User phone:" << phone;
    qDebug() << "User email:" << email;
}

} // persistence
