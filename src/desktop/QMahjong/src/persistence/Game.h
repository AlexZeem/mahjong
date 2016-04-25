#pragma once
#include <vector>
#include <string>

// некоторео множество, создание для группировки неких идентификаторов.
namespace persistence {

class Game
{
public:
    //конструктор с умолчанием
    Game(unsigned long _id = 0, std::string _d = "12/12/2012", std::string _w = "Player 1", std::vector<int> _s = std::vector<int>(4,0));


    // геттеры
    unsigned long GetGameId();
    std::string GetDate();
    std::string GetWinner();
    std::vector<int> GetScore();

    //сеттеры
    void SetGameId(unsigned long);
    void SetDate (const std::string&);
    void SetWinner (const std::string&);
    void SetScore (const std::vector<int>&);

private:
    unsigned long gameId;
    std::string date;
    std::string winner;
    std::vector <int> score;

};

} //persistence
