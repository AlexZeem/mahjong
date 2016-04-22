#pragma once // предпроцессорная дериктива, контроль подключения исходника только 1 раз при компиляции
#include <vector>
#include <string>
#include <iostream>

// некоторео множество, создание для группировки неких идентификаторов.
namespace persistence {

class Game
{
public:
    Game() // конструктор по умолчанию
    { }

    Game(const unsigned long& _id) :
    /* конструктор который инициирует объект параметром _id
    (константа ссылки(переданный параметр не будет изменен)).
        // инициализируемый объект*/
        gameId(_id)
    { }

    Game(const std::string& _d, const std::string& _w) : // конструктор который инициирует объекты параметрами  _d, _w
        // инициализируемые объекты
        data(_d),
        winner (_w)
    { }

    Game(const std::vector<int>& _s) : // конструктор который инициирует объект параметром _s
        // инициализируемый объект
        score(_s)
    { }

private:
    unsigned long gameId;
    std::string data;
    std::string winner;
    std::vector <int> score;

};

} //persistence
