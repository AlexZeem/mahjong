#include <QDebug>
#include "../../persistence/DBHandler.h"
#include "../../persistence/User.h"
#include "UsersTableModel.h"

namespace cabinet {

const int UTABLE_COL_COUNTER = 7;

UsersTableModel::UsersTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    QMap<QString, persistence::User> u = persistence::DBHandler::instance()->getUsers();
    for (const auto& i : u) {
        if (i.getLogin() == "admin") continue;
        users.push_back(i);
    }
}

UsersTableModel::~UsersTableModel()
{ }

void UsersTableModel::addEntry()
{
    persistence::User u;
    if (persistence::DBHandler::instance()->addUser(u)) {
        users.push_back(u);
        qDebug() << "[addEntry] item added";
        insertRows(users.size() -1 , 1, QModelIndex());
    } else {
        qDebug() << "[addEntry] skipped (item exist)";
    }
}

void UsersTableModel::editEntry(const QString& value, int row, int col)
{
    setData(index(row, col, QModelIndex()), value, Qt::EditRole);
}

void UsersTableModel::removeEntry(int row)
{
    if (row < 0 || row >= rowCount()) {
        qDebug() << "[removeEntry]" << row << "invalid";
        return;
    }

    if (persistence::DBHandler::instance()->deleteUser(users[ row])) {
        users.removeAt(row);
        removeRows(row, 1, QModelIndex());
        qDebug() << "[removeEntry] item deleted";
    } else {
        qDebug() << "[removeEntry] skipped";
    }

    qDebug() << "[rowCount]" << rowCount();
}

int UsersTableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return users.size();
}

int UsersTableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return UTABLE_COL_COUNTER;
}

QVariant UsersTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) return QVariant();
    if (index.row() >= users.size() || index.row() < 0) return QVariant();

    persistence::User item = users[index.row()];
    switch (role) {
    case LOGIN_ROLE:   return item.getLogin();
    case PASS_ROLE:    return item.getPass();
    case NAME_ROLE:    return item.getName();
    case SURNAME_ROLE: return item.getSurname();
    case PHONE_ROLE:   return item.getPhone();
    case EMAIL_ROLE:   return item.getEmail();
    case RANG_ROLE:    return item.getRang();
    default: return QVariant();
    }
}

QHash<int, QByteArray> UsersTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[LOGIN_ROLE]   = "login";
    roles[PASS_ROLE]    = "pass";
    roles[NAME_ROLE]    = "name";
    roles[SURNAME_ROLE] = "surname";
    roles[PHONE_ROLE]   = "phone";
    roles[EMAIL_ROLE]   = "email";
    roles[RANG_ROLE]    = "rang";
    return roles;
}

bool UsersTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {

        persistence::User item = users[index.row()];
        switch (index.column()) {
        case LOGIN_ROLE:   item.setLogin(value.toString());   break;
        case PASS_ROLE:    item.setPass(value.toString());    break;
        case NAME_ROLE:    item.setName(value.toString());    break;
        case SURNAME_ROLE: item.setSurname(value.toString()); break;
        case PHONE_ROLE:   item.setPhone(value.toString());   break;
        case EMAIL_ROLE:   item.setEmail(value.toString());   break;
        case RANG_ROLE:    item.setRang(value.toDouble());    break;
        default: return false;
        }

        if (persistence::DBHandler::instance()->updateUser(item, users[index.row()].getLogin())) {
            qDebug() << "[setData] item updated";
            users.replace(index.row(), item);
            emit(dataChanged(index, index));
            return true;
        } else {
            qDebug() << "[setData] item not updated";
            return false;
        }
    }

    return false;
}

bool UsersTableModel::insertRows(int position, int rows, const QModelIndex& index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    endInsertRows();
    return true;
}

bool UsersTableModel::removeRows(int position, int rows, const QModelIndex& index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);
    endRemoveRows();
    return true;
}

} //namespace cabinet
