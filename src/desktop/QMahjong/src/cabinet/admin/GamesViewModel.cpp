#include <QDebug>
#include "../../persistence/DBHandler.h"
#include "../../persistence/Game.h"
#include "GamesViewModel.h"

namespace cabinet {

namespace helper
{
QVariantMap toMap(const persistence::Game & item)
{
    QVariantMap result;
    result["date"] = item.getDate();
    result["winner"] = item.getWinner();

    for (int i = 0; i < item.getScore().size(); ++i) {
        result["score" + QString::number(i)] = item.getScore()[i];
    }
    return result;
}

} //namespace helper

GamesViewModel::GamesViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    QMap<unsigned long, persistence::Game> g = persistence::DBHandler::instance()->getGames();
    for (const auto& i : g) {
        games.push_back(i);
    }
}

GamesViewModel::~GamesViewModel()
{ }

persistence::Game GamesViewModel::getItem(int index) const
{
    if(index < 0 || index >= rowCount())
        return persistence::Game();
    return games[index];
}

QVariant GamesViewModel::data(const QModelIndex &index, int role) const
{
    persistence::Game item = getItem(index.row());
    switch (role) {
    case DATE_ROLE: return item.getDate();
    case WINNER_ROLE: return item.getWinner();
    case SCORE1_ROLE: return item.getScore()[0];
    case SCORE2_ROLE: return item.getScore()[1];
    case SCORE3_ROLE: return item.getScore()[2];
    case SCORE4_ROLE: return item.getScore()[3];
    default: return helper::toMap(item);
    }
}

int GamesViewModel::rowCount(const QModelIndex &) const
{
    return games.size();
}

QHash<int, QByteArray> GamesViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[DATE_ROLE] = "date";
    roles[WINNER_ROLE] = "winner";
    roles[SCORE1_ROLE] = "score1";
    roles[SCORE2_ROLE] = "score2";
    roles[SCORE3_ROLE] = "score3";
    roles[SCORE4_ROLE] = "score4";
    return roles;
}

void GamesViewModel::editItem(const QString& value, int row, int col, const QString &role)
{
    qDebug() << "editItem" << value << row << col << role;
    if ("date" == role) {
        games[row].setDate(value);
    } else if ("winner" == role) {
        games[row].setWinner(value);
    } else if ("score1" == role) {
        QVector<int> temp = games[row].getScore();
        temp[0] = value.toInt();
        games[row].setScore(temp);
    } else if ("score2" == role) {
        QVector<int> temp = games[row].getScore();
        temp[1] = value.toInt();
        games[row].setScore(temp);
    } else if ("score3" == role) {
        QVector<int> temp = games[row].getScore();
        temp[2] = value.toInt();
        games[row].setScore(temp);
    } else if ("score4" == role) {
        QVector<int> temp = games[row].getScore();
        temp[3] = value.toInt();
        games[row].setScore(temp);
    }

    qDebug() << "item" << (persistence::DBHandler::instance()->updateGame(games[row]) ? "updated" : "not updated");
}

void GamesViewModel::addNew()
{
    persistence::Game g;
    if (persistence::DBHandler::instance()->addGame(g)) {
        beginInsertRows(QModelIndex(), games.size(), games.size());
        games.push_back(g);
        endInsertRows();
        qDebug() << "item added";
    } else {
        qDebug() << "item already added";
    }
}

void GamesViewModel::deleteSelected(int index)
{
    if (index < 0 || index > rowCount()) {
       qDebug() << "invalid index";
       return;
    }

    if (persistence::DBHandler::instance()->deleteGame(games[index])) {
        beginRemoveRows(QModelIndex(), index, index);
        games.removeAt(index);
        endRemoveRows();
        qDebug() << "item deleted";
    } else {
        qDebug() << "cannot delete item";
    }
}

} //namespace cabinet

