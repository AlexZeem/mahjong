#include <QTime>
#include <QDebug>
#include "../../persistence/DBHandler.h"
#include "../../persistence/Hand.h"
#include "HandTableView.h"

namespace cabinet {

HandTableView::HandTableView(QObject *parent)
    : QAbstractTableModel(parent)
{
    QTime curr(QTime::currentTime());
    qsrand(curr.msecsSinceStartOfDay());
//    QMap<unsigned long, persistence::Hand> h = persistence::DBHandler::instance()->getHands();
//    for (const auto& i : h) {
//        hands.push_back(i);
//    }
}

HandTableView::~HandTableView()
{ }

int HandTableView::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 0;//listOfPairs.size();
}

int HandTableView::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 12;
}

QVariant HandTableView::data(const QModelIndex &index, int role) const
{
//    if (!index.isValid())
//        return QVariant();

//    if (index.row() >= listOfPairs.size() || index.row() < 0)
//        return QVariant();

//    if (role == Qt::DisplayRole) {
//        QPair<QString, QString> pair = listOfPairs.at(index.row());

//        if (index.column() == 0)
//            return pair.first;
//        else if (index.column() == 1)
//            return pair.second;
//    }
    return QVariant();
}

QVariant HandTableView::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Name");
        case 1:
            return tr("Address");
        default:
            return QVariant();
        }
    }
    return QVariant();
}

bool HandTableView::insertRows(int position, int rows, const QModelIndex &index)
{
//    Q_UNUSED(index);
//    beginInsertRows(QModelIndex(), position, position + rows - 1);

//    for (int row = 0; row < rows; ++row) {
//        QPair<QString, QString> pair(" ", " ");
//        listOfPairs.insert(position, pair);
//    }

//    endInsertRows();
    return true;
}

bool HandTableView::removeRows(int position, int rows, const QModelIndex &index)
{
//    Q_UNUSED(index);
//    beginRemoveRows(QModelIndex(), position, position + rows - 1);

//    for (int row = 0; row < rows; ++row) {
//        listOfPairs.removeAt(position);
//    }

//    endRemoveRows();
    return true;
}

void HandTableView::editItem(const QString &value, int row, int col, int role)
{

}

void HandTableView::addNew()
{

}

void HandTableView::deleteSelected(int index)
{

}

void HandTableView::updateHandsData(unsigned long gameId)
{

}

bool HandTableView::setData(const QModelIndex &index, const QVariant &value, int role)
{
//    if (index.isValid() && role == Qt::EditRole) {
//        int row = index.row();

//        QPair<QString, QString> p = listOfPairs.value(row);

//        if (index.column() == 0)
//            p.first = value.toString();
//        else if (index.column() == 1)
//            p.second = value.toString();
//        else
//            return false;

//        listOfPairs.replace(row, p);
//        emit(dataChanged(index, index));

//        return true;
//    }

    return false;
}


} //namespace cabinet


