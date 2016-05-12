import QtQuick 2.4

Item{
    id: control
    property alias border: background.border
    property alias radius: background.radius
    property alias backgroundOpacity: background.opacity

    Rectangle {
        id: background
        anchors.fill: parent
        opacity: 1
        color: cScheme.backgroungItem
        radius: 0
        border {
            width: 0
            color: cScheme.border
        }
    }
}
