#pragma once
#include <QString>
#include <QDataStream>

namespace persistence {

class Limit
{
public:
    Limit(const QString& n = "Limit");

    //переопределим операторов ввода и вывода:
    friend QDataStream& operator <<(QDataStream& out,const Limit& limit);
    friend QDataStream& operator >>(QDataStream& in, Limit& limit);

    QString GetName();
    void SetName(const QString& value);

private:
    QString name;
};

} //persistence
