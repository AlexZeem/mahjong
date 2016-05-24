#include "GameInfoMediator.h"
#include "../persistence/DBHandler.h"
#include "../persistence/Participant.h"
#include "../persistence/Game.h"
#include "../persistence/User.h"
#include <QDebug>

void Quicksort(QVector <persistence::Game>);

namespace cabinet {
GameInfoMediator::GameInfoMediator(QObject *parent)
    :QObject(parent)
{
    //    QObject::connect(this, SIGNAL(participationChanged()), SIGNAL(participatedInChanged()));
    //    QObject::connect(this, SIGNAL(participationChanged()), SIGNAL(lastPlayedChanged()));
    //    QObject::connect(this, SIGNAL(participationChanged()), SIGNAL(countMahjongChanged()));
}

int GameInfoMediator::participatedIn() const
{
    return participated.size();
}

QString GameInfoMediator::lastPlayed() const
{
    if (! participatedGames.isEmpty()) return participatedGames.last().getDate();
    else return " ";
}

int GameInfoMediator::countMahjong() const
{
    return mcount;
}

void GameInfoMediator::setParticipation(QString login)
{
    participated = persistence::DBHandler::instance()->getParticipant(login);
    if (! participated.isEmpty()) {
        for (auto & i : participated){
            i.getGameId();
            for(auto & j : persistence::DBHandler::instance()->getGames()){
                if(j.getGameId() == i.getGameId())
                    participatedGames.push_back(j);
            }
        }
        Quicksort(participatedGames);
    }

    // получим кол-во сыгранных маджонгов
    int count = 0;
    for (const auto & i : participatedGames){
        if (i.getWinner() == persistence::DBHandler::instance()->selectUser(login).getLogin()){
            count++;
        }
        mcount = count;
        //qDebug() << "Mcount value:" << mcount; // test
    }

    //заполним вектор структур, чтобы получить позицию нашего игрока в играх, где он выиграл маджонг
    QVector <userPlace> up;
    userPlace temp;
    for (const auto & j : participated){
        temp.gameId = j.getGameId();
        qDebug() << "Temp gameId:" << temp.gameId;
        QVector<QString> tempUser = j.getUserId();
        for (auto & t : tempUser) {
            if (tempUser[0] == persistence::DBHandler::instance()->selectUser(login).getLogin()){
                temp.place = first;
            }
            if (tempUser[1] == persistence::DBHandler::instance()->selectUser(login).getLogin()){
                temp.place = second;
            }
            if (tempUser[2] == persistence::DBHandler::instance()->selectUser(login).getLogin()){
                temp.place = third;
            }
            if (tempUser[3] == persistence::DBHandler::instance()->selectUser(login).getLogin()){
                temp.place = fourth;
            }
        }
        qDebug() << "Place:" << temp.place;
        up.push_back(temp);
    }
    emit participationChanged();
}
} // cabinet

void Quicksort (QVector <persistence::Game> participatedGames)
{
    QString medianaValued = participatedGames[participatedGames.size()/2].getDate();
    int mediana = participatedGames.size()/2;
    int left = 0;
    int right = participatedGames.size()-1;
    int temp;
    while(true){
        if (participatedGames[left].getDate() < participatedGames[mediana].getDate())
        {left ++;}
        if(participatedGames[right].getDate() > participatedGames[mediana].getDate())
        {right--;}
        if (left == right) break;
        if (left < right){
            participatedGames[temp] = participatedGames[left];
            participatedGames[left] = participatedGames[right];
            participatedGames[right] = participatedGames[temp];
            if (left == mediana) {
                mediana = right;
            }
            if (right == mediana) {
                mediana = left;
            }
        }
    } // end while
} // end Quicksort



