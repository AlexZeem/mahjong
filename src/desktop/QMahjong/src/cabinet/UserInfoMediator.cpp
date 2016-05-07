#include "UserInfoMediator.h"
#include "../persistence/DBHandler.h"
#include "../persistence/User.h"
#include <QDebug>

namespace cabinet {

UserInfoMediator::UserInfoMediator(QObject *parent)
    :QObject(parent)
{}

QString UserInfoMediator::nickname() const
{

    return currentUser.getLogin();
}

QString UserInfoMediator::name() const
{
    return currentUser.getName();
}

QString UserInfoMediator::surname() const
{
    return currentUser.getSurname();
}

QString UserInfoMediator::phone() const
{
    return currentUser.getPhone();
}

QString UserInfoMediator::email() const
{
    return currentUser.getEmail();
}

double UserInfoMediator::rang() const
{
    return currentUser.getRang();
}

void UserInfoMediator::setNickname(QString nickname)
{
    if (currentUser.getLogin() == nickname)
        return;
    persistence::User temp = currentUser;
    temp.setLogin(nickname);
    if (persistence::DBHandler::instance()->updateUser(temp, currentUser.getLogin()))
    {
        currentUser.setLogin(nickname);
        emit userChanged();
    }

}

void UserInfoMediator::setName(QString name)
{
    if (currentUser.getName()  == name)
        return;
    persistence::User temp = currentUser;
    temp.setName(name);
    if (persistence::DBHandler::instance()->updateUser(temp))
    {
        currentUser.setName(name);
        emit userChanged();
    }
}

void UserInfoMediator::setSurname(QString surname)
{

    if (currentUser.getSurname() == surname)
        return;
    persistence::User temp = currentUser;
    temp.setSurname(surname);
    if (persistence::DBHandler::instance()->updateUser(temp))
    {
        currentUser.setSurname(surname);
        emit userChanged();
    }
}

void UserInfoMediator::setPhone(QString phone)
{
    if (currentUser.getPhone() == phone)
        return;
    persistence::User temp = currentUser;
    temp.setPhone(phone);
    if(persistence::DBHandler::instance()->updateUser(temp))
    {
        currentUser.setPhone(phone);
        emit userChanged();
    }
}

void UserInfoMediator::setEmail(QString email)
{
    if (currentUser.getEmail() == email)
        return;
    persistence::User temp = currentUser;
    temp.setEmail(email);
    if (persistence::DBHandler::instance()->updateUser(temp))
    {
        currentUser.setEmail(email);
        emit userChanged();
    }
}

void UserInfoMediator::setRang(double rang)
{
    if (currentUser.getRang() == rang)
        return;
    persistence::User temp = currentUser;
    temp.setRang(rang);
    if (persistence::DBHandler::instance()->updateUser(temp))
    {
        currentUser.setRang(rang);
        emit userChanged();
    }
}

void UserInfoMediator::setUser(QString login)
{
    currentUser = persistence::DBHandler::instance()->selectUser(login);
    emit userChanged();
}



} // namespace cabinet