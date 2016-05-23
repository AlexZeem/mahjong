#include "GameInfoMediator.h"
#include "../persistence/DBHandler.h"
#include "../persistence/Participant.h"
#include "../persistence/Game.h"

void Quicksort(QVector <persistence::Game>);

namespace cabinet {
GameInfoMediator::GameInfoMediator(QObject *parent)
    :QObject(parent)
{
    QObject::connect(this, SIGNAL(participationChanged()), SIGNAL(participatedInChanged()));
    QObject::connect(this, SIGNAL(participationChanged()), SIGNAL(lastPlayedChanged()));
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



