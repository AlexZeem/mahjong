#pragma once

#include <QAbstractListModel>
#include <QVector>

namespace persistence {
class Game;
}

namespace cabinet {

class GamesViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Role { DATE_ROLE = Qt::UserRole + 1,
                WINNER_ROLE,
                SCORE1_ROLE,
                SCORE2_ROLE,
                SCORE3_ROLE,
                SCORE4_ROLE};

    explicit GamesViewModel(QObject *parent = 0);
    ~GamesViewModel();

    persistence::Game getItem(int index) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void editItem(const QString& value, int row, int col, const QString &role);
    Q_INVOKABLE void addNew();
    Q_INVOKABLE void deleteSelected(int index);

private:
    QVector<persistence::Game> games;
};

} //namespace cabinet
