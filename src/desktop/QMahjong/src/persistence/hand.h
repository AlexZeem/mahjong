#pragma once
#include <string>
#include <iostream>

namespace persistence {

class Hand
{
public:
    Hand()
    { }

    Hand(const unsigned long& _h) :
        handId(_h)
    { }

    Hand(const unsigned long& _g) :
        gameId(_h)
    { }

    Hand(const unsigned long& _h) :
        handId(_h)
    { }

    Hand(const char& _w) :
        wind(_w)
    { }

    Hand(const unsigned int& _m) :
        mahjong(_m)
    { }

    Hand(const std::vector<uint>& _c) :
        combo(_c)
    { }

    Hand(const std::vector<int>& _s) :
        score(_s)
    { }

    Game(const std::string& _l) :
        limit(_l)
    { }

private:
    unsigned long handId;
    unsigned long gameId;
    char wind;
    unsigned int mahjong;
    std::vector <uint> combo;
    std::vector <uint> score;
    std::string limit;

};

} //persistence
