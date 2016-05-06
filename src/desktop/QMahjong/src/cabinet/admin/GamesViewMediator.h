#pragma once
#include <QObject>
#include "GamesTableModel.h"

namespace cabinet {

class GamesViewMediator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* gamesModel READ gamesModel NOTIFY never)
    Q_PROPERTY(QStringList users READ users NOTIFY never)
    Q_PROPERTY(QStringList players READ players NOTIFY playersChanged)

public:
    explicit GamesViewMediator(QObject *parent = 0);
    virtual ~GamesViewMediator();

    QObject *gamesModel();
    QStringList users() const;
    QStringList players() const;

    Q_INVOKABLE void getPlayers(unsigned long gameId);
    Q_INVOKABLE void addPlayer(unsigned long gameId, const QString& login);

signals:
    void never();
    void playersChanged();

private:
    GamesTableModel _gamesModel;
    QStringList     _players;
};
} // namespace cabinet
