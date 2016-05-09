#include <QTime>
#include <QDebug>
#include "../../persistence/DBHandler.h"
#include "../../persistence/Hand.h"
#include "HandTableModel.h"

namespace cabinet {
const int HTABLE_COL_COUNTER = 14;

HandTableModel::HandTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    QTime curr(QTime::currentTime());
    qsrand(curr.msecsSinceStartOfDay());
}

HandTableModel::~HandTableModel()
{ }

void HandTableModel::setGame(unsigned long gameId)
{
    beginResetModel();
    hands.clear();

    QMap<unsigned long, persistence::Hand> h = persistence::DBHandler::instance()->getHands(gameId);
    for (const auto& i : h) {
        hands.push_back(i);
    }
    qDebug() << "[HandTableModel][setGame]" << gameId << hands.size();
    endResetModel();
}

void HandTableModel::addEntry(unsigned long gameId)
{
    persistence::Hand h(qrand()); qDebug() << "[HandTableModel][addEntry]"<<gameId;
    h.setGameId(gameId);
    if (persistence::DBHandler::instance()->addHand(h)) {
        hands.push_back(h);
        qDebug() << "[HandTableModel][addEntry] item added";
        insertRows(hands.size() - 1 , 1, QModelIndex());
    } else {
        qDebug() << "[HandTableModel][addEntry] skipped (item exist)";
    }
}

void HandTableModel::editEntry(const QString &value, int row, int col)
{
    setData(index(row, col, QModelIndex()), value, Qt::EditRole);
}

void HandTableModel::removeEntry(int row)
{
    if (row < 0 || row >= rowCount()) {
        qDebug() << "[HandTableModel][removeEntry]" << row << "invalid";
        return;
    }

    if (persistence::DBHandler::instance()->deleteHand(hands[row])) {
        hands.removeAt(row);
        removeRows(row, 1, QModelIndex());
        qDebug() << "[HandTableModel][removeEntry] item deleted";
    } else {
        qDebug() << "[HandTableModel][removeEntry] skipped";
    }
}

int HandTableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return hands.size();
}

int HandTableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return HTABLE_COL_COUNTER;
}

QVariant HandTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) return QVariant();
    if (index.row() >= hands.size() || index.row() < 0) return QVariant();

    switch (role) {
    case WIND_ROLE:            return QString(hands[index.row()].getWind());
    case PLAYER1_MAHJONG_ROLE: return (hands[index.row()].getMahjong() == 0) ? true : false;
    case PLAYER1_COMBO_ROLE:   return hands[index.row()].getCombo()[0];
    case PLAYER1_SCORE_ROLE:   return hands[index.row()].getScore()[0];
    case PLAYER2_MAHJONG_ROLE: return (hands[index.row()].getMahjong() == 1) ? true : false;
    case PLAYER2_COMBO_ROLE:   return hands[index.row()].getCombo()[1];
    case PLAYER2_SCORE_ROLE:   return hands[index.row()].getScore()[1];
    case PLAYER3_MAHJONG_ROLE: return (hands[index.row()].getMahjong() == 2) ? true : false;
    case PLAYER3_COMBO_ROLE:   return hands[index.row()].getCombo()[2];
    case PLAYER3_SCORE_ROLE:   return hands[index.row()].getScore()[2];
    case PLAYER4_MAHJONG_ROLE: return (hands[index.row()].getMahjong() == 3) ? true : false;
    case PLAYER4_COMBO_ROLE:   return hands[index.row()].getCombo()[3];
    case PLAYER4_SCORE_ROLE:   return hands[index.row()].getScore()[3];
    case LIMIT_ROLE:           return hands[index.row()].getLimit();
    default: return QVariant();
    }
}

QHash<int, QByteArray> HandTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[WIND_ROLE]            = "wind";
    roles[PLAYER1_MAHJONG_ROLE] = "mahjong1";
    roles[PLAYER1_COMBO_ROLE]   = "combo1";
    roles[PLAYER1_SCORE_ROLE]   = "score1";
    roles[PLAYER2_MAHJONG_ROLE] = "mahjong2";
    roles[PLAYER2_COMBO_ROLE]   = "combo2";
    roles[PLAYER2_SCORE_ROLE]   = "score2";
    roles[PLAYER3_MAHJONG_ROLE] = "mahjong3";
    roles[PLAYER3_COMBO_ROLE]   = "combo3";
    roles[PLAYER3_SCORE_ROLE]   = "score3";
    roles[PLAYER4_MAHJONG_ROLE] = "mahjong4";
    roles[PLAYER4_COMBO_ROLE]   = "combo4";
    roles[PLAYER4_SCORE_ROLE]   = "score4";
    roles[LIMIT_ROLE]           = "limit";
    return roles;
}

bool HandTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {

        persistence::Hand item = hands[index.row()];
        QVector<int> score = hands[index.row()].getScore();
        QVector<unsigned int> combo = hands[index.row()].getCombo();
        switch (index.column()) {
        case WIND_ROLE: {
            QString tmp = value.toString();
            if (!tmp.isEmpty()) item.setWind(tmp.toUtf8().at(tmp.length() - 1));
            break;
        }
        case PLAYER1_MAHJONG_ROLE: if (value.toBool()) item.setMahjong(0);         break;
        case PLAYER1_COMBO_ROLE:   combo[0] = value.toInt(); item.setCombo(combo); break;
        case PLAYER1_SCORE_ROLE:   score[0] = value.toInt(); item.setScore(score); break;
        case PLAYER2_MAHJONG_ROLE: if (value.toBool()) item.setMahjong(1);         break;
        case PLAYER2_COMBO_ROLE:   combo[1] = value.toInt(); item.setCombo(combo); break;
        case PLAYER2_SCORE_ROLE:   score[1] = value.toInt(); item.setScore(score); break;
        case PLAYER3_MAHJONG_ROLE: if (value.toBool()) item.setMahjong(2);         break;
        case PLAYER3_COMBO_ROLE:   combo[2] = value.toInt(); item.setCombo(combo); break;
        case PLAYER3_SCORE_ROLE:   score[2] = value.toInt(); item.setScore(score); break;
        case PLAYER4_MAHJONG_ROLE: if (value.toBool()) item.setMahjong(3);         break;
        case PLAYER4_COMBO_ROLE:   combo[3] = value.toInt(); item.setCombo(combo); break;
        case PLAYER4_SCORE_ROLE:   score[3] = value.toInt(); item.setScore(score); break;
        case LIMIT_ROLE:           item.setLimit(value.toString());                break;
        default: return false;
        }

        if (persistence::DBHandler::instance()->updateHand(item)) {
            qDebug() << "[HandTableModel][setData] item updated";
            hands.replace(index.row(), item);
            emit(dataChanged(index, index));
            return true;
        } else {
            qDebug() << "[HandTableModel][setData] item not updated";
            return false;
        }
    }

    return false;
}

bool HandTableModel::insertRows(int position, int rows, const QModelIndex& index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    endInsertRows();
    return true;
}

bool HandTableModel::removeRows(int position, int rows, const QModelIndex& index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);
    endRemoveRows();
    return true;
}

} //namespace cabinet


