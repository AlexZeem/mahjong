#include "GameInfoMediator.h"
#include "../persistence/DBHandler.h"
#include "../persistence/Participant.h"

//void Quicksort(QVector <persistence::Participant>);

namespace cabinet {
GameInfoMediator::GameInfoMediator(QObject *parent)
    :QObject(parent)
{
    QObject::connect(this, SIGNAL(participationChanged()), SIGNAL(ParticipatedInChanged()));
}

int GameInfoMediator::ParticipatedIn() const
{
    return participated.size();
}

void GameInfoMediator::setParticipation(QString login)
{
    participated = persistence::DBHandler::instance()->getParticipant(login);
    if (! participated.isEmpty())
    {
        //Quicksort(participated);
    }
    emit participationChanged();
}

//void Quicksort (QVector <persistence::Participant> participated)
//{
//    QString medianaValued = participated[participated.size()/2].getGameId().getData();
//    int mediana = participated.size()/2;
//    int left = 0;
//    int right = participated.size()-1;
//    while(true){
//        if (participated[left].getGameId().getData() < participated[mediana].getData())
//        {left ++;}
//        if(participated[right].getData() > participated[mediana].getData())
//        {right--;}
//        if (left == right) break;
//        if (left < right){
//            participant[temp] = participant[left];
//            participant[left] = participant[right];
//            participant[right] = participant[temp];
//            if (left == mediana) {
//                mediana = right;
//            }
//            if (right == mediana) {
//                mediana = left;
//            }
//        }
//    } // end while
//} // end Quicksort

} // cabinet

