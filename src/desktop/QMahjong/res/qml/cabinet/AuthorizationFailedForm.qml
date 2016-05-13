import QtQuick 2.0
import mahjong.cabinet.authorization 1.0
import "../controls"

Item {
    id: root

    TBackgroundItem {
        id: background
        anchors.fill: parent
    }

    TItem {
        id: form
        anchors.centerIn: background
        width: parent.width / 2
        height: parent.height / 2
    }

    TTitle {
        id: header
        anchors.centerIn: parent
        text: qsTr("Authorization Failed")
    }

    TPrompt {
        id: prompt
        anchors {
            top: header.bottom
            right: header.right
        }
        text: {
            if (auth.error === Errors.FAILED_PASS) {
                return qsTr("* incorrect password")
            } else if (auth.error === Errors.FAILED_NO_USER) {
                return qsTr("* no such login")
            } else {
                return qsTr("* sorry, something went wrong")
            }
        }
    }

    TBackButton {
        id: backBtn
        anchors {
            top: form.top
            right: form.right
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
