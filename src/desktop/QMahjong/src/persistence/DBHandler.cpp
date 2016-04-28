#include <QFile>
#include <QDebug>
#include <iostream>

#include "Game.cpp"
#include "Hand.cpp"
#include "User.cpp"
#include "Participant.cpp"
#include "Limit.cpp"
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
        for (const auto & i : p.GetUserId()){
            qDebug() << i;
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
{ load();
    impl->displayGame();
    impl->displayHand();
    impl->displayPart();
    impl->displayUser();

    impl->l.SetName("Green Dragon");

    impl->u.SetName("Name");
    impl->u.SetSurname("Surname");
    impl->u.SetLogin("Login");
    impl->u.SetPass("1111");
    impl->u.SetPhone("123 456 78");
    impl->u.SetEmail("e-mail@example.com");

    impl->g.SetGameId(0);
    impl->g.SetDate("12/12/2012");
    impl->g.SetWinner("Player 1");
    impl->g.SetScore(QVector<int>(4,0));

    impl->h.SetHandId(0);
    impl->h.SetGameId(0);
    impl->h.SetWind('E');
    impl->h.SetMahjong(0);
    impl->h.SetCombo(QVector<unsigned int>(4,0));
    impl->h.SetScore(QVector<int>(4,0));
    impl->h.SetLimit("Limit");

    impl->p.SetPartId(0);
    impl->p.SetGameId(0);
    impl->p.SetUserId(QVector<QString>(4,"Login"));

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
    QFile outputFile(QString::fromStdString(filepath));
    outputFile.open(QFile::WriteOnly);
    QDataStream outstream(&outputFile);
    outstream << impl->l;
    outstream << impl->u;
    outstream << impl->g;
    outstream << impl->h;
    outstream << impl->p;
    qDebug() << "Outstream:" << outstream; // для вывода инфо кьютовских данніх;
    outputFile.flush();
    outputFile.close();
}

void DBHandler::load(const std::string &filepath)
{
    QFile inputFile (QString::fromStdString(filepath));
    inputFile.open(QFile::ReadOnly);
    QDataStream inputStream (&inputFile);
    inputStream >> impl->l;
    inputStream >> impl->u;
    inputStream >> impl->g;
    inputStream >> impl->h;
    inputStream >> impl->p;

    qDebug() << "Limit name:" << impl->l.GetName().c_str();

    //User check
    qDebug() << "User:" << impl->u.GetSuper();
    qDebug() << "User:" << impl->u.GetLogin().c_str();
    qDebug() << "User:" << impl->u.GetPass().c_str();
    qDebug() << "User:" << impl->u.GetName().c_str();
    qDebug() << "User:" << impl->u.GetSurname().c_str();
    qDebug() << "User:" << impl->u.GetPhone().c_str();
    qDebug() << "User:" << impl->u.GetEmail().c_str();
    qDebug() << "User:" << impl->u.GetRang();

    //Game check:
    qDebug() << "Game:" << impl->g.GetGameId();
    qDebug() << "Game:" << impl->g.GetDate().c_str();
    qDebug() << "Game:" << impl->g.GetWinner().c_str();
    qDebug() << "Game:" << impl->g.GetScore();

    //Hand check:
    qDebug() << "Hand:" << impl->h.GetHandId();
    qDebug() << "Hand:" << impl->h.GetGameId();
    qDebug() << "Hand:" << impl->h.GetWind();
    qDebug() << "Hand:" << impl->h.GetMahjong();
    qDebug() << "Hand:" << impl->h.GetCombo();
    qDebug() << "Hand:" << impl->h.GetScore();
    qDebug() << "Hand:" << impl->h.GetLimit().c_str();

    //Participant check
    qDebug() << "Participant:" << impl->p.GetPartId();
    qDebug() << "Participant:" << impl->p.GetGameId();
    qDebug() << "Participant:" << impl->p.GetUserId();

    inputFile.close();
}

} //persistence
