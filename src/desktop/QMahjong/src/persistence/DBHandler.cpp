#include <QFile>
#include <QDebug>
#include <iostream>

#include "Game.h"
#include "Hand.h"
#include "User.h"
#include "Participant.h"
#include "Limit.h"
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
        qDebug() << "Game ID:" << g.getGameId();
        qDebug() << "Game date:" << g.getDate();
        qDebug() << "Game winner:" << g.getWinner();
        qDebug() << "Game score: ";
        for (const auto & i : g.getScore()){
            qDebug() << i << ",";
        }
    }

    // hand.h test
    void displayHand() {
       std::cout << "Hand ID:" << h.GetHandId() << std::endl;
        std::cout << "Game ID:" << h.GetGameId() << std::endl;
        std::cout << "Hand ID:" << h.GetWind() << std::endl;
        std::cout << "Hand ID:" << h.GetMahjong() << std::endl;
        qDebug() << "Hand ID:" << h.GetLimit();
        for (const auto & c : h.GetCombo()){
            qDebug() << c << ",";
        }
        for (const auto & s : h.GetScore()){
            qDebug() << s << ",";
        }
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
//    impl->displayGame();
//    impl->displayHand();
//    impl->displayPart();
//    impl->displayUser();

    impl->l.SetName("Green Dragon");

    impl->u.SetSuper(false);
    impl->u.SetName("Name");
    impl->u.SetSurname("Surname");
    impl->u.SetLogin("Login");
    impl->u.SetPass("1111");
    impl->u.SetPhone("123 456 78");
    impl->u.SetEmail("e-mail@example.com");
    impl->u.SetRang(.89);

    impl->g.setGameId(0);
    impl->g.setDate("12/12/2012");
    impl->g.setWinner("Player 1");
    impl->g.setScore(QVector<int>(4,7));

    impl->h.SetHandId(1);
    impl->h.SetGameId(2);
    impl->h.SetWind('W');
    impl->h.SetMahjong(3);
    impl->h.SetCombo(QVector<unsigned int>(4,6));
    impl->h.SetScore(QVector<int>(4,9));
    impl->h.SetLimit("Limit");

    impl->p.SetPartId(20);
    impl->p.SetGameId(10);
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

    qDebug() << "Limit name:" << impl->l.GetName();

    //User check
    qDebug() << "User super:" << impl->u.GetSuper();
    qDebug() << "User login:" << impl->u.GetLogin().c_str();
    qDebug() << "User pass:" << impl->u.GetPass().c_str();
    qDebug() << "User name:" << impl->u.GetName().c_str();
    qDebug() << "User surname:" << impl->u.GetSurname().c_str();
    qDebug() << "User phone:" << impl->u.GetPhone().c_str();
    qDebug() << "User email:" << impl->u.GetEmail().c_str();
    qDebug() << "User rang:" << impl->u.GetRang();

    //Game check:
    qDebug() << "Game id:" << impl->g.getGameId();
    qDebug() << "Game date:" << impl->g.getDate();
    qDebug() << "Game winner:" << impl->g.getWinner();
    qDebug() << "Game score:" << impl->g.getScore();

    //Hand check:
    qDebug() << "Hand id:" << impl->h.GetHandId();
    qDebug() << "Hand game id:" << impl->h.GetGameId();
    qDebug() << "Hand wind:" << impl->h.GetWind();
    qDebug() << "Hand mahjong:" << impl->h.GetMahjong();
    qDebug() << "Hand combo:" << impl->h.GetCombo();
    qDebug() << "Hand score:" << impl->h.GetScore();
    qDebug() << "Hand limit:" << impl->h.GetLimit();

    //Participant check
    qDebug() << "Participant id:" << impl->p.GetPartId();
    qDebug() << "Participant game id:" << impl->p.GetGameId();
    qDebug() << "Participant user id:" << impl->p.GetUserId();

    inputFile.close();
}

} //persistence
