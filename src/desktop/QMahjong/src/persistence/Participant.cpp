#include "Participant.h"
#include <QDebug>

namespace persistence {
Participant::Participant(unsigned long _pid,
                         unsigned long _gid,
                         QVector<QString> _uid):
    partId(_pid),
    gameId(_gid),
    userId(_uid)
{ }

//Getters:
unsigned long Participant::GetPartId(){return partId;}
unsigned long Participant::GetGameId() {return gameId;}
QVector<QString> Participant::GetUserId() {return userId;}

//Setters:
void Participant::SetPartId(unsigned long pid){
    partId = pid;
}

void Participant::SetGameId(unsigned long gid) {
    gameId = gid;
}

void Participant::SetUserId(const QVector<QString> &uid){
    userId = uid;
}

QDataStream &operator<<(QDataStream &out, const Participant &p)
{
    out << (qint32)p.partId;


    for (const auto& i : p.userId) {
        out << i;
    }
    out << (qint32)p.gameId;

    return out;
}

QDataStream &operator>>(QDataStream &in, Participant &p)
{
    qint32 pi, gi;
    in >> pi;
    for (auto i : p.userId) {
        in >> i;
    }
    in >> gi;
    qDebug() << "jhgiygabf" << pi << gi;
    p.SetPartId(pi);
    p.SetGameId(gi);
    //p.partId = pi;
    //p.gameId = gi;



    return in;
}

} // persistence
