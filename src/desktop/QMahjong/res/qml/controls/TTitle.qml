import QtQuick 2.4

Item {
    id: control
    width: title.implicitWidth
    height: title.implicitHeight
    property alias text: title.text

    Text {
        id: title
        anchors.fill: parent
        clip: true
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        color: cScheme.title
        font {
            weight: Font.DemiBold
            pixelSize: nConst.titleSize
        }
    }
}
