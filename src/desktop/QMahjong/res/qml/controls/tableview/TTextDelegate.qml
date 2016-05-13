import QtQuick 2.0

Item {
    anchors.fill: parent
    Text {
        anchors.centerIn: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: styleData.selected ? cScheme.activeFocusTextColor : cScheme.textColor
        text: styleData.value
        font.pixelSize: nConst.textPixelSize
    }
}
