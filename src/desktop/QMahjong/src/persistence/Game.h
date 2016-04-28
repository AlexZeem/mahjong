#pragma once
#include <string>
#include <QDataStream>
#include <QVector>

// некоторео множество, создание для группировки неких идентификаторов.
namespace persistence {

class Game
{
public:
    //конструктор с умолчанием
    Game(unsigned long _id = 0,
         std::string _d = "12/12/2012",
         std::string _w = "Player 1",
         QVector<int> _s = QVector<int>(4,0));


    // геттеры
    unsigned long GetGameId();
    std::string GetDate();
    std::string GetWinner();
    QVector<int> GetScore();

    //сеттеры
    void SetGameId(unsigned long);
    void SetDate (const std::string&);
    void SetWinner (const std::string&);
    void SetScore (const QVector<int>&);

    friend QDataStream &operator << (QDataStream& out, const Game&);
    friend QDataStream &operator >> (QDataStream& in, Game&);

private:
    unsigned long gameId;
    std::string date;
    std::string winner;
    QVector<qint32> score;

};

} //persistence
