#include "Hand.h"
#include <QString>

namespace persistence{

Hand::Hand(unsigned long _h,
           unsigned long _g,
           char _w,
           unsigned int _m,
           QVector<unsigned int> _c,
           QVector<int> _s,
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

//Getters:
unsigned long Hand::GetHandId() {
    return handId;
}

unsigned long Hand::GetGameId() {
    return gameId;
}

char Hand::GetWind() {
    return wind;
}

unsigned int Hand::GetMahjong() {
    return mahjong;
}

QVector<unsigned int> Hand::GetCombo(){
    return combo;
}

QVector<int> Hand::GetScore(){
    return score;
}

std::string Hand::GetLimit(){
    return limit;
}

// Setters:
void Hand::SetHandId(unsigned long hi) {
    handId = hi;
}

void Hand::SetGameId(unsigned long gi){
    gameId = gi;
}

void Hand::SetWind(char w) {
    wind = w;
}

void Hand::SetMahjong(unsigned int m) {
    mahjong = m;
}

void Hand::SetCombo(const QVector<unsigned int> &c){
    combo = c;
}

void Hand::SetScore(const QVector<int> &s){
    score = s;
}

void Hand::SetLimit(const std::string& l){
    limit = l;
}

QDataStream & operator >>(QDataStream &in, Hand h)
{
    quint32 hid, gid;
    qint8 w;
    quint16 m;
    QVector<unsigned int> c;
    QVector<int> s;
    in >> hid >> gid >> w >> m >> c >> s;
    h.SetGameId(gid);
    h.SetHandId(hid);
    h.SetWind(w);
    h.SetMahjong(m);
    h.SetCombo(c);
    h.SetScore(s);
    return in;
}

QDataStream & operator <<(QDataStream &out, const Hand &h)
{
    out << (quint32)h.handId;
    out << (quint32)h.gameId;
    out << (qint8)h.wind;
    out << (quint16)h.mahjong;
    out << (QVector<unsigned int>)h.combo;
    out << (QVector<int>)h.score;
    out << QString::fromStdString(h.limit);
    return out;
}
} // persistence
