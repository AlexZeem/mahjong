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
    Q_PROPERTY(int countMahjong READ countMahjong NOTIFY countMahjongChanged)

 public:
    GameInfoMediator(QObject *parent = 0);
    int participatedIn () const;
    QString lastPlayed () const;
    int countMahjong () const;

 signals:
    void participationChanged();
    void participatedInChanged();
    void lastPlayedChanged();
    void countMahjongChanged();

 public slots:
    void setParticipation(QString login);

 private:

    enum Place{
        first,
        second,
        third,
        fourth};

    QVector <persistence::Participant> participated;
    QVector <persistence::Game> participatedGames;
    int mcount;
    int mbest;
    int mworst;
    QString mbestDate;
    QString mworstDate;
    struct userPlace {
        unsigned long gameId;
        Place place;
    };

}; // gameInfoMediator
} // cabinet
