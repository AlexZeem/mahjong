#include "../persistence/DBHandler.h"
#include "../persistence/User.h"
#include "Authorization.h"

#include <QDebug>

namespace cabinet {

Authorization::Authorization(QObject *parent)
    : QObject(parent)
{ }

Authorization::~Authorization()
{ }

void Authorization::validate(const QString &login, const QString &pass)
{
    qDebug() << "Validate" << login << pass;

    if (!login.isEmpty() && !pass.isEmpty()) {
        persistence::User u = persistence::DBHandler::instance()->selectUser(login);
        if (u.getPass() == pass) {
            emit validationSuccesfull();
        } else {
            emit validationFailed();
        }
    } else {
        emit validationFailed();
    }
}

} //cabinet
