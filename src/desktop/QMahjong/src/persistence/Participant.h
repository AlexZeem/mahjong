#pragma once

#include <QString>
#include <QVector>
#include <QDataStream>

namespace persistence {

class Participant
{
public:
    friend QDataStream &operator << (QDataStream &out, const Participant& obj);
    friend QDataStream &operator >> (QDataStream &in, Participant& obj);

    Participant(unsigned long _pid = 0,
                unsigned long _gid = 0,
                QVector<QString> _uid = QVector<QString>(4,"Login"));

    QVector<QString> getUserId() const;
    void setUserId(const QVector<QString> &value);

    unsigned long getGameId() const;
    void setGameId(unsigned long value);

    unsigned long getPartId() const;
    void setPartId(unsigned long value);

    void print() const;

private:
    unsigned long partId;
    unsigned long gameId;
    QVector<QString> userId;
};

} //persistence
