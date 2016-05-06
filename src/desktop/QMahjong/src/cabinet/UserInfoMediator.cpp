#include "UserInfoMediator.h"
#include "../persistence/DBHandler.h"
#include "../persistence/User.h"

namespace cabinet {

UserInfoMediator::UserInfoMediator(QObject *parent)
    :QObject(parent)
{}

QString UserInfoMediator::nickname() const
{
    return _nickname;
}

QString UserInfoMediator::name() const
{
    return _name;
}

QString UserInfoMediator::surname() const
{
    return _surname;
}

QString UserInfoMediator::phone() const
{
    return _phone;
}

QString UserInfoMediator::email() const
{
    return _email;
}

//double UserInfoMediator::rang() const
//{
//    return _rang;
//}

void UserInfoMediator::setNickname(QString nickname)
{
    if (_nickname == nickname)
        return;

    if (nickname != _nickname){
        _nickname = nickname;
        emit userChanged(nickname);
    }
}

void UserInfoMediator::setName(QString name)
{
    persistence::User currentUser = persistence::DBHandler::instance()->selectUser(name);
    _name = currentUser.getName();
}

void UserInfoMediator::setSurname(QString surname)
{
    persistence::User currentUser = persistence::DBHandler::instance()->selectUser(surname);
    _surname = currentUser.getSurname();
}

void UserInfoMediator::setPhone(QString phone)
{
    persistence::User currentUser = persistence::DBHandler::instance()->selectUser(phone);
    _phone = currentUser.getPhone();
}

void UserInfoMediator::setEmail(QString email)
{
    persistence::User currentUser = persistence::DBHandler::instance()->selectUser(email);
    _email = currentUser.getEmail();
}

//void UserInfoMediator::setRang(double rang)
//{
//    persistence::User currentUser = persistence::DBHandler::instance()->u;
//    _rang = currentUser.rang;
//}



} // namespace cabinet
