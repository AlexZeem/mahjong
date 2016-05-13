import QtQuick 2.4

Item {
    id: control
    property alias text: label.text
    property alias font: label.font
    width: label.implicitWidth
    height: label.implicitHeight

    Text {
        id: label
        anchors.fill: parent
        clip: true
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: cScheme.label
        font.pixelSize: nConst.labelSize
    }
}
