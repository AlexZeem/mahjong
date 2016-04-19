#include <QGuiApplication>
#include <QtQuick>
#ifdef __APPLE__
    #include "persistence/DBHandler.h"
#endif
#include "cabinet/Authorization.h"


int main(int argc, char *argv[])
{
    int result = 0;
    QGuiApplication guiApp(argc, argv);
    QQuickView view;

#ifdef __APPLE__
    persistence::DBHandler::instance();
#endif

    //object registration
    cabinet::Authorization auth;
    view.engine()->rootContext()->setContextProperty("auth", &auth);
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

    return result;
}
