#pragma once

#include <QString>
#include <QVector>
#include <QDataStream>

namespace persistence {

class Participant
{
public:
    Participant(unsigned long _pid = 0,
                unsigned long _gid = 0,
                QVector<QString> _uid = QVector<QString>(4,"Login"));
    //Getters:
    unsigned long GetPartId() const;
    unsigned long GetGameId() const;
    QVector <QString> GetUserId() const;

    //Setters:
    void SetPartId(unsigned long value);
    void SetGameId(unsigned long value);
    void SetUserId(const QVector<QString>& value);

    friend QDataStream & operator << (QDataStream &out, const Participant & part);
    friend QDataStream & operator >> (QDataStream &in, Participant& part);

private:
    unsigned long partId;
    unsigned long gameId;
    QVector <QString> userId;

};

} //persistence
