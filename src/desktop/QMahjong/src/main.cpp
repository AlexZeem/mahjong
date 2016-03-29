#include <QGuiApplication>
#include <QtQuick>

int main(int argc, char *argv[])
{
    QGuiApplication guiApp(argc, argv);

    QQuickView view;

    //for transparency
    QQuickWindow::setDefaultAlphaBuffer(true);
    view.setColor(Qt::transparent);
    //------------

    view.setSource(QUrl(QStringLiteral("res/qml/main.qml")));

    view.setPosition(0,0);
    view.show();
    view.raise();

    return guiApp.exec();
}
