#pragma once

#include <string>
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
         std::string _l = "none");

    // getters;
    unsigned long GetHandId();
    unsigned long GetGameId();
    char GetWind();
    unsigned int GetMahjong();
    QVector<unsigned int> GetCombo();
    QVector<int> GetScore();
    std::string GetLimit();

    //setter;
    void SetHandId(unsigned long);
    void SetGameId(unsigned long);
    void SetWind(char);
    void SetMahjong(unsigned int);
    void SetCombo(const QVector<unsigned int>&);
    void SetScore(const QVector<int>&);
    void SetLimit(const std::string&);

    friend QDataStream &operator<< (QDataStream &out, const Hand&);
    friend QDataStream &operator>> (QDataStream &in, Hand);

private:
    unsigned long handId;
    unsigned long gameId;
    char wind;
    unsigned int mahjong;
    QVector <unsigned int> combo;
    QVector <int> score;
    std::string limit;

};

} //persistence
