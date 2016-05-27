#include "GameInfoMediator.h"
#include "../persistence/DBHandler.h"
#include "../persistence/Participant.h"
#include "../persistence/Game.h"
#include "../persistence/User.h"
#include "../persistence/Hand.h"
#include <QDebug>
#include <QVariantMap>

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

int GameInfoMediator::bestMahjong() const
{
    return mbest;
}

int GameInfoMediator::worstMahjong() const
{
    return mworst;
}

QString GameInfoMediator::bestMDate() const
{
    return mbestDate;
}

QString GameInfoMediator::worstMDate() const
{
    return mworstDate;
}

int GameInfoMediator::countLimit() const
{
    return ul.size();
}

QVariantList GameInfoMediator::ulimit() const
{
    QVariantList result;
    for (auto &i : ul){
        QVariantMap temp;
        temp["name"] = i.limit;
        temp["date"] = i.date;
        result.push_back(temp);
    }
    return result;
}

void GameInfoMediator::setParticipation(QString login)
{
    participated = persistence::DBHandler::instance()->getParticipant(login);
    participatedGames.clear();

    for (auto & i : participated){
        i.getGameId();
        for(auto & j : persistence::DBHandler::instance()->getGames()){
            if(j.getGameId() == i.getGameId())
                participatedGames.push_back(j);
        }
    }

    if (! participatedGames.isEmpty()) {
        Quicksort(participatedGames);
    }

    // получим кол-во сыгранных маджонгов
    int count = 0;
    for (const auto & i : participatedGames){
        if (i.getWinner() == login){
            count++;
        }
        mcount = count;

        //заполним вектор структур, чтобы получить позицию нашего игрока в играх, где он выиграл маджонг
        QVector <userPlace> up;
        userPlace temp;
        for (const auto & j : participated){
            temp.gameId = j.getGameId();
            QVector<QString> tempUser = j.getUserId();
            if (tempUser[0] == login){
                temp.place = first;
            }
            if (tempUser[1] == login){
                temp.place = second;
            }
            if (tempUser[2] == login){
                temp.place = third;
            }
            if (tempUser[3] == login){
                temp.place = fourth;
            }

            up.push_back(temp);

            //получим лучший маджонг и его дату.
            int best = -10000;
            int worst = 10000;
            QString mdate;
            for (auto &k : persistence::DBHandler::instance()->getHands(j.getGameId())) {
                if (best < k.getScore()[temp.place]) {
                    best = k.getScore()[temp.place];
                    mdate = persistence::DBHandler::instance()->selectGame(temp.gameId).getDate();
                }
                mbest = best;
                mbestDate = mdate;

                if (worst > k.getScore()[temp.place]) {
                    worst = k.getScore()[temp.place];
                    mdate = persistence::DBHandler::instance()->selectGame(temp.gameId).getDate();
                }
                mworst = worst;
                mworstDate = mdate;

                // получим инфо по лимитам

                qDebug() << "1st condition:" << (i.getWinner() == login);
                qDebug() << "2nd condition:" << k.getLimit();
                if(i.getWinner() == login && !k.getLimit().isEmpty())
                {
                    userLimits templ;
                    templ.date = persistence::DBHandler::instance()->selectGame(temp.gameId).getDate();
                    for (auto & l : persistence::DBHandler::instance()->getHands(j.getGameId())){
                        templ.limit = l.getLimit();
                        qDebug() << "Temp limit" << templ.limit;
                    }
                    ul.push_back(templ);
                    emit ulimitChanged();
                }
            }
        }
    }

    qDebug() << "Mcount value:" << mcount; // test
    qDebug() << "Mbest:" << mbest; // test
    qDebug() << "MbestDate:" << mbestDate; // test
    qDebug() << "Mworst:" << mworst; // test
    qDebug() << "MworstDate:" << mworstDate; // test


    emit participationChanged();
}
} // cabinet

void Quicksort (QVector <persistence::Game> participatedGames)
{
    QString medianaValued = participatedGames[participatedGames.size()/2].getDate();
    int mediana = participatedGames.size()/2;
    int left = 0;
    int right = participatedGames.size()-1;

    while(true){
        if (participatedGames[left].getDate() < participatedGames[mediana].getDate())
        {left ++;}
        if(participatedGames[right].getDate() > participatedGames[mediana].getDate())
        {right--;}
        if (left == right) break;
        if (left < right){
            persistence::Game temp = participatedGames[left];
            participatedGames[left] = participatedGames[right];
            participatedGames[right] = temp;
            if (left == mediana) {
                mediana = right;
            }
            if (right == mediana) {
                mediana = left;
            }
        }
    } // end while
} // end Quicksort



