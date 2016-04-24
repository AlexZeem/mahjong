#pragma once

#include <vector>
#include <string>

namespace persistence {

class Hand
{
public:
    //конструктор который инициирует объект параметрами.
    Hand(unsigned long _h = 0, unsigned long _g = 0, char _w = 'E', unsigned int _m = 1,
         std::vector<unsigned int> _c = std::vector<unsigned int>(1,20), std::vector<int> _s = std::vector<int>(1,20),
         std::string _l = "none") :

        //Список инициируемых объектов:
        handId(_h),
        gameId(_g),
        wind(_w),
        mahjong(_m),
        combo(_c),
        score(_s),
        limit(_l)
    { }

    unsigned long GetHandId() {
        return handId;
    }

    void SetHandId(unsigned long hi) {
        handId = hi;
    }

    unsigned long GetGameId() {
        return gameId;
    }

    void SetGamaId(unsigned long gi){
        gameId = gi;
    }

    char GetWind() {
        return wind;
    }

    void SetChar(char w) {
        wind = w;
    }

    unsigned int GetMahjong() {
        return mahjong;
    }

    void SetMahjong(unsigned int m) {
        mahjong = m;
    }

    std::vector<unsigned int> GetCombo(){
        return combo;
    }

    void SetCombo(const std::vector<unsigned int>& c){
        combo = c;
    }

    std::vector<int> GetScore(){
        return score;
    }

    void SetScore(const std::vector<int>& s){
        score = s;
    }

    std::string GetLimit(){
        return limit;
    }

    void SetLimit(const std::string& l){
        limit = l;
    }

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
