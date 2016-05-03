#pragma once

#include <QString>
#include <QDataStream>

namespace persistence {

class User
{
public:
    friend QDataStream &operator << (QDataStream &out, const User& obj);
    friend QDataStream &operator >> (QDataStream &in, User& obj);

    User(bool _a = false,
         QString _l = "a",
         QString _p = "a",
         QString _n = "Player",
         QString _s = "First",
         QString _ph = "000 123 45 67",
         QString _e = "some@email.com",
         double _r = 0.10);

    bool getSuper() const;
    void setSuper(bool value);

    double getRang() const;
    void setRang(double value);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPass() const;
    void setPass(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getSurname() const;
    void setSurname(const QString &value);

    QString getPhone() const;
    void setPhone(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    void print() const;

private:
    bool super;
    double rang;
    QString login;
    QString pass;
    QString name;
    QString surname;
    QString phone;
    QString email;
};

} //persistence
