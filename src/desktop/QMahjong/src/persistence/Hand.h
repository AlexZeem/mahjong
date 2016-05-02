#pragma once

#include <QString>
#include <QVector>
#include <QDataStream>

namespace persistence {

class Hand
{
public:
    //конструктор который инициирует объект параметрами.
    Hand(unsigned long _h = 0,
         unsigned long _g = 0,
         char _w = 'E',
         unsigned int _m = 0,
         QVector<unsigned int> _c = QVector<unsigned int>(4,0),
         QVector<int> _s = QVector<int>(4,0),
         const QString& _l = "none");

    // getters;
    unsigned long GetHandId() const;
    unsigned long GetGameId() const;
    char GetWind() const;
    unsigned int GetMahjong() const;
    QVector<unsigned int> GetCombo() const;
    QVector<int> GetScore() const;
    QString GetLimit() const;

    //setter;
    void SetHandId(unsigned long value);
    void SetGameId(unsigned long value);
    void SetWind(char value);
    void SetMahjong(unsigned int value);
    void SetCombo(const QVector<unsigned int>& value);
    void SetScore(const QVector<int>& value);
    void SetLimit(const QString& value);

    friend QDataStream &operator<< (QDataStream &out, const Hand& hand);
    friend QDataStream &operator>> (QDataStream &in, Hand & hand);

private:
    unsigned long handId;
    unsigned long gameId;
    char wind;
    unsigned int mahjong;
    QVector <unsigned int> combo;
    QVector <int> score;
    QString limit;

};

} //persistence
