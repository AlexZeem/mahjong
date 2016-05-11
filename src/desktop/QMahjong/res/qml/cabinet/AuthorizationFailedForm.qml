import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import mahjong.cabinet.authorization 1.0

Item {
    id: root

    Rectangle {
        id: background
        anchors.fill: parent
        //opacity: 0.2
        color: cScheme.backgroungColor
    }

    Rectangle {
        id: backgr
        anchors.centerIn: parent
        width: parent.width / 2
        height: parent.height / 2
        color: cScheme.itemBackgroungColor
        radius: 5
        border {
            width: 3
            color: cScheme.borderColor
        }
    }

    Text {
        id: header
        anchors.centerIn: parent
        text: qsTr("Authorization Failed")
        font.pixelSize: 30
        color: cScheme.activeFocusTitleColor
    }

    Text {
        id: prompt
        anchors {
            top: header.bottom
            right: header.right
        }
        text: {
            var promptText = qsTr("* ")

            if (auth.error === Errors.FAILED_PASS) {
                promptText = promptText + qsTr("incorrect password")
            } else if (auth.error === Errors.FAILED_NO_USER) {
                promptText = promptText + qsTr("no such login")
            } else {
                promptText = promptText + qsTr("sorry, something went wrong")
            }

            return promptText
        }
        font.pixelSize: 10
        horizontalAlignment: Text.AlignRight
        color: cScheme.textColor
    }

    Button {
        id: backBtn

        anchors {
            top: backgr.top
            right: backgr.right
            topMargin: 15
            rightMargin: 15
        }

        style: ButtonStyle {
            background: Rectangle {
                id: styleRect
                implicitWidth: 75
                implicitHeight: 25
                radius: 5
                border {
                    width: 1
                    color: cScheme.borderColor
                }
            }
            label: Text {
                text: qsTr("Back")
                color: backBtn.pressed ? cScheme.activeFocusTextColor : cScheme.inactiveFocusTextColor
                font.pixelSize: 16
                horizontalAlignment: Text.AlignHCenter
            }
        }

        onClicked: {
            console.log("Back button clicked")
            fsmEvent.back()
        }
    }
}
