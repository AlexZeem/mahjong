#pragma once

#include <QString>
#include <QVector>
#include <QDataStream>

namespace persistence {

class Hand
{
public:
    friend QDataStream &operator << (QDataStream &out, const Hand& obj);
    friend QDataStream &operator >> (QDataStream &in, Hand& obj);

    Hand(unsigned long _h = 0,
         unsigned long _g = 0,
         char _w = 'E',
         int _m = 0,
         QVector<unsigned int> _c = QVector<unsigned int>(4,0),
         QVector<int> _s = QVector<int>(4,0),
         QString _l = "none");

    unsigned long getHandId() const;
    void setHandId(unsigned long value);

    unsigned long getGameId() const;
    void setGameId(unsigned long value);

    char getWind() const;
    void setWind(char value);

    int getMahjong() const;
    void setMahjong(int value);

    QVector<unsigned int> getCombo() const;
    void setCombo(const QVector<unsigned int> &value);

    QVector<int> getScore() const;
    void setScore(const QVector<int> &value);

    QString getLimit() const;
    void setLimit(const QString &value);

private:
    unsigned long handId;
    unsigned long gameId;
    char wind;
    int mahjong;
    QVector<unsigned int> combo;
    QVector<int> score;
    QString limit;
};

} //persistence
