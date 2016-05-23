#pragma once
#include <QObject>
#include "../persistence/Participant.h"
#include "../persistence/Game.h"

namespace cabinet {
class GameInfoMediator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int participatedIn READ participatedIn NOTIFY participatedInChanged)
    Q_PROPERTY(QString lastPlayed READ lastPlayed NOTIFY lastPlayedChanged)

 public:
    GameInfoMediator(QObject *parent = 0);
    int participatedIn () const;
    QString lastPlayed () const;

 signals:
    void participationChanged();
    void participatedInChanged();
    void lastPlayedChanged();

 public slots:
    void setParticipation(QString login);

 private:
    QVector <persistence::Participant> participated;
    QVector <persistence::Game> participatedGames;

}; // gameInfoMediator
} // cabinet
