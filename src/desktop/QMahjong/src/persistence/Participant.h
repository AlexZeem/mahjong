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
    unsigned long GetPartId();
    unsigned long GetGameId();
    QVector <QString> GetUserId();

    //Setters:
    void SetPartId(unsigned long);
    void SetGameId(unsigned long);
    void SetUserId(const QVector<QString>&);

    friend QDataStream & operator << (QDataStream &out, const Participant &);
    friend QDataStream & operator >> (QDataStream &in, Participant&);

private:
    unsigned long partId;
    unsigned long gameId;
    QVector <QString> userId;

};

} //persistence
