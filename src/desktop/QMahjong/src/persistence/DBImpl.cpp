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
        if (!login.isEmpty()) {
            users.remove(login);
        }
        users[u.getLogin()] = u;
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

Game impl_t::selectGame(unsigned long gameId)
{
    return games.value(gameId);
}

bool impl_t::updateGame(const Game &g)
{
    if (!games.contains(g.getGameId())) {
        return false;
    } else {
        games[g.getGameId()] = g;
        return true;
    }
}

bool impl_t::addGame(const Game &g)
{
    if (games.contains(g.getGameId())) {
        return false;
    } else {
        games[g.getGameId()] = g;
        return true;
    }
}

bool impl_t::deleteGame(const Game &g)
{
    if (!games.contains(g.getGameId())) {
        return false;
    } else {
        games.erase(games.find(g.getGameId()));
        return true;
    }
}

QMap<unsigned long, Game> impl_t::getGames()
{
    return games;
}

bool impl_t::updateParticipant(const Participant &p)
{
    participants[p.getGameId()] = p;
    return true;
}

QVector <Participant> impl_t::getParticipant(QString login)
{
    QVector <Participant> result;
    for (const auto & i : participants) {
       QVector <QString> userId = i.getUserId();
       for (auto & j : userId){
           if (j == login){
               result.push_back(i);
           }
       }
    }
    return result;
}

QVector<QString> impl_t::getPlayers(unsigned long gameId)
{
    if (!participants.contains(gameId)) {
        return QVector<QString>();
    } else {
        return participants.value(gameId).getUserId();
    }
}

bool impl_t::updateHand(const Hand &h)
{
    if (!hands.contains(h.getHandId())) {
        return false;
    } else {
        hands[h.getHandId()] = h;
        return true;
    }
}

bool impl_t::addHand(const Hand &h)
{
    if (hands.contains(h.getHandId())) {
        return false;
    } else {
        hands[h.getHandId()] = h;
        return true;
    }
}

bool impl_t::deleteHand(const Hand &h)
{
    if (!hands.contains(h.getHandId())) {
        return false;
    } else {
        hands.erase(hands.find(h.getHandId()));
        return true;
    }
}

QMap<unsigned long, Hand> impl_t::getHands(unsigned long gameId)
{
    if (gameId == 0) return hands;

    QMap<unsigned long, Hand> result;

    for (const auto& i: hands) {
        if (i.getGameId() == gameId) {
            result[i.getHandId()] = i;
        }
    }

    return result;
}

QSet<QString> impl_t::getLimits()
{
    return limits;
}

void impl_t::saveGamesData(const QString& path)
{
    QFile file(path + gamesDataPath);
    file.open(QFile::WriteOnly);
    QDataStream ostream(&file);

    for (const auto& i : games) {
        ostream << i;
        //i.print();
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
        //i.print();
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
        //qDebug() << "Limit: " << i;
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
        ostream << i;
        //i.print();
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
        //i.print();
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
