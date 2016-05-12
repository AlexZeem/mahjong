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

    Image {
        id: avatar
        anchors {
            top: parent.top
            topMargin: nConst.margin
            horizontalCenter: parent.horizontalCenter
        }
        width: 150
        height: avatar.width
        fillMode: Image.PreserveAspectFit
        source: "qrc:///res/icons/cabinet/UserIcon.png"
    }

    Grid {
        id: body
        columns: 2
        spacing: 5
        anchors {
            margins: nConst.margin
            top: avatar.bottom
            left: parent.left
            right: parent.right
        }

        TLableText {
            text: qsTr("Nickname: ")
        }
        TTextInput {
            id: nicknameTI
            text: umediator.nickname
            readOnly: true
            width: parent.width / 2 + nConst.margin
        }

        TLableText {
            text: qsTr("Name: ")
        }
        TTextInput {
            id: nameTI
            text: umediator.name
            readOnly:true
            width: parent.width / 2 + nConst.margin
        }

        TLableText {
            text: qsTr("Surname: ")
        }
        TTextInput {
            id: surnameTI
            text: umediator.surname
            readOnly:true
            width: parent.width / 2 + nConst.margin
        }

        TLableText {
            text: qsTr("Phone: ")
        }
        TTextInput {
            id: phoneTI
            text: umediator.phone
            readOnly: true
            width: parent.width / 2 + nConst.margin
        }

        TLableText {
            text: qsTr("Email: ")
        }
        TTextInput{
            id: emailTI
            text: umediator.email
            readOnly: true
            width: parent.width / 2 + nConst.margin
        }

        TLableText {
            text: qsTr("Rang: ")
        }
        TTextInput {
            text: umediator.rang
            font.italic: true
            readOnly: true
            maximumLength: 6
            width: parent.width / 2 + nConst.margin
        }
    } // grid

    Column {
        id:buttonClmn
        anchors {
            top: body.bottom
            left: body.left
            topMargin: nConst.margin
        }
        spacing: 3

        TButton {
            id: editButton
            text: qsTr("Edit")
            visible: true
            onClicked: {
                console.log("Edit button clicked")

                //Save/Cancel visibility on
                //Edit - off
                saveButton.visible = true
                cancelButton.visible = true
                editButton.visible = false

                // Open cells for edit
                nicknameTI.readOnly = false
                nameTI.readOnly = false
                surnameTI.readOnly = false
                emailTI.readOnly = false
                phoneTI.readOnly = false
            }
        } // editButton

        TButton {
            id: saveButton
            text: qsTr("Save")
            visible: false
            onClicked: {
                console.log("Save button clicked")

                //set
                if(nicknameTI.text != umediator.nickname){umediator.nickname = nicknameTI.text}
                if(nameTI.text != umediator.name){umediator.name = nameTI.text}
                if(surnameTI.text != umediator.surname) {umediator.surname = surnameTI.text}
                if(emailTI.text != umediator.email) {umediator.email = emailTI.text}
                if (phoneTI.text != umediator.phone) {umediator.phone = phoneTI.text}

                //Save/Cancel visibility off
                //Edit - on
                saveButton.visible = false
                cancelButton.visible = false
                editButton.visible = true

                // Close cells for edit
                nicknameTI.readOnly = true
                nameTI.readOnly = true
                surnameTI.readOnly = true
                emailTI.readOnly = true
                phoneTi.readOnly = true
            }
        } // saveButton

        TButton {
            id: cancelButton
            text: qsTr("Cancel")
            visible: false
            onClicked: {
                console.log("Cancel button clicked")

                //Save/Cancel visibility off
                //Edit - on
                saveButton.visible = false
                cancelButton.visible = false
                editButton.visible = true

                //Set basic user info
                nicknameTI.text = umediator.nickname
                nameTI.text = umediator.name
                surnameTI.text = umediator.surname
                emailTI.text = umediator.email
                phoneTI.text = umediator.phone

                // Close cells for edit
                nicknameTI.readOnly = true
                nameTI.readOnly = true
                surnameTI.readOnly = true
                emailTI.readOnly = true
                phoneTi.readOnly = true
            }
        } // cancelButton
    } // end column
}

