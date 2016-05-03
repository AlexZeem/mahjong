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

        TabView {
            anchors {
                top: parent.top
                bottom: parent.bottom
                left: parent.left
                right: button.left
                margins: 15
            }
            Tab {
                id: usersTab
                title: "Users"
                UsersView {
                    width: parent.width - button.width
                    anchors {
                        fill: parent
                        margins: 15
                    }
                }
            }

            Tab {
                title: "Games"
                Rectangle { color: "green" }
            }
        }


    }
}
