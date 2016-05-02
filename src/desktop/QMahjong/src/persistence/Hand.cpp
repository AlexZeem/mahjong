#include "Hand.h"

namespace persistence{

Hand::Hand(unsigned long _h,
           unsigned long _g,
           char _w,
           unsigned int _m,
           QVector<unsigned int> _c,
           QVector<int> _s,
           const QString& _l):

    //Список инициируемых объектов:
    handId(_h),
    gameId(_g),
    wind(_w),
    mahjong(_m),
    combo(_c),
    score(_s),
    limit(_l)
{ }

//Getters:
unsigned long Hand::GetHandId() const
{
    return handId;
}

unsigned long Hand::GetGameId() const
{
    return gameId;
}

char Hand::GetWind() const
{
    return wind;
}

unsigned int Hand::GetMahjong() const
{
    return mahjong;
}

QVector<unsigned int> Hand::GetCombo() const
{
    return combo;
}

QVector<int> Hand::GetScore()const
{
    return score;
}

QString Hand::GetLimit() const
{
    return limit;
}

// Setters:
void Hand::SetHandId(unsigned long value)
{
    if (handId != value)handId = value;
}

void Hand::SetGameId(unsigned long value)
{
    if (gameId != value)gameId = value;
}

void Hand::SetWind(char value)
{
    if (wind != value) wind = value;
}

void Hand::SetMahjong(unsigned int value)
{
    if(mahjong != value) mahjong = value;
}

void Hand::SetCombo(const QVector<unsigned int> &value)
{
    combo = value;
}

void Hand::SetScore(const QVector<int> &value)
{
    score = value;
}

void Hand::SetLimit(const QString& value)
{
    if(limit != value) limit = value;
}

QDataStream & operator <<(QDataStream &out, const Hand & hand)
{
    out << QString::number(hand.GetGameId());
    out << QString::number(hand.GetHandId());
    out << (qint8)hand.GetWind();
    out << QString::number(hand.GetMahjong());
    for (const auto& c : hand.GetCombo()){
        out << c;
    };
    for (const auto& s : hand.GetScore()){
        out << s;
    };
    out << hand.GetLimit();
    return out;
}

QDataStream & operator >>(QDataStream &in, Hand & hand)
{
    QString h, g, m;
    qint8 w;
    in >> h >> g >> w >> m;
    hand.SetHandId(h.toULong());
    hand.SetGameId(g.toULong());
    hand.SetWind(w);
    hand.SetMahjong(m.toUInt());
    for (auto& c : hand.combo){
        in >> c;
    }
    for (auto& s : hand.score){
        in >> s;
    }
    in >> hand.limit;



    return in;
}


} // persistence
