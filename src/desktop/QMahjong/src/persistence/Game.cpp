#include "Game.h"
#include <QString>
#include <QVector>

namespace persistence {

QDataStream &operator << (QDataStream& out, const Game& obj)
{
    out << QString::number(obj.gameId);
    out << obj.date;
    out << obj.winner;
    for (const auto& i : obj.score) {
        out << i;
    }
    return out;
}

QDataStream &operator >> (QDataStream& in, Game& obj)
{
    QString temp;
    in >> temp;
    obj.gameId = temp.toULong();
    in >> obj.date;
    in >> obj.winner;
    for (auto& i : obj.score) {
        in >> i;
    }
    return in;
}

Game::Game(unsigned long _id,
           const QString &_d,
           const QString &_w,
           QVector<int> _s):

    gameId(_id),
    date(_d),
    winner (_w),
    score(_s)
{ }

unsigned long Game::getGameId() const
{
    return gameId;
}

void Game::setGameId(unsigned long value)
{
    if (value != gameId) gameId = value;
}

QString Game::getDate() const
{
    return date;
}

void Game::setDate(const QString &value)
{
    if (value != date) date = value;
}

QString Game::getWinner() const
{
    return winner;
}

void Game::setWinner(const QString &value)
{
    if (value != winner) winner = value;
}

QVector<int> Game::getScore() const
{
    return score;
}

void Game::setScore(const QVector<int> &value)
{
    if (value != score) score = value;
}

} //persistence
