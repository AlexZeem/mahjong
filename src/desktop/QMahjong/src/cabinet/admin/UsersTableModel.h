#pragma once

#include <QAbstractTableModel>
#include <QVector>

namespace persistence {
class User;
}

namespace cabinet {

class UsersTableModel : public QAbstractTableModel
{
    Q_OBJECT

    enum Roles{
        LOGIN_ROLE,
        PASS_ROLE,
        NAME_ROLE,
        SURNAME_ROLE,
        PHONE_ROLE,
        EMAIL_ROLE,
        RANG_ROLE
    };

public:
    explicit UsersTableModel(QObject* parent = 0);
    ~UsersTableModel();

    Q_INVOKABLE void addEntry();
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
    QVector<persistence::User> users;
};

} //namespace cabinet
