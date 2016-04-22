#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace persistence {

class Hand
{
public:
    Hand()
    { }

    Hand(const unsigned long& _h, const unsigned long& _g) :
        handId(_h),
        gameId(_g)
    { }

    Hand(const char& _w) :
        wind(_w)
    { }

    Hand(const unsigned int& _m) :
        mahjong(_m)
    { }

    Hand(const std::vector<unsigned int>& _c) :
        combo(_c)
    { }

    Hand(const std::vector<int>& _s) :
        score(_s)
    { }

    Hand(const std::string& _l) :
        limit(_l)
    { }

private:
    unsigned long handId;
    unsigned long gameId;
    char wind;
    unsigned int mahjong;
    std::vector <unsigned int> combo;
    std::vector <int> score;
    std::string limit;

};

} //persistence
