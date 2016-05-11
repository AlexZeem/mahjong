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

        Row {
            id:buttonRow
            spacing: 3

            Button {
                id: editButton
                text: qsTr("Edit")
                visible: true
                onClicked: {
                    console.log("Edit button clicked")
                    saveButton.visible = true
                    cancelButton.visible = true
                    editButton.visible = false
                }
            } // editButton

            Column {
                spacing: 3

                Button {
                    id: saveButton
                    text: qsTr("Save")
                    visible: false
                    onClicked: {
                        console.log("Save button clicked")
                        saveButton.visible = false
                        cancelButton.visible = false
                        editButton.visible = true
                    }
                } // saveButton

                Button {
                    id: cancelButton
                    text: qsTr("Cancel")
                    visible: false
                    onClicked: {
                        console.log("Save button clicked")
                        saveButton.visible = false
                        cancelButton.visible = false
                        editButton.visible = true
                    }
                } // cancelButton

            } // end column

        } // buttonRow
    }
}