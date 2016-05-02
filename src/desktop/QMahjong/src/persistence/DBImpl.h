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
