#pragma once
#include <QObject>
#include "GamesViewModel.h"

namespace cabinet {

class GamesViewMediator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* gamesModel READ gamesModel NOTIFY never)
public:
    explicit GamesViewMediator(QObject *parent = 0);
    virtual ~GamesViewMediator();

    QObject *gamesModel();

signals:
    void never();

private:
    GamesViewModel _gamesModel;
};
} // namespace cabinet
