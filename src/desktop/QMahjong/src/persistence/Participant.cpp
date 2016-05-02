#include <QDebug>
#include "Participant.h"

namespace persistence {

QDataStream &operator << (QDataStream &out, const Participant& obj)
{
    out << QString::number(obj.partId);
    out << QString::number(obj.gameId);
    for (const auto& i : obj.userId) {
        out << i;
    }
    return out;
}

QDataStream &operator >> (QDataStream &in, Participant& obj)
{
    QString temp;
    in >> temp;
    obj.partId = temp.toULong();
    in >> temp;
    obj.gameId = temp.toULong();
    for (auto& i : obj.userId) {
        in >> i;
    }
    return in;
}

Participant::Participant(unsigned long _pid,
                         unsigned long _gid,
                         QVector<QString> _uid)
    : partId(_pid)
    , gameId(_gid)
    , userId(_uid)
{ }

QVector<QString> Participant::getUserId() const
{
    return userId;
}

void Participant::setUserId(const QVector<QString> &value)
{
    if (value != userId) userId = value;
}

unsigned long Participant::getGameId() const
{
    return gameId;
}

void Participant::setGameId(unsigned long value)
{
    if (value != gameId) gameId = value;
}

unsigned long Participant::getPartId() const
{
    return partId;
}

void Participant::setPartId(unsigned long value)
{
    if (value != partId) partId = value;
}

void Participant::print() const
{
    qDebug() << "Participant id:" << partId;
    qDebug() << "Participant game id:" << gameId;
    qDebug() << "Participant user id:" << userId;
}

} // persistence
