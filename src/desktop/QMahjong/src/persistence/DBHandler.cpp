#include <fstream>
#include <iostream>

#include "Game.cpp"
#include "Hand.cpp"
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

    // game.h test
    void displayGame() {
        std::cout << "Game ID:" << g.GetGameId() << std::endl;
        std::cout << "Game date:" << g.GetDate() << std::endl;
        std::cout << "Game winner:" << g.GetWinner() << std::endl;
        std::cout << "Game score: ";
        for (const auto & i : g.GetScore()){
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }

    // hand.h test
    void displayHand() {
        std::cout << "Hand ID:" << h.GetHandId() << std::endl;
        std::cout << "Game ID:" << h.GetGameId() << std::endl;
        std::cout << "Wind: " << h.GetWind() << std::endl;
        std::cout << "Mahjong:" << h.GetMahjong() << std::endl;
        std::cout << "Combo:";
        for (const auto & i : h.GetCombo()){
            std::cout << i << ",";
        }
        std::cout << std::endl;
        std::cout << "Score:";
        for (const auto & i : h.GetScore()){
            std::cout << i << ",";
        }
        std::cout << std::endl;
        std::cout << "Limit:" << h.GetLimit() << std::endl;

    }

    //participant.h test
    void displayPart() {
        std::cout << "Part ID:" << p.GetPartId() << std::endl;
        std::cout << "Game ID:" << p.GetGameId() << std::endl;
        std::cout << "UserId:";
        for (const auto & i : p.GetUsedId()){
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }

    // user.h test
    void displayUser() {
        std::cout << "Super user:" << u.GetSuper() << std::endl;
        std::cout << "Login:" << u.GetLogin() << std::endl;
        std::cout << "Password:" << u.GetPass() << std::endl;
        std::cout << "Name:" << u.GetName() << std::endl;
        std::cout << "Surname:" << u.GetSurname() << std::endl;
        std::cout << "Phone:" << u.GetPhone() << std::endl;
        std::cout << "Email:" << u.GetEmail() << std::endl;
        std::cout << "Rang:" << u.GetRang() << std::endl;
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
    impl->displayGame();
    impl->displayHand();
    impl->displayPart();
    impl->displayUser();
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
