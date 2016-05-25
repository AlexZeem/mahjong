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
    Q_PROPERTY(int bestMahjong READ bestMahjong NOTIFY bestMahjongChanged)
    Q_PROPERTY(int worstMahjong READ worstMahjong NOTIFY worstMahjongChanged)
    Q_PROPERTY(QString bestMDate READ bestMDate NOTIFY bestMDateChanged)
    Q_PROPERTY(QString worstMDate READ worstMDate NOTIFY worstMDateChanged)

 public:
    GameInfoMediator(QObject *parent = 0);
    int participatedIn () const;
    QString lastPlayed () const;
    int countMahjong () const;
    int bestMahjong () const;
    int worstMahjong() const;
    QString bestMDate () const;
    QString worstMDate() const;

 signals:
    void participationChanged();
    void participatedInChanged();
    void lastPlayedChanged();
    void countMahjongChanged();
    void bestMahjongChanged();
    void worstMahjongChanged();
    void bestMDateChanged();
    void worstMDateChanged();

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
