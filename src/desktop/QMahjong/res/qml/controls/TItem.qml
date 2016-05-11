import QtQuick 2.0

Item{
    id: root
    property bool iActiveFocus: true
    property int iBorderWidth: 2

    Rectangle {
        id: background
        anchors.fill: parent
        //opacity: 0.2
        color: iActiveFocus ? cScheme.itemBackgroungColor : cScheme.backgroungColor
        radius: 5
        border {
            width: iActiveFocus ? iBorderWidth : 0
            color: cScheme.borderColor
        }
    }
}
