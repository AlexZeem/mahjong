#include <QTime>
#include <QDebug>
#include "../../persistence/DBHandler.h"
#include "../../persistence/Game.h"
#include "GamesTableModel.h"

namespace cabinet {
const int GTABLE_COL_COUNTER = 6;

GamesTableModel::GamesTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    QTime curr(QTime::currentTime());
    qsrand(curr.msecsSinceStartOfDay());
    QMap<unsigned long, persistence::Game> g = persistence::DBHandler::instance()->getGames();
    for (const auto& i : g) {
        games.push_back(i);
    }
}

GamesTableModel::~GamesTableModel()
{ }

void GamesTableModel::addEntry()
{
    persistence::Game g(qrand());
    if (persistence::DBHandler::instance()->addGame(g)) {
        games.push_back(g);
        qDebug() << "[GamesTableModel][addEntry] item added";
        insertRows(games.size() - 1 , 1, QModelIndex());
    } else {
        qDebug() << "[GamesTableModel][addEntry] skipped (item exist)";
    }
}

void GamesTableModel::editEntry(const QString &value, int row, int col)
{
    setData(index(row, col, QModelIndex()), value, Qt::EditRole);
}

void GamesTableModel::removeEntry(int row)
{
    if (row < 0 || row >= rowCount()) {
        qDebug() << "[GamesTableModel][removeEntry]" << row << "invalid";
        return;
    }

    if (persistence::DBHandler::instance()->deleteGame(games[row])) {
        games.removeAt(row);
        removeRows(row, 1, QModelIndex());
        qDebug() << "[GamesTableModel][removeEntry] item deleted";
    } else {
        qDebug() << "[GamesTableModel][removeEntry] skipped";
    }
}

unsigned long GamesTableModel::gameId(int row) const
{
    if (row < 0 || row >= rowCount()) {
        qDebug() << "[GamesTableModel][gameId]" << row << "invalid";
        return 0;
    }

    return games[row].getGameId();
}

int GamesTableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return games.size();
}

int GamesTableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return GTABLE_COL_COUNTER;
}

QVariant GamesTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) return QVariant();
    if (index.row() >= games.size() || index.row() < 0) return QVariant();

    switch (role) {
    case DATE_ROLE:   return games[index.row()].getDate();
    case WINNER_ROLE: return games[index.row()].getWinner();
    case SCORE1_ROLE: return games[index.row()].getScore()[0];
    case SCORE2_ROLE: return games[index.row()].getScore()[1];
    case SCORE3_ROLE: return games[index.row()].getScore()[2];
    case SCORE4_ROLE: return games[index.row()].getScore()[3];
    default: return QVariant();
    }
}

QHash<int, QByteArray> GamesTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[DATE_ROLE]   = "date";
    roles[WINNER_ROLE] = "winner";
    roles[SCORE1_ROLE] = "score1";
    roles[SCORE2_ROLE] = "score2";
    roles[SCORE3_ROLE] = "score3";
    roles[SCORE4_ROLE] = "score4";
    return roles;
}

bool GamesTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {

        persistence::Game item = games[index.row()];
        QVector<int> score = games[index.row()].getScore();
        switch (index.column()) {
        case DATE_ROLE:   item.setDate(value.toString());                 break;
        case WINNER_ROLE: item.setWinner(value.toString());               break;
        case SCORE1_ROLE: score[0] = value.toInt(); item.setScore(score); break;
        case SCORE2_ROLE: score[1] = value.toInt(); item.setScore(score); break;
        case SCORE3_ROLE: score[2] = value.toInt(); item.setScore(score); break;
        case SCORE4_ROLE: score[3] = value.toInt(); item.setScore(score); break;
        default: return false;
        }

        if (persistence::DBHandler::instance()->updateGame(item)) {
            qDebug() << "[GamesTableModel][setData] item updated";
            games.replace(index.row(), item);
            emit(dataChanged(index, index));
            return true;
        } else {
            qDebug() << "[GamesTableModel][setData] item not updated";
            return false;
        }
    }

    return false;
}

bool GamesTableModel::insertRows(int position, int rows, const QModelIndex& index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    endInsertRows();
    return true;
}

bool GamesTableModel::removeRows(int position, int rows, const QModelIndex& index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);
    endRemoveRows();
    return true;
}

} //namespace cabinet

