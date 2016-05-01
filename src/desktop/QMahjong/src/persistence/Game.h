#pragma once
#include <QString>
#include <QVector>
#include <QDataStream>

// некоторео множество, создание для группировки неких идентификаторов.
namespace persistence {

class Game
{
public:
    //конструктор с умолчанием
    Game(unsigned long _id = 0,
         const QString& _d = "12/12/2012",
         const QString& _w = "Player 1",
         QVector<int> _s = QVector<int>(4,0));

    unsigned long getGameId() const;
    void setGameId(unsigned long value);

    QString getDate() const;
    void setDate(const QString &value);

    QString getWinner() const;
    void setWinner(const QString &value);

    QVector<int> getScore() const;
    void setScore(const QVector<int> &value);

    friend QDataStream &operator << (QDataStream& out, const Game& obj);
    friend QDataStream &operator >> (QDataStream& in, Game& obj);

private:
    unsigned long gameId;
    QString date;
    QString winner;
    QVector<int> score;
};

} //persistence
