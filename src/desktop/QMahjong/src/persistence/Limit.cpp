#include "Limit.h"

namespace persistence {

Limit::Limit(const QString &n):
    name(n)
{}

QString Limit::GetName()
{
    return name;
}

void Limit::SetName(const QString &value)
{
    if (name != value)name = value;
}

QDataStream &operator <<(QDataStream &out, const Limit & limit)
{
    out << limit.name;
    return out; //return after changes;
}


QDataStream &operator >>(QDataStream &in, Limit & limit)
{
    in >> limit.name;
    return in;
}



} // persistence
