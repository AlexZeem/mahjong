#pragma once
#include <QString>
#include <QSet>
#include <QMap>

namespace persistence {

class Game;
class Hand;
class Participant;
class User;

struct impl_t
{
    impl_t();
    ~impl_t();

    User selectUser(const QString& login);
    bool updateUser(const User& u, const QString& login = "");
    bool addUser(const User& u);
    bool deleteUser(const User& u);
    QMap<QString, User> getUsers();

    bool updateGame(const Game& g);
    bool addGame(const Game& g);
    bool deleteGame(const Game& g);
    QMap<unsigned long, Game> getGames();

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

} //namespace persistence
