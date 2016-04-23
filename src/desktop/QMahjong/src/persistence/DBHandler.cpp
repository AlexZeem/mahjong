#include <fstream>
#include <iostream>

#include "Game.h"
#include "Hand.h"
#include "Limit.h"
#include "User.h"
#include "Participant.h"
#include "DBHandler.h"

namespace persistence {

struct DBHandler::impl_t
{
    impl_t()
    { }

    ~impl_t()
    { }

    void display() {
        std::cout << "Game ID:" << g.GetGameId() << std::endl;
        std::cout << "Game date:" << g.GetDate() << std::endl;
        std::cout << "Game winner:" << g.GetWinner() << std::endl;
        std::cout << "Game score: ";
        for (const auto & i : g.GetScore()){
        std::cout << i << ",";
        }
        std::cout << std::endl;
    }

    Game g;
    Hand h;
    Limit l;
    User u;
    Participant p;

};

DBHandler::DBHandler()
    : impl(new impl_t())
{ //load();
    //impl->display();
}

DBHandler::~DBHandler()
{ save(); }

DBHandler* DBHandler::instance()
{
    static DBHandler*  ptr = 0;
    if (!ptr)
        ptr = new DBHandler();

    return ptr;
}

void DBHandler::save(const std::string &filepath)
{
    std::ofstream ofs(filepath);

}

void DBHandler::load(const std::string &filepath)
{
    std::ifstream ifs(filepath);

    // restore the schedule from the archive
    //ia >> s;
}



} //persistence
