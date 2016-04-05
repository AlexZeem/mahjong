import QtQuick 2.4

Item {
    id: root
    readonly property real tableWidth  : 600
    readonly property real tableHeight  : 600

    width: tableWidth
    height: tableHeight

    Image {
        id: table
        anchors.fill: root
        fillMode: Image.PreserveAspectFit
        source: "qrc:///res/icons/table/background.png"
    }
}
