#pragma once

#include <QAbstractTableModel>
#include <QVector>

namespace persistence {
class Hand;
}

namespace cabinet {

class HandTableView : public QAbstractTableModel
{   Q_OBJECT

public:
    explicit HandTableView(QObject *parent=0);
    ~HandTableView();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());

    Q_INVOKABLE void editItem(const QString& value, int row, int col, int role);
    Q_INVOKABLE void addNew();
    Q_INVOKABLE void deleteSelected(int index);
    Q_INVOKABLE void updateHandsData(unsigned long gameId = 0);

private:
    QVector<persistence::Hand> hands;
};

} //namespace cabinet
