#include "Hand.h"

namespace persistence  {

Hand::Hand(unsigned long _h,
           unsigned long _g,
           char _w,
           unsigned int _m,
           std::vector<unsigned int> _c,
           std::vector<int> _s,
           std::string _l):

    //Список инициируемых объектов:
    handId(_h),
    gameId(_g),
    wind(_w),
    mahjong(_m),
    combo(_c),
    score(_s),
    limit(_l)
{ }

unsigned long Hand::GetHandId() {
    return handId;
}

void Hand::SetHandId(unsigned long hi) {
    handId = hi;
}

unsigned long Hand::GetGameId() {
    return gameId;
}

void Hand::SetGamaId(unsigned long gi){
    gameId = gi;
}

char Hand::GetWind() {
    return wind;
}

void Hand::SetChar(char w) {
    wind = w;
}

unsigned int Hand::GetMahjong() {
    return mahjong;
}

void Hand::SetMahjong(unsigned int m) {
    mahjong = m;
}

std::vector<unsigned int> Hand::GetCombo(){
    return combo;
}

void Hand::SetCombo(const std::vector<unsigned int>& c){
    combo = c;
}

std::vector<int> Hand::GetScore(){
    return score;
}

void Hand::SetScore(const std::vector<int>& s){
    score = s;
}

std::string Hand::GetLimit(){
    return limit;
}

void Hand::SetLimit(const std::string& l){
    limit = l;
}

} // persistence
