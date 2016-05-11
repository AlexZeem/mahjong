import QtQuick 2.0

Item{
    id: root
    property bool iActiveFocus: true
    property int iWidth: parent.width
    property int iHeight: parent.height
    property int iBorderWidth: 2

    Rectangle {
        id: background
        width: iWidth
        height: iHeight
        //opacity: 0.2
        color: iActiveFocus ? cScheme.itemBackgroungColor : cScheme.backgroungColor
        radius: 5
        border {
            width: iActiveFocus ? iBorderWidth : 0
            color: cScheme.borderColor
        }
    }
}
