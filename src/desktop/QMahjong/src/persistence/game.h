#pragma once
#include <string>
#include <iostream>

namespace persistence {

class Game
{
public:
    Game()
    { }

    Game(const unsigned long& _id) :
        GameId(_id)
    { }

    Game(const std::string& _d) :
        data(_d)
    { }

    Game(const std::string& _w) :
        winner(_w)
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
