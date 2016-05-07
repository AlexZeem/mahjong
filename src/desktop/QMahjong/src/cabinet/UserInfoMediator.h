#pragma once
#include <QObject>
#include "../persistence/User.h"

namespace cabinet {
class UserInfoMediator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY userChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY userChanged)
    Q_PROPERTY(QString surname READ surname WRITE setSurname NOTIFY userChanged)
    Q_PROPERTY(QString phone READ phone WRITE setPhone NOTIFY userChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY userChanged)
    Q_PROPERTY(double rang READ rang WRITE setRang NOTIFY userChanged)

public:
    UserInfoMediator(QObject *parent = 0);

    QString nickname() const;
    QString name()const;
    QString surname() const;
    QString phone() const;
    QString email() const;
    double rang() const;

signals: // сигнал для передачи данных в интерфейс.
   void userChanged();

public slots: // слот для приема данных из интерфейса.
   void setNickname(QString nickname);
   void setName(QString name);
   void setSurname(QString surname);
   void setPhone (QString phone);
   void setEmail(QString email);
   void setRang(double rang);
   void setUser (QString login);

private:
 persistence::User currentUser;
};

}//namespace cabinet

