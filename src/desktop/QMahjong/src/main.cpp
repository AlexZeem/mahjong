#include <QGuiApplication>
#include <QtQuick>
#include "cabinet/Authorization.h"
#include "cabinet/admin/UsersViewModel.h"
#include "cabinet/admin/GamesViewMediator.h"
#include "cabinet/UserInfoMediator.h"
#include "persistence/DBHandler.h"

int main(int argc, char *argv[])
{
    int result = 0;
    QGuiApplication guiApp(argc, argv);
    QQuickView view;
    persistence::DBHandler::instance();

    //object registration
    cabinet::Authorization auth;
    cabinet::UserInfoMediator userMediator;
    //Connect:
    QObject::connect(&auth, SIGNAL(validationSuccesfull(QString)), &userMediator, SLOT(setUser(QString)));

    view.engine()->rootContext()->setContextProperty("auth", &auth);
    cabinet::UsersViewModel usersModel;
    view.engine()->rootContext()->setContextProperty("umodel", &usersModel);
    cabinet::GamesViewMediator gameMediator;
    view.engine()->rootContext()->setContextProperty("gmediator", &gameMediator);

    view.engine()->rootContext()->setContextProperty("umediator", &userMediator);
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
