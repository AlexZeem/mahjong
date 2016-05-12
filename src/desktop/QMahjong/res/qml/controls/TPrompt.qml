import QtQuick 2.4

Item {
    id: control
    property alias text: prompt.text

    Text {
        id: prompt
        anchors.fill: parent
        clip: true
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        color: cScheme.prompt
        font {
            weight: Font.Light
            pixelSize: nConst.promptSize
        }
    }
}
