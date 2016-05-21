import QtQuick 2.4

FocusScope {
    id: main
    implicitWidth: nConst.appWidth
    implicitHeight: nConst.appHeight
    focus: true

    property NumericConstants nConst: NumericConstants {}
    property ColorScheme cScheme: ColorScheme {}

    ScreenManager {
        id: mainScrMgr
        anchors.fill: parent
    }
}
