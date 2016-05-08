#pragma once

#include <QAbstractTableModel>
#include <QVector>

namespace persistence {
class Hand;
}

namespace cabinet {

class HandTableModel : public QAbstractTableModel
{
    Q_OBJECT

    enum Roles {
        WIND_ROLE,
        PLAYER1_MAHJONG_ROLE,
        PLAYER1_COMBO_ROLE,
        PLAYER1_SCORE_ROLE,
        PLAYER2_MAHJONG_ROLE,
        PLAYER2_COMBO_ROLE,
        PLAYER2_SCORE_ROLE,
        PLAYER3_MAHJONG_ROLE,
        PLAYER3_COMBO_ROLE,
        PLAYER3_SCORE_ROLE,
        PLAYER4_MAHJONG_ROLE,
        PLAYER4_COMBO_ROLE,
        PLAYER4_SCORE_ROLE
    };

public:
    explicit HandTableModel(QObject *parent = 0);
    ~HandTableModel();

    Q_INVOKABLE void setGame(unsigned long gameId);
    Q_INVOKABLE void addEntry(unsigned long gameId);
    Q_INVOKABLE void editEntry(const QString &value, int row, int col);
    Q_INVOKABLE void removeEntry(int row);

protected:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;

private:
    QVector<persistence::Hand> hands;
};

} //namespace cabinet
