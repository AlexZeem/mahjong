#include <QGuiApplication>
#include <QtQuick>
#include "cabinet/Authorization.h"
#include "cabinet/admin/UsersTableModel.h"
#include "cabinet/admin/GamesViewMediator.h"
#include "cabinet/UserInfoMediator.h"
#include "persistence/DBHandler.h"
#include "cabinet/GameInfoMediator.h"

int main(int argc, char *argv[])
{
    int result = 0;
    QGuiApplication guiApp(argc, argv);
    QQuickView view;
    persistence::DBHandler::instance();

    //object registration
    cabinet::Authorization auth;
    cabinet::UserInfoMediator userMediator;
    cabinet::UsersTableModel usersModel;
    cabinet::GamesViewMediator gameMediator;
    cabinet::GameInfoMediator gameInfoMediator;

    //Connect:
    QObject::connect(&auth, SIGNAL(validationSuccesfull(QString)), &userMediator, SLOT(setUser(QString)));
    QObject::connect(&auth, SIGNAL(validationSuccesfull(QString)), &gameInfoMediator, SLOT(setParticipation(QString)));

    view.engine()->rootContext()->setContextProperty("auth", &auth);
    view.engine()->rootContext()->setContextProperty("users", &usersModel);
    view.engine()->rootContext()->setContextProperty("gmediator", &gameMediator);
    view.engine()->rootContext()->setContextProperty("umediator", &userMediator);
    view.engine()->rootContext()->setContextProperty("ginfomediator", &gameInfoMediator);

    qmlRegisterType<cabinet::Authorization>("mahjong.cabinet.authorization", 1, 0, "Errors");
    //


    //for transparency
    QQuickWindow::setDefaultAlphaBuffer(true);
    view.setColor(Qt::transparent);
    //------------

    view.setSource(QUrl(QStringLiteral("res/qml/main.qml")));
    view.setPosition(0,0);
    view.show();
    view.raise();

    result = guiApp.exec();
    persistence::DBHandler::instance()->save();

    return result;
}
