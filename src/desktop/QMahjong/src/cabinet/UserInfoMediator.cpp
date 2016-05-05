#include "UserInfoMediator.h"

namespace cabinet {

UserInfoMediator::UserInfoMediator(QObject *parent)
    :QObject(parent)
{}

QString UserInfoMediator::nickname() const
{
    return _nickname;
}

void UserInfoMediator::setNickname(QString nickname)
{
    if (_nickname == nickname)
            return;

    if (nickname != _nickname){
        _nickname = nickname;
        emit nicknameChanged(nickname);
    }
}
} // namespace cabinet
