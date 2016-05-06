#pragma once
#include <QObject>
#include "../persistence/User.h"

namespace cabinet {
class UserInfoMediator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY nicknameChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString surname READ surname WRITE setSurname NOTIFY surnameChanged)
    Q_PROPERTY(QString phone READ phone WRITE setPhone NOTIFY phoneChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(double rang READ rang WRITE setRang NOTIFY rangChanged)

public:
    UserInfoMediator(QObject *parent = 0);

    QString nickname() const;
    QString name()const;
    QString surname() const;
    QString phone() const;
    QString email() const;
    double rang() const;

signals: // сигнал для передачи данных в интерфейс.
   void nicknameChanged();
   void nameChanged();
   void surnameChanged();
   void phoneChanged();
   void emailChanged();
   void rangChanged();

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

