#include "Authorization.h"

#include <QDebug>

namespace cabinet {

Authorization::Authorization(QObject *parent)
    : QObject(parent)
{

}

Authorization::~Authorization()
{ }

void Authorization::validate(const QString &login, const QString &pass)
{
    qDebug() << "Validate" << login << pass;
    //TODO: make request to DB
    if (!login.isEmpty() && !pass.isEmpty() && login == pass ) {
        emit validationSuccesfull();
    } else {
        emit validationFailed();
    }
}

} //cabinet
