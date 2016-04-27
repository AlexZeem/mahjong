#pragma once

#include <vector>
#include <string>

namespace persistence {

class Hand
{
public:
    //конструктор который инициирует объект параметрами.
    Hand(unsigned long _h = 0,
         unsigned long _g = 0,
         char _w = 'E',
         unsigned int _m = 1,
         std::vector<unsigned int> _c = std::vector<unsigned int>(4,0),
         std::vector<int> _s = std::vector<int>(4,0),
         std::string _l = "none");

    // getters;
    unsigned long GetHandId();
    unsigned long GetGameId();
    char GetWind();
    unsigned int GetMahjong();
    std::vector<unsigned int> GetCombo();
    std::vector<int> GetScore();
    std::string GetLimit();

    //setter;
    void SetHandId(unsigned long);
    void SetGamaId(unsigned long);
    void SetChar(char);
    void SetMahjong(unsigned int);
    void SetCombo(const std::vector<unsigned int>&);
    void SetScore(const std::vector<int>&);
    void SetLimit(const std::string&);

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
