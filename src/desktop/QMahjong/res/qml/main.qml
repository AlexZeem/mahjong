import QtQuick 2.4
import "cabinet"

FocusScope {
    id: main
    width: 640
    height: 480

    /*ScreenManager{
        id: mainScrMgr
        anchors.fill: parent

        state: "SIGNIN"
    }*/

    // for testing Authorization Failed Form
    /*AuthorizationFailedForm {
        anchors.centerIn: main
    }*/

    // for testing Cabinet Form
    CabinetForm {
        anchors.centerIn: main
    }
}
