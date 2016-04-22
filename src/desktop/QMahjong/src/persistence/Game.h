#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace persistence {

class Game
{
public:
    Game()
    { }

    Game(const unsigned long& _id) :
        gameId(_id)
    { }

    Game(const std::string& _d, const std::string& _w) :
        data(_d),
        winner (_w)
    { }

    Game(const std::vector<int>& _s) :
        score(_s)
    { }

private:
    unsigned long gameId;
    std::string data;
    std::string winner;
    std::vector <int> score;

};

} //persistence
