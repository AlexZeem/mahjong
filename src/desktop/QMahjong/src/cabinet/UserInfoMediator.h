#pragma once
#include <QObject>

namespace cabinet {
class UserInfoMediator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY nicknameChanged)

public:
    UserInfoMediator(QObject *parent = 0);

    QString nickname() const;

signals: // сигнал для передачи данных в интерфейс.
   void nicknameChanged(QString nickname);

public slots: // слот для приема данных из интерфейса.
   void setNickname(QString nickname);

private:
    QString _nickname;
};

}//namespace cabinet

