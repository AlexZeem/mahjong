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
            TLableText {
                text: qsTr("Nickname: ")
            }
            TTextInput {
                id: nicknameTI
                text: umediator.nickname
                readOnly: true
            }
        }

        Row {
            id: name
            TLableText {
                text: qsTr("Name: ")
            }
            TTextInput {
                id: nameTI
                text: umediator.name
                readOnly:true
            }
        }

        Row {
            id: surname
            TLableText {
                text: qsTr("Surname: ")
            }
            TTextInput {
                id: surnameTI
                text: umediator.surname
                readOnly:true
            }
        }

        Row {
            id: phone
            TLableText {
                text: qsTr("Phone: ")
            }
            TTextInput {
                id: phoneTI
                text: umediator.phone
                readOnly: true
            }
        }

        Row {
            id: email
            TLableText {
                text: qsTr("Email: ")
            }
            TTextInput{
                id: emailTI
                text: umediator.email
                readOnly: true
            }
        }

        Row {
            id: rang
            TLableText {
                text: qsTr("Rang: ")
            }
            TTextInput {
                text: umediator.rang
                font.italic: true
                readOnly: true
                maximumLength: 6
            }
        }

        Row {
            id:buttonRow
            spacing: 3

            TButton {
                id: editButton
                text: qsTr("Edit")
                visible: true
                onClicked: {
                    console.log("Edit button clicked")

                    //Edit click visibility
                    saveButton.visible = true
                    cancelButton.visible = true
                    editButton.visible = false

                    // open cells for editi
                    nicknameTI.readOnly = false
                    nameTI.readOnly = false
                    surnameTI.readOnly = false

                }
            } // editButton

            Column {
                spacing: 3

                TButton {
                    id: saveButton
                    text: qsTr("Save")
                    visible: false
                    onClicked: {
                        console.log("Save button clicked")

                        //Save click visibility
                        saveButton.visible = false
                        cancelButton.visible = false
                        editButton.visible = true

                        //accessibility to edit
                        nicknameTI.readOnly = true
                        nameTI.readOnly = true
                        surnameTI.readOnly = true

                        //set block
                        console.log(nicknameTI.text)
                        if(nicknameTI.text != umediator.nickname){umediator.setNickname(nicknameTI.text)}

                        console.log(nameTI.text)
                        if(nameTI.text != umediator.name){umediator.name = nameTI.text}

                        console.log(surnameTI.text)
                        if (surnameTI.text != umediator.surname) {umediator.surname = surnameTI.text}
                    }
                } // saveButton

                TButton {
                    id: cancelButton
                    text: qsTr("Cancel")
                    visible: false
                    onClicked: {
                        console.log("Save button clicked")
                        //visible block
                        saveButton.visible = false
                        cancelButton.visible = false
                        editButton.visible = true

                        //accesability
                        nicknameTI.readOnly = true
                        nameTI.readOnly = true
                        surnameTI.readOnly = true

                        //cancel block
//                        nicknameTI.text = umediator.nickname
//                        nameTI.text = umediator.name
//                        surnameTI.text = umediator.surname
                    }
                } // cancelButton

            } // end column

        } // buttonRow
    }
}
