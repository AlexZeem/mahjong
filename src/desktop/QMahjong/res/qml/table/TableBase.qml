import QtQuick 2.4

Item {
    id: root

    width: 360
    height: 360

    Image {
        id: table
        anchors.fill: root
        fillMode: Image.PreserveAspectFit
        source: "qrc:///res/icons/table/background.png"
    }

}
