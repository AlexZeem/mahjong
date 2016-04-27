#include "Limit.h"

namespace persistence {

Limit::Limit(const std::string& n):
    name(n)
{}

std::string Limit::GetName()
{
    return name;
}

void Limit::SetName(const std::string& n)
{
    name = n;
}

QDataStream &operator >>(QDataStream &in, Limit &l)
{
    QString str;
    in >> str;
    l.SetName(str.toStdString());
    return in;
}

QDataStream &operator <<(QDataStream &out, const Limit &l)
{
    out << QString::fromStdString(l.name); // convert string to QString;
    return out; //return after changes;
}


} // persistence
