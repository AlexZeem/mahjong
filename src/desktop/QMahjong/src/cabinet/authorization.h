#pragma once

#include <QObject>
#include <QString>

namespace cabinet {

class Authorization : public QObject
{
    Q_OBJECT

public:
    Authorization(QObject* parent = 0);
    virtual ~Authorization();

    Q_INVOKABLE void validate(const QString& login, const QString& pass);

signals:
    void validationFailed();
    void validationSuccesfull();
    void superUserSignIn();

private:
    Q_DISABLE_COPY(Authorization)
};

} //cabinet
