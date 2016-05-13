import QtQuick 2.4

Item {
    id: control
    height: textItem.implicitHeight
    width: textItem.implicitWidth
    Text {
        id: textItem
        text: styleData.value
        anchors.fill: parent
        anchors.leftMargin: nConst.margin
        clip: true
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: styleData.selected ? cScheme.backgroung : cScheme.label
        font.pixelSize: nConst.labelSize
    }
}
