#pragma once

#include <QObject>
#include <QString>

namespace cabinet {

class Authorization : public QObject
{
    Q_OBJECT

    Q_PROPERTY(FailCodes error READ error WRITE setError NOTIFY errorChanged)

public:
    enum FailCodes {
        FAILED_OK = 0,
        FAILED_NO_USER,
        FAILED_PASS
    };

    Q_ENUM(FailCodes)

public:
    Authorization(QObject* parent = 0);
    virtual ~Authorization();

    FailCodes error() const;

    Q_INVOKABLE void validate(const QString& login, const QString& pass);

signals:
    void validationFailed(FailCodes);
    void validationSuccesfull(QString);
    void superUserSignIn();
    void errorChanged();

private slots:
    void setError(FailCodes e);

private:
    Q_DISABLE_COPY(Authorization)
    FailCodes _error;
};

} //cabinet
