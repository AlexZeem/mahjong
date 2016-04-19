import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    id: root

    UserInfo {
        id: userInfo
        width: 200
        anchors {
            top: parent.top
            left: parent.left
            bottom: parent.bottom
        }
    }

    GameInfo {
        id: gamesInfo
        width: 200
        height: 75
        anchors {
            top: parent.top
            left: userInfo.right
        }
    }

    MahjongInfo {
        id: mahjongsInfo
        width: 200
        height: 75
        anchors {
            top: gamesInfo.bottom
            left: userInfo.right
        }
    }

    LimitInfo {
        id: limitsInfo
        width: 200
        height: 200

        anchors {
            top: mahjongsInfo.bottom
            bottom: parent.bottom
            left: userInfo.right
        }
    }

    Rectangle {
        id: background
        color: "white"
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: mahjongsInfo.right
            right: parent.right
        }

        Button {
            id: button
            anchors {
                top: background.top
                right: background.right
                topMargin: 15
                rightMargin: 15
            }
            text: qsTr("Sign out")
            onClicked: {
                console.log("Sign out button clicked")
                fsmEvent.signOut()
            }
        }
    }
}
