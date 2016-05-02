import QtQuick 2.0
import QtQuick.Controls 1.3

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
    }
}
