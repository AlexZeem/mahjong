#pragma once // предпроцессорная дериктива, контроль подключения исходника только 1 раз при компиляции
#include <vector>
#include <string>

// некоторео множество, создание для группировки неких идентификаторов.
namespace persistence {

class Game
{
public:
    Game(unsigned long _id = 0, std::string _d = "12/12/2012", std::string _w = "Player 1", std::vector<int> _s = std::vector<int>(4,0)):
        gameId(_id),
        date(_d),
        winner (_w),
        score(_s)
    { }

    unsigned long GetGameId() {
        return gameId;
    }

    void SetGameId (unsigned long gi) {
        gameId = gi;
    }

    std::string GetDate() {
        return date;
    }

    void SetDate (const std::string& d) {
        date = d;
    }

    std::string GetWinner () {
        return winner;
    }

    void SetWinner (const std::string& w) {
        winner = w;
    }

    std::vector<int> GetScore () {
        return score;
    }

    void SetScore (const std::vector<int>& s) {
        score = s;
    }

private:
    unsigned long gameId;
    std::string date;
    std::string winner;
    std::vector <int> score;

};

} //persistence
