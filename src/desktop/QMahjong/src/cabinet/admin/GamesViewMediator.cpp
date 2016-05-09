#include <QTime>
#include <QDebug>
#include "../../persistence/DBHandler.h"
#include "../../persistence/Game.h"
#include "../../persistence/Participant.h"
#include "../../persistence/User.h"
#include "GamesViewMediator.h"

namespace cabinet {

GamesViewMediator::GamesViewMediator(QObject *parent) : QObject(parent)
{
    QTime curr(QTime::currentTime());
    qsrand(curr.msecsSinceStartOfDay());
}

GamesViewMediator::~GamesViewMediator()
{ }

void GamesViewMediator::getPlayers(unsigned long gameId)
{
    _players.clear();
    for (const auto& i : persistence::DBHandler::instance()->getPlayers(gameId)) {
        _players << i;
    }

    qDebug() << "[GamesViewMediator][players]" << gameId << "size =" << _players.size();
    emit playersChanged();
}

void GamesViewMediator::addPlayer(unsigned long gameId, const QString& login)
{
    qDebug() << "[GamesViewMediator][addPlayer]" << gameId << login;
    QVector<QString> pls = persistence::DBHandler::instance()->getPlayers(gameId);
    pls.append(login);
    persistence::Participant p(qrand(), gameId, pls);

    if (persistence::DBHandler::instance()->updateParticipant(p)) {
        _players.clear();
        for (const auto& i : pls) {
            _players << i;
        }
        emit playersChanged();
        qDebug() << "[GamesViewMediator][addPlayer] added";
    } else {
        qDebug() << "[GamesViewMediator][addPlayer] not added";
    }
}

void GamesViewMediator::removePlayer(unsigned long gameId, int index)
{
    QVector<QString> pls = persistence::DBHandler::instance()->getPlayers(gameId);
    if (index < 0 || index >= pls.size()) {
        qDebug() << "[GamesViewMediator][removePlayer]" << index << "invalid";
        return;
    }

    pls.removeAt(index);
    persistence::Participant p(qrand(), gameId, pls);

    if (persistence::DBHandler::instance()->updateParticipant(p)) {
        _players.clear();
        for (const auto& i : pls) {
            _players << i;
        }
        emit playersChanged();
        qDebug() << "[GamesViewMediator][removePlayer] removed";
    } else {
        qDebug() << "[GamesViewMediator][removePlayer] not removed";
    }
}

QObject *GamesViewMediator::gamesModel()
{
    return &_gamesModel;
}

QObject *GamesViewMediator::handsModel()
{
    return &_handsModel;
}

QStringList GamesViewMediator::users() const
{
    QStringList result;
    result << "";
    for (const auto& i : persistence::DBHandler::instance()->getUsers()) {
        if ("admin" == i.getLogin()) continue;
        result << i.getLogin();
    }

    return result;
}

QStringList GamesViewMediator::players() const
{
    return _players;
}

QStringList GamesViewMediator::limits() const
{
    QStringList result;
    for (const auto& i : persistence::DBHandler::instance()->getLimits()) {
        result << i;
    }
    return result;
}

} // namespace cabinet

