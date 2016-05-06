#include <QFile>
#include <QDebug>

#include "Game.h"
#include "Hand.h"
#include "User.h"
#include "Participant.h"
#include "DBImpl.h"
#include "DBHandler.h"

namespace persistence {

const QString rootDataPath         = "persistence.dat";

DBHandler::DBHandler()
    : impl(new impl_t())
{ load();

    /*impl->users.clear();
    User u1(true,"admin", "admin", "Admin", "Admin", "911", "admin@email.com", .0);
    impl->users[u1.getLogin()] = u1;*/

    /*impl->games.clear();
    Game g1(1,"02/05/2016","User", QVector<int>(4,678));
    impl->games[g1.getGameId()] = g1;*/

    impl->hands.clear();
    Hand h1(1, 1, 'E', 2, QVector<unsigned int>(4,6), QVector<int>(4,45), "none");
    impl->hands[h1.getHandId()] = h1;

    impl->limits.clear();
    impl->limits << "Green dragon";

    /*impl->participants.clear();
    Participant p1(1, 1, QVector<QString>(4,"q"));
    impl->participants[p1.getGameId()] = p1;*/
}

DBHandler::~DBHandler()
{ save(); }

User DBHandler::selectUser(const QString &login)
{
    return impl->selectUser(login);
}

bool DBHandler::updateUser(const User &u, const QString& login)
{
    return impl->updateUser(u, login);
}

bool DBHandler::addUser(const User &u)
{
    return impl->addUser(u);
}

bool DBHandler::deleteUser(const User &u)
{
    return impl->deleteUser(u);
}

QMap<QString, User> DBHandler::getUsers()
{
    return impl->getUsers();
}

bool DBHandler::updateGame(const Game &g)
{
    return impl->updateGame(g);
}

bool DBHandler::addGame(const Game &g)
{
    return impl->addGame(g);
}

bool DBHandler::deleteGame(const Game &g)
{
    return impl->deleteGame(g);
}

QMap<unsigned long, Game> DBHandler::getGames()
{
    return impl->getGames();
}

bool DBHandler::updateParticipant(const Participant &p)
{
    return impl->updateParticipant(p);
}

QVector<QString> DBHandler::getPlayers(unsigned long gameId)
{
    return impl->getPlayers(gameId);
}

DBHandler* DBHandler::instance()
{
    static DBHandler*  ptr = 0;
    if (!ptr)
        ptr = new DBHandler();

    return ptr;
}

void DBHandler::load(const QString& path)
{
    qDebug() << "-----LOAD";
    QFile file(path + rootDataPath);
    file.open(QFile::ReadOnly);
    QDataStream inputStream(&file);
    QString temp;
    inputStream >> impl->gamesDataPath >> temp;
    qDebug() << impl->gamesDataPath << temp.toInt();
    impl->loadGamesData(path, temp.toInt());
    inputStream >> impl->handsDataPath >> temp;
    qDebug() << impl->handsDataPath << temp.toInt();
    impl->loadHandsData(path, temp.toInt());
    inputStream >> impl->limitsDataPath >> temp;
    qDebug() << impl->limitsDataPath << temp.toInt();
    impl->loadLimitsData(path, temp.toInt());
    inputStream >> impl->participantsDataPath >> temp;
    qDebug() << impl->participantsDataPath << temp.toInt();
    impl->loadParticipantsData(path, temp.toInt());
    inputStream >> impl->usersDataPath >> temp;
    qDebug() << impl->usersDataPath << temp.toInt();
    impl->loadUsersData(path, temp.toInt());
    file.close();
}

void DBHandler::save(const QString& path)
{
    qDebug() << "-----SAVE";
    QFile file(path + rootDataPath);
    file.open(QFile::WriteOnly);
    QDataStream outStream(&file);

    qDebug() << "Games items:" << impl->games.size();
    outStream << QString("games.dat") << QString::number(impl->games.size());
    impl->saveGamesData(path);

    qDebug() << "Hans items: " << impl->hands.size();
    outStream << QString("hands.dat") << QString::number(impl->hands.size());
    impl->saveHandsData(path);

    qDebug() << "Limits items: " << impl->limits.size();
    outStream << QString("limits.dat") << QString::number(impl->limits.size());
    impl->saveLimitsData(path);

    qDebug() << "Participants items: " << impl->participants.size();
    outStream << QString("participants.dat") << QString::number(impl->participants.size());
    impl->saveParticipantsData(path);

    qDebug() << "Users items: " << impl->users.size();
    outStream << QString("users.dat") << QString::number(impl->users.size());
    impl->saveUsersData(path);

    file.flush();
    file.close();
}

} //persistence
