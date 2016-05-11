#include "../persistence/DBHandler.h"
#include "../persistence/User.h"
#include "Authorization.h"

#include <QDebug>

namespace cabinet {

Authorization::Authorization(QObject *parent)
    : QObject(parent)
    , _error(FAILED_OK)
{
    QObject::connect(this, SIGNAL(validationFailed(FailCodes)),
                           SLOT(setError(FailCodes)));
}

Authorization::~Authorization()
{ }

Authorization::FailCodes Authorization::error() const
{
    return _error;
}

void Authorization::validate(const QString &login, const QString &pass)
{
    qDebug() << "Validate" << login << pass;

    if (!login.isEmpty() && !pass.isEmpty()) {
        persistence::User u = persistence::DBHandler::instance()->selectUser(login);
        if (login != u.getLogin()) {
            emit validationFailed(FAILED_NO_USER);
            return;
        }

        if (u.getPass() == pass) {
            if (u.getSuper()) {
                emit superUserSignIn();
            } else {
                emit validationSuccesfull(login);
            }
            setError(FAILED_OK);
        } else {
            emit validationFailed(FAILED_PASS);
        }
    } else {
        emit validationFailed(FAILED_NO_USER);
    }
}

void Authorization::setError(Authorization::FailCodes e)
{
    if (e != _error) {
        _error = e;
        emit errorChanged();
    }
}

} //cabinet
