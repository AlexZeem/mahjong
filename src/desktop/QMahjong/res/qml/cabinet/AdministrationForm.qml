import QtQuick 2.0
import QtQuick.Controls 1.3
import "admin"

Item {
    id: root

    Rectangle {
        anchors.fill: parent
        color: "white"

        Button {
            id: button
            anchors {
                top: parent.top
                right: parent.right
                topMargin: 15
                rightMargin: 15
            }
            text: qsTr("Sign out")
            onClicked: {
                console.log("Sign out button clicked")
                fsmEvent.signOut()
            }
        }

        UsersView {
            width: parent.width - button.width
            anchors {
                top: parent.top
                bottom: parent.bottom
                left: parent.left
                right: button.left
                topMargin: 15
                rightMargin: 15
                leftMargin: 15
            }
        }
    }
}
