import QtQuick 2.0

Rectangle {
    property bool focused: true

    anchors.fill: parent
    color: focused ? cScheme.itemBackgroungColor : cScheme.backgroungColor
    radius: nConst.cornerRadius
    border {
        width: focused ? nConst.borderWidth : 0
        color: cScheme.borderColor
    }
}

