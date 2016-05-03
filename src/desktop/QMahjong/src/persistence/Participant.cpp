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
unsigned long Participant::GetPartId() const
{
    return partId;
}

unsigned long Participant::GetGameId() const
{
    return gameId;
}

QVector<QString> Participant::GetUserId() const
{
    return userId;
}

//Setters:
void Participant::SetPartId(unsigned long value)
{
    if(partId != value)partId = value;
}

void Participant::SetGameId(unsigned long value)
{
    if(gameId != value)gameId = value;
}

void Participant::SetUserId(const QVector<QString> &value)
{
            userId = value;
}

QDataStream &operator<<(QDataStream &out, const Participant &part)
{
    out << QString::number(part.GetPartId());
    out << QString::number(part.GetGameId());
    for (const auto & i : part.GetUserId()){
        out << i;
    }
    return out;
}

QDataStream & operator >> (QDataStream &in, Participant &part)
{
    QString p, g;
    in >> p >> g;
    part.SetGameId(g.toULong());
    part.SetPartId(p.toULong());
    for (auto i : part.userId) {
        in >> i;
    }
    return in;
}

} // persistence
