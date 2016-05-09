#include <QDebug>
#include "Hand.h"

namespace persistence{

QDataStream &operator << (QDataStream &out, const Hand& obj)
{
    out << QString::number(obj.handId);
    out << QString::number(obj.gameId);
    out << obj.wind;
    out << QString::number(obj.mahjong);
    for (const auto& i : obj.combo) {
        out << i;
    }
    for (const auto& i : obj.score) {
        out << i;
    }
    out << obj.limit;
    return out;
}

QDataStream &operator >> (QDataStream &in, Hand& obj)
{
    QString temp;
    in >> temp;
    obj.handId = temp.toULong();
    in >> temp;
    obj.gameId = temp.toULong();
    in >> obj.wind;
    in >> temp;
    obj.mahjong = temp.toInt();
    for (auto& i : obj.combo) {
        in >> i;
    }
    for (auto& i : obj.score) {
        in >> i;
    }
    in >> obj.limit;
    return in;
}

Hand::Hand(unsigned long _h,
           unsigned long _g,
           char _w,
           int _m,
           QVector<unsigned int> _c,
           QVector<int> _s,
           QString _l)
    : handId(_h)
    , gameId(_g)
    , wind(_w)
    , mahjong(_m)
    , combo(_c)
    , score(_s)
    , limit(_l)
{ }

unsigned long Hand::getHandId() const
{
    return handId;
}

void Hand::setHandId(unsigned long value)
{
    if (value != handId) handId = value;
}

unsigned long Hand::getGameId() const
{
    return gameId;
}

void Hand::setGameId(unsigned long value)
{
    if (value != gameId) gameId = value;
}

QChar Hand::getWind() const
{
    return wind;
}

void Hand::setWind(QChar value)
{
    if (value != wind) wind = value;
}

int Hand::getMahjong() const
{
    return mahjong;
}

void Hand::setMahjong(int value)
{
    if (value != mahjong) mahjong = value;
}

QVector<unsigned int> Hand::getCombo() const
{
    return combo;
}

void Hand::setCombo(const QVector<unsigned int> &value)
{
    if (value != combo) combo = value;
}

QVector<int> Hand::getScore() const
{
    return score;
}

void Hand::setScore(const QVector<int> &value)
{
    if (value != score) score = value;
}

QString Hand::getLimit() const
{
    return limit;
}

void Hand::setLimit(const QString &value)
{
    if (value != limit) limit = value;
}

void Hand::print() const
{
    qDebug() << "Hand id:" << handId;
    qDebug() << "Hand game id:" << gameId;
    qDebug() << "Hand wind:" << wind;
    qDebug() << "Hand mahjong:" << mahjong;
    qDebug() << "Hand combo:" << combo;
    qDebug() << "Hand score:" << score;
    qDebug() << "Hand limit:" << limit;
}

} // persistence
