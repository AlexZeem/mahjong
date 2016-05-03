#include <QDebug>
#include "../persistence/DBHandler.h"
#include "../persistence/User.h"
#include "UsersViewModel.h"

namespace cabinet {

namespace helper
{
QVariantMap toMap(const persistence::User & item)
{
    QVariantMap result;
    result["rang"] = item.getRang();
    result["login"] = item.getLogin();
    result["pass"] = item.getPass();
    result["name"] = item.getName();
    result["surname"] = item.getSurname();
    result["phone"] = item.getPhone();
    result["email"] = item.getEmail();
    return result;
}

} //namespace helper

UsersViewModel::UsersViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    QMap<QString, persistence::User> u = persistence::DBHandler::instance()->getUsers();
    for (const auto& i : u) {
        if (i.getLogin() == "admin") continue;
        users.push_back(i);
    }
}

UsersViewModel::~UsersViewModel()
{ }

persistence::User UsersViewModel::getItem(int index) const
{
    if(index < 0 || index >= rowCount())
        return persistence::User();
    return users[index];
}

QVariant UsersViewModel::data(const QModelIndex &index, int role) const
{
    persistence::User item = getItem(index.row());
    switch (role) {
    case LOGIN_ROLE: return item.getLogin();
    case PASS_ROLE: return item.getPass();
    case NAME_ROLE: return item.getName();
    case SURNAME_ROLE: return item.getSurname();
    case PHONE_ROLE: return item.getPhone();
    case EMAIL_ROLE: return item.getEmail();
    case RANG_ROLE: return item.getRang();
    default: return helper::toMap(item);
    }
}

int UsersViewModel::rowCount(const QModelIndex &) const
{
    return users.size();
}

QHash<int, QByteArray> UsersViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[LOGIN_ROLE] = "login";
    roles[PASS_ROLE] = "pass";
    roles[NAME_ROLE] = "name";
    roles[SURNAME_ROLE] = "surname";
    roles[PHONE_ROLE] = "phone";
    roles[EMAIL_ROLE] = "email";
    roles[RANG_ROLE] = "rang";
    return roles;
}

void UsersViewModel::editItem(const QString& value, int row, int col, const QString &role)
{
    qDebug() << "editItem" << value << row << col << role;
    QString key = users[row].getLogin();
    if ("login" == role) {
        users[row].setLogin(value);
    } else if ("pass" == role) {
        users[row].setPass(value);
    } else if ("name" == role) {
        users[row].setName(value);
    } else if ("surname" == role) {
        users[row].setSurname(value);
    } else if ("phone" == role) {
        users[row].setPhone(value);
    } else if ("email" == role) {
        users[row].setEmail(value);
    } else if ("rang" == role) {
        users[row].setRang(value.toDouble());
    }

    qDebug() << "item" << (persistence::DBHandler::instance()->updateUser(users[row], "login" == role ? key : "") ? "updated" : "not updated");
}

void UsersViewModel::addNew()
{
    persistence::User u;
    if (persistence::DBHandler::instance()->addUser(u)) {
        beginInsertRows(QModelIndex(), users.size(), users.size());
        users.push_back(u);
        endInsertRows();
        qDebug() << "item added";
    } else {
        qDebug() << "item already added";
    }
}

void UsersViewModel::deleteSelected(int index)
{
    if (index < 0 || index > rowCount()) {
       qDebug() << "invalid index";
       return;
    }

    if (persistence::DBHandler::instance()->deleteUser(users[index])) {
        beginRemoveRows(QModelIndex(), index, index);
        users.removeAt(index);
        endRemoveRows();
        qDebug() << "item deleted";
    } else {
        qDebug() << "cannot delete item";
    }
}

} //namespace cabinet
