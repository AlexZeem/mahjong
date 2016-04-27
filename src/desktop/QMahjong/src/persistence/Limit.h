#pragma once
#include <string>
#include <QDataStream>

namespace persistence {

class Limit
{
public:
    Limit(const std::string& n = "Limit");

    //переопределим операторов ввода и вывода:
    friend QDataStream& operator <<(QDataStream& out,const Limit&);
    friend QDataStream& operator >>(QDataStream& in, Limit&);

    std::string GetName();
    void SetName(const std::string&);

private:
    std::string name;
};

} //persistence
