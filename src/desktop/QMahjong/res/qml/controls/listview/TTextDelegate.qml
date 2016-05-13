import QtQuick 2.4

Component {
    Item {
        id: control
        width: nConst.listItemWidth
        height: nConst.listItemHeight
        Text {
            id: textItem
            text: modelData
            anchors.fill: parent
            anchors.leftMargin: nConst.margin
            clip: true
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            color: cScheme.label
            font.pixelSize: nConst.labelSize
        }

        MouseArea {
            anchors.fill: parent
            onClicked:  {
                list.currentIndex = index
            }
        }
    }
}
