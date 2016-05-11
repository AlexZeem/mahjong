import QtQuick 2.0
import QtQuick.Controls 1.3
import "../controls"

Item {
    id: root

    TItem {
        id: background
        focused: true
        anchors.fill: parent
    }

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
                text: umediator.name
            }
        }

        Row {
            id: surname
            Text {
                text: qsTr("Surname: ")
            }
            Text {
                text: umediator.surname
            }
        }

        Row {
            id: phone
            Text {
                text: qsTr("Phone: ")
            }
            Text {
                text: umediator.phone
            }
        }

        Row {
            id: email
            Text {
                text: qsTr("Surname: ")
            }
            Text {
                text: umediator.email
            }
        }

        Row {
            id: rang
            Text {
                text: qsTr("Rang: ")
            }
            Text {
                text: umediator.rang
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
