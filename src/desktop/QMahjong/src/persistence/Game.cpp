#include "Game.h"
#include <QString>
#include <QVector>

namespace persistence {

    Game::Game(unsigned long _id,
               std::string _d,
               std::string _w,
               QVector<int> _s):

        gameId(_id),
        date(_d),
        winner (_w),
        score(_s)
    { }

    unsigned long Game::GetGameId() {
        return gameId;
    }

    std::string Game::GetDate() {
        return date;
    }

    std::string Game::GetWinner () {
        return winner;
    }

    QVector<int> Game::GetScore() {
        return score;
    }

    void Game::SetGameId(unsigned long gi) {
        gameId = gi;
    }

    void Game::SetDate(const std::string& d) {
        date = d;
    }

    void Game::SetWinner(const std::string& w) {
        winner = w;
    }

    void Game::SetScore(const QVector<int>& s) {
        score = s;
    }

    QDataStream &operator>>(QDataStream &in, Game & g)
    {
        quint32 gid;
        in >> gid;
        g.SetGameId(gid);
        QString d, w;
        in >> d >> w;
        g.SetDate(d.toStdString());
        g.SetWinner(w.toStdString());
        QVector<int> v;
        in >> v;
        g.SetScore(v);
        return in;
    }

    QDataStream &operator<<(QDataStream &out, const Game & g)
    {
        out << (quint32)g.gameId;
        out << QString::fromStdString(g.date);
        out << QString::fromStdString(g.winner);
        out << (QVector<int>)g.score;
        return out;
    }

} //persistence
