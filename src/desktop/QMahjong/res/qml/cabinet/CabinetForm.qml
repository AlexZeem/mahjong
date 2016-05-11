import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import "../controls"

Item {
    id: root

    TItem {
        id: background
        focused: false
        anchors.fill: parent
        radius: 0
    }

    UserInfo {
        id: userInfo
        width: nConst.userInfoWidth
        anchors {
            margins: nConst.margin
            top: parent.top
            left: parent.left
            bottom: parent.bottom
        }
    }

    GameInfo {
        id: gamesInfo
        width: parent.width - button.width - userInfo.width - nConst.margin * 4
        height: nConst.gameInfoHeight
        anchors {
            margins: nConst.margin
            top: parent.top
            left: userInfo.right
        }
    }

    MahjongInfo {
        id: mahjongsInfo
        width: gamesInfo.width
        height: nConst.mahjongInfoHeight
        anchors {
            margins: nConst.margin
            top: gamesInfo.bottom
            left: userInfo.right
        }
    }

    LimitInfo {
        id: limitsInfo
        width: gamesInfo.width
        height: nConst.limitInfoHeight

        anchors {
            margins: nConst.margin
            top: mahjongsInfo.bottom
            bottom: parent.bottom
            left: userInfo.right
        }
    }

    TButton {
        id: button
        anchors {
            top: background.top
            right: background.right
            topMargin: nConst.margin
            rightMargin: nConst.margin
        }
        text: qsTr("Sign out")
        onClicked: {
            console.log("Sign out button clicked")
            fsmEvent.signOut()
        }
    }
}
