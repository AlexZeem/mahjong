#include <QFile>
#include <QSet>
#include <QMap>
#include <QDebug>

#include "Game.h"
#include "Hand.h"
#include "User.h"
#include "Participant.h"
#include "DBHandler.h"

namespace persistence {

const QString rootDataPath         = "persistence.dat";

struct DBHandler::impl_t
{
    impl_t()
        : gamesDataPath("games.dat")
        , handsDataPath("hands.dat")
        , limitsDataPath("limits.dat")
        , usersDataPath("users.dat")
        , participantsDataPath("participants.dat")
    { }

    ~impl_t()
    { }

    void saveGamesData(const QString& path);
    void loadGamesData(const QString& path, unsigned int counter);
    void saveHandsData(const QString& path);
    void loadHandsData(const QString& path, unsigned int counter);
    void saveLimitsData(const QString& path);
    void loadLimitsData(const QString& path, unsigned int counter);
    void saveUsersData(const QString& path);
    void loadUsersData(const QString& path, unsigned int counter);
    void saveParticipantsData(const QString& path);
    void loadParticipantsData(const QString& path, unsigned int counter);

    QString gamesDataPath;
    QString handsDataPath;
    QString limitsDataPath;
    QString usersDataPath;
    QString participantsDataPath;
    QMap<unsigned long, Game> games;
    QMap<unsigned long, Hand> hands;
    QSet<QString> limits;
    QMap<QString, User> users;
    // key = game id
    QMap<unsigned long, Participant> participants;
};

DBHandler::DBHandler()
    : impl(new impl_t())
{ load(); }

DBHandler::~DBHandler()
{ save(); }

DBHandler* DBHandler::instance()
{
    static DBHandler*  ptr = 0;
    if (!ptr)
        ptr = new DBHandler();

    return ptr;
}

void DBHandler::load(const QString& path)
{
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
    inputStream >> impl->usersDataPath >> temp;
    qDebug() << impl->usersDataPath << temp.toInt();
    impl->loadUsersData(path, temp.toInt());
    inputStream >> impl->participantsDataPath >> temp;
    qDebug() << impl->participantsDataPath << temp.toInt();
    impl->loadParticipantsData(path, temp.toInt());
    file.close();
}

void DBHandler::save(const QString& path)
{
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
    impl->saveUsersData(path);

    qDebug() << "Users items: " << impl->users.size();
    outStream << QString("users.dat") << QString::number(impl->users.size());
    impl->saveParticipantsData(path);

    file.flush();
    file.close();
}

void DBHandler::impl_t::saveGamesData(const QString& path)
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

void DBHandler::impl_t::loadGamesData(const QString& path, unsigned int counter)
{
    QFile file(path + gamesDataPath);
    file.open(QFile::ReadOnly);
    QDataStream istream(&file);

    for (unsigned int i = 0; i < counter; ++i) {
        Game g;
        istream >> g;
        games[g.getGameId()] = g;
    }

    file.close();
}

void DBHandler::impl_t::saveHandsData(const QString& path)
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

void DBHandler::impl_t::loadHandsData(const QString& path, unsigned int counter)
{
    QFile file(path + handsDataPath);
    file.open(QFile::ReadOnly);
    QDataStream istream(&file);

    for (unsigned int i = 0; i < counter; ++i) {
        Hand h;
        istream >> h;
        hands[h.GetHandId()] = h;
    }

    file.close();
}

void DBHandler::impl_t::saveLimitsData(const QString& path)
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

void DBHandler::impl_t::loadLimitsData(const QString& path, unsigned int counter)
{
    QFile file(path + limitsDataPath);
    file.open(QFile::ReadOnly);
    QDataStream istream(&file);

    for (unsigned int i = 0; i < counter; ++i) {
        QString l;
        istream >> l;
        limits << l;
    }

    file.close();
}

void DBHandler::impl_t::saveUsersData(const QString& path)
{
    QFile file(path + usersDataPath);
    file.open(QFile::WriteOnly);
    QDataStream ostream(&file);

    for (const auto& i : users) {
        ostream << i;
    }

    file.flush();
    file.close();
}

void DBHandler::impl_t::loadUsersData(const QString& path, unsigned int counter)
{
    QFile file(path + usersDataPath);
    file.open(QFile::ReadOnly);
    QDataStream istream(&file);

    for (unsigned int i = 0; i < counter; ++i) {
        User u;
        istream >> u;
        users[u.GetLogin()] = u;
    }

    file.close();
}

void DBHandler::impl_t::saveParticipantsData(const QString& path)
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

void DBHandler::impl_t::loadParticipantsData(const QString& path, unsigned int counter)
{
    QFile file(path + participantsDataPath);
    file.open(QFile::ReadOnly);
    QDataStream istream(&file);

    for (unsigned int i = 0; i < counter; ++i) {
        Participant p;
        istream >> p;
        participants[p.GetGameId()] = p;
    }

    file.close();
}

} //persistence
