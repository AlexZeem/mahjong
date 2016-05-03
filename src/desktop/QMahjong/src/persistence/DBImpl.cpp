#include <QFile>
#include <QDebug>
#include "Game.h"
#include "Hand.h"
#include "User.h"
#include "Participant.h"
#include "DBImpl.h"

namespace persistence {

impl_t::impl_t()
    : gamesDataPath("games.dat")
    , handsDataPath("hands.dat")
    , limitsDataPath("limits.dat")
    , usersDataPath("users.dat")
    , participantsDataPath("participants.dat")
{ }

impl_t::~impl_t()
{ }

User impl_t::selectUser(const QString &login)
{
    return users.value(login);
}

bool impl_t::updateUser(const User &u, const QString& login)
{
    QString key = !login.isEmpty() ? login : u.getLogin();
    if (!users.contains(key)) {
        return false;
    } else {
        users[key] = u;
        return true;
    }
}

bool impl_t::addUser(const User &u)
{
    if (users.contains(u.getLogin())) {
        return false;
    } else {
        users[u.getLogin()] = u;
        return true;
    }
}

bool impl_t::deleteUser(const User &u)
{
    if (!users.contains(u.getLogin())) {
        return false;
    } else {
        users.erase(users.find(u.getLogin()));
        return true;
    }
}

QMap<QString, User> impl_t::getUsers()
{
    return users;
}

void impl_t::saveGamesData(const QString& path)
{
    QFile file(path + gamesDataPath);
    file.open(QFile::WriteOnly);
    QDataStream ostream(&file);

    for (const auto& i : games) {
        ostream << i;
    }

    file.flush();
    file.close();
}

void impl_t::loadGamesData(const QString& path, unsigned int counter)
{
    QFile file(path + gamesDataPath);
    file.open(QFile::ReadOnly);
    QDataStream istream(&file);

    for (unsigned int i = 0; i < counter; ++i) {
        Game g;
        istream >> g;
        games[g.getGameId()] = g;
        //g.print();
    }

    file.close();
}

void impl_t::saveHandsData(const QString& path)
{
    QFile file(path + handsDataPath);
    file.open(QFile::WriteOnly);
    QDataStream ostream(&file);

    for (const auto& i : hands) {
        ostream << i;
    }

    file.flush();
    file.close();
}

void impl_t::loadHandsData(const QString& path, unsigned int counter)
{
    QFile file(path + handsDataPath);
    file.open(QFile::ReadOnly);
    QDataStream istream(&file);

    for (unsigned int i = 0; i < counter; ++i) {
        Hand h;
        istream >> h;
        hands[h.getHandId()] = h;
        //h.print();
    }

    file.close();
}

void impl_t::saveLimitsData(const QString& path)
{
    QFile file(path + limitsDataPath);
    file.open(QFile::WriteOnly);
    QDataStream ostream(&file);

    for (const auto& i : limits) {
        ostream << i;
    }

    file.flush();
    file.close();
}

void impl_t::loadLimitsData(const QString& path, unsigned int counter)
{
    QFile file(path + limitsDataPath);
    file.open(QFile::ReadOnly);
    QDataStream istream(&file);

    for (unsigned int i = 0; i < counter; ++i) {
        QString l;
        istream >> l;
        limits << l;
        //qDebug() << "Limit: " << l;
    }

    file.close();
}

void impl_t::saveUsersData(const QString& path)
{
    QFile file(path + usersDataPath);
    file.open(QFile::WriteOnly);
    QDataStream ostream(&file);

    for (const auto& i : users) {
        //i.print();
        ostream << i;
    }

    file.flush();
    file.close();
}

void impl_t::loadUsersData(const QString& path, unsigned int counter)
{
    QFile file(path + usersDataPath);
    file.open(QFile::ReadOnly);
    QDataStream istream(&file);

    for (unsigned int i = 0; i < counter; ++i) {
        User u;
        istream >> u;
        users[u.getLogin()] = u;
        //u.print();
    }

    file.close();
}

void impl_t::saveParticipantsData(const QString& path)
{
    QFile file(path + participantsDataPath);
    file.open(QFile::WriteOnly);
    QDataStream ostream(&file);

    for (const auto& i : participants) {
        ostream << i;
    }

    file.flush();
    file.close();
}

void impl_t::loadParticipantsData(const QString& path, unsigned int counter)
{
    QFile file(path + participantsDataPath);
    file.open(QFile::ReadOnly);
    QDataStream istream(&file);

    for (unsigned int i = 0; i < counter; ++i) {
        Participant p;
        istream >> p;
        participants[p.getGameId()] = p;
        //p.print();
    }

    file.close();
}

} //namespace persistence
