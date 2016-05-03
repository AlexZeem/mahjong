#pragma once
#include <memory>
#include <QString>
#include <QMap>

namespace persistence {

struct impl_t;
class Game;
class Hand;
class Participant;
class User;

class DBHandler
{
    std::unique_ptr<impl_t> impl;

    DBHandler();
    ~DBHandler();

public:
    User selectUser(const QString& login);
    bool updateUser(const User& u, const QString& login = "");
    bool addUser(const User& u);
    bool deleteUser(const User& u);
    QMap<QString, User> getUsers();

    bool updateGame(const Game& g);
    bool addGame(const Game& g);
    bool deleteGame(const Game& g);
    QMap<unsigned long, Game> getGames();

    QVector<QString> getPlayers(unsigned long gameId);

public:
    static DBHandler* instance();

    void load(const QString& path = default_path());
    void save(const QString& path = default_path());

    static QString default_path() { return "persistence/"; }

    // delete copy and move constructors and assign operators
    DBHandler(DBHandler const&) = delete;             // Copy construct
    DBHandler(DBHandler&&) = delete;                  // Move construct
    DBHandler& operator=(DBHandler const&) = delete;  // Copy assign
    DBHandler& operator=(DBHandler &&) = delete;      // Move assign
};

} //persistence
