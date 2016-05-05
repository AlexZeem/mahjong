#include "../../persistence/DBHandler.h"
#include "../../persistence/Game.h"
#include "../../persistence/User.h"
#include "GamesViewMediator.h"

namespace cabinet {

GamesViewMediator::GamesViewMediator(QObject *parent) : QObject(parent)
{ }

GamesViewMediator::~GamesViewMediator()
{ }

QStringList GamesViewMediator::players(unsigned long gameId) const
{
    QStringList result;
    for (const auto& i : persistence::DBHandler::instance()->getPlayers(gameId)) {
        result << i;
    }

    if (result.empty()) {
        result << "";
        for (const auto& i : persistence::DBHandler::instance()->getUsers()) {
            if ("admin" == i.getLogin()) continue;
            result << i.getLogin();
        }
    }

    return result;
}

QObject *GamesViewMediator::gamesModel()
{
    return &_gamesModel;
}

} // namespace cabinet

