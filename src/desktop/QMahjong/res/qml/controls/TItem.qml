import QtQuick 2.4

Item{
    id: control
    property alias border: background.border
    property alias radius: background.radius
    property alias backgroundOpacity: background.opacity
    property alias color: background.color

    Rectangle {
        id: background
        anchors.fill: parent
        opacity: 1
        color: cScheme.backgroung
        radius: nConst.radius
        border {
            width: nConst.borderWidth
            color: cScheme.border
        }
    }
}
