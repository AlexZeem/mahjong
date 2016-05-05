import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root

    Rectangle {
        anchors.fill: parent
        color: "white"

        Column {
            spacing: 5
            anchors {
                top: parent.top
                horizontalCenter: parent.horizontalCenter
                topMargin: 15
            }

            Image {
                id: avatar
                width: 150
                height: 150
                fillMode: Image.PreserveAspectFit
                source: "qrc:///res/icons/cabinet/UserIcon.png"
            }

            Row {
                id: nickname
                Text {
                    text: qsTr("Nickname: ")
                }
                Text {
                    text: umediator.nickname
                }
            }

            Row {
                id: name
                Text {
                    text: qsTr("Name: ")
                }
                Text {
                    text: ""
                }
            }

            Row {
                id: surname
                Text {
                    text: qsTr("Surname: ")
                }
                Text {
                    text: ""
                }
            }

            Row {
                id: rang
                Text {
                    text: qsTr("Rang: ")
                }
                Text {
                    text: ""
                    font.italic: true
                }
            }

            Button {
                id: editButton
                text: qsTr("Edit")

                onClicked: {
                    console.log("Edit button clicked")
                }
            }
        }
    }
}
