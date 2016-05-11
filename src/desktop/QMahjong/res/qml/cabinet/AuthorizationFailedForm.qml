import QtQuick 2.0
import mahjong.cabinet.authorization 1.0
import "../controls"

Item {
    id: root

    TItem {
        id: background
        focused: false
        anchors.fill: parent
        radius: 0
    }

    TItem {
        id: backgr
        anchors.centerIn: parent
        width: parent.width / 2
        height: parent.height / 2
    }

    TTitleText {
        id: header
        anchors.centerIn: parent
        text: qsTr("Authorization Failed")
    }

    TPromptText {
        id: prompt
        anchors {
            top: header.bottom
            right: header.right
        }
        promptText: {
            if (auth.error === Errors.FAILED_PASS) {
                return qsTr("incorrect password")
            } else if (auth.error === Errors.FAILED_NO_USER) {
                return qsTr("no such login")
            } else {
                return qsTr("sorry, something went wrong")
            }
        }
    }

    TButton {
        id: backBtn
        anchors {
            top: backgr.top
            right: backgr.right
            topMargin: nConst.margin
            rightMargin: nConst.margin
        }
        text: qsTr("Back")
        onClicked: {
            console.log("Back button clicked")
            fsmEvent.back()
        }
    }
}
