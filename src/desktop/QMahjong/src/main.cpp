#include <QGuiApplication>
#include <QtQuick>
#include "cabinet/Authorization.h"

int main(int argc, char *argv[])
{
    int result = 0;
    QGuiApplication guiApp(argc, argv);
    QQuickView view;

    //for transparency
    QQuickWindow::setDefaultAlphaBuffer(true);
    view.setColor(Qt::transparent);
    //------------

    view.setSource(QUrl(QStringLiteral("res/qml/main.qml")));

    //object registration
    cabinet::Authorization auth;
    view.engine()->rootContext()->setContextProperty("auth", &auth);
    //

    view.setPosition(0,0);
    view.show();
    view.raise();

    result = guiApp.exec();

    return result;
}
