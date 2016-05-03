#pragma once

#include <QAbstractListModel>
#include <QVector>

namespace persistence {
class User;
}

namespace cabinet {

class UsersViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Role { LOGIN_ROLE = Qt::UserRole + 1,
                PASS_ROLE,
                NAME_ROLE,
                SURNAME_ROLE,
                PHONE_ROLE,
                EMAIL_ROLE,
                RANG_ROLE};

    explicit UsersViewModel(QObject *parent = 0);
    ~UsersViewModel();

    persistence::User getItem(int index) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void editItem(const QString& value, int row, int col, const QString &role);
    Q_INVOKABLE void addNew();
    Q_INVOKABLE void deleteSelected(int index);

signals:

private slots:


private:
    QVector<persistence::User> users;
};

} //namespace cabinet
