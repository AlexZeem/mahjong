#include "GamesViewMediator.h"

namespace cabinet {

GamesViewMediator::GamesViewMediator(QObject *parent) : QObject(parent)
{ }

GamesViewMediator::~GamesViewMediator()
{ }

QObject *GamesViewMediator::gamesModel()
{
    return &_gamesModel;
}

} // namespace cabinet

