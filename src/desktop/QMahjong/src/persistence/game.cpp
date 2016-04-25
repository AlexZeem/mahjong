#include "Game.h"

namespace persistence {

    Game::Game(unsigned long _id, std::string _d, std::string _w, std::vector<int> _s):
        gameId(_id),
        date(_d),
        winner (_w),
        score(_s)
    { }

    unsigned long Game::GetGameId() {
        return gameId;
    }

    void Game::SetGameId(unsigned long gi) {
        gameId = gi;
    }

    std::string Game::GetDate() {
        return date;
    }

    void Game::SetDate(const std::string& d) {
        date = d;
    }

    std::string Game::GetWinner () {
        return winner;
    }

    void Game::SetWinner(const std::string& w) {
        winner = w;
    }

    std::vector<int> Game::GetScore() {
        return score;
    }

    void Game::SetScore(const std::vector<int>& s) {
        score = s;
    }

} //persistence
