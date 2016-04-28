#include "Participant.h"

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
    out << (quint32)p.partId;
    out << (quint32)p.gameId;
    out << (QVector<QString>)p.userId;
    return out;
}

QDataStream &operator>>(QDataStream &in, Participant &p)
{
    quint32 pi, gi;
    QVector<QString> ui;
    in >> pi >> gi >> ui;
    p.SetPartId(pi);
    p.SetGameId(gi);
    p.SetUserId(ui);
    return in;
}

} // persistence
