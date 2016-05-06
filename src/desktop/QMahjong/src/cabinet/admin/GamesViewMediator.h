#pragma once
#include <QObject>
#include "GamesTableModel.h"

namespace cabinet {

class GamesViewMediator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* gamesModel READ gamesModel NOTIFY never)

public:
    explicit GamesViewMediator(QObject *parent = 0);
    virtual ~GamesViewMediator();

    Q_INVOKABLE QStringList players(unsigned long gameId, bool all = false) const;

    QObject *gamesModel();

signals:
    void never();

private:
    GamesTableModel _gamesModel;
};
} // namespace cabinet
