import QtQuick 2.4
import "cabinet"

FocusScope {
    id: main
    width: 640
    height: 480

    ScreenManager{
        id: mainScrMgr
        anchors.fill: parent

        state: "SIGNIN"
    }
}
