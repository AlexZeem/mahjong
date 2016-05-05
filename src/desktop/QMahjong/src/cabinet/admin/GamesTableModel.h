#pragma once

#include <QAbstractTableModel>
#include <QVector>

namespace persistence {
class Game;
}

namespace cabinet {

class GamesTableModel : public QAbstractTableModel
{
    Q_OBJECT

    enum Roles {
        DATE_ROLE,
        WINNER_ROLE,
        SCORE1_ROLE,
        SCORE2_ROLE,
        SCORE3_ROLE,
        SCORE4_ROLE
    };

public:
    explicit GamesTableModel(QObject *parent = 0);
    ~GamesTableModel();

    Q_INVOKABLE void addEntry();
    Q_INVOKABLE void editEntry(const QString &value, int row, int col);
    Q_INVOKABLE void removeEntry(int row);
    Q_INVOKABLE unsigned long gameId(int row) const;

protected:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;

private:
    QVector<persistence::Game> games;
};

} //namespace cabinet
