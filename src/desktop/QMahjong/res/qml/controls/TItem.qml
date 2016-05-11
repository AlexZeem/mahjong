import QtQuick 2.0

Item{
    id: root
    property bool focused: true
    property int borderWidth: nConst.borderWidth
    property int radius: nConst.cornerRadius

    Rectangle {
        id: background
        anchors.fill: parent
        //opacity: 0.2
        color: root.focused ? cScheme.itemBackgroungColor : cScheme.backgroungColor
        radius: root.radius
        border {
            width: root.focused ? root.borderWidth : 0
            color: cScheme.borderColor
        }
    }
}
