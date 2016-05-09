#pragma once
#include <QObject>
#include "GamesTableModel.h"
#include "HandTableModel.h"

namespace cabinet {

class GamesViewMediator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* gamesModel READ gamesModel NOTIFY never)
    Q_PROPERTY(QObject* handsModel READ handsModel NOTIFY never)
    Q_PROPERTY(QStringList users READ users NOTIFY never)
    Q_PROPERTY(QStringList players READ players NOTIFY playersChanged)
    Q_PROPERTY(QStringList limits READ limits NOTIFY never)

public:
    explicit GamesViewMediator(QObject *parent = 0);
    virtual ~GamesViewMediator();

    QObject *gamesModel();
    QObject *handsModel();
    QStringList users() const;
    QStringList players() const;
    QStringList limits() const;

    Q_INVOKABLE void getPlayers(unsigned long gameId);
    Q_INVOKABLE void addPlayer(unsigned long gameId, const QString& login);
    Q_INVOKABLE void removePlayer(unsigned long gameId, int index);

signals:
    void never();
    void playersChanged();

private:
    GamesTableModel _gamesModel;
    HandTableModel  _handsModel;
    QStringList     _players;
};
} // namespace cabinet
