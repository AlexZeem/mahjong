import QtQuick 2.0
import QtQuick.Controls 1.3
import "../controls"

Item {
    id: root

    TItem {
        id: background
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

        TLable {
            id: nicknameLbl
            text: qsTr("Nickname:")
        }
        TLable {
            id: nickname
            text: umediator.nickname
            implicitWidth: nicknameLbl.width
            property string enteredText: umediator.nickname
            Loader {
                id: nicknameLoader
                anchors.fill: parent
                sourceComponent: saveButton.visible ? nicknameEditor : null

                Connections {
                    target: nicknameLoader.item
                    onEditingFinished: {
                        nickname.enteredText = nicknameLoader.item.text
                    }
                }
                Component {
                    id: nicknameEditor
                    TInputText {
                        font.pixelSize: phone.font.pixelSize
                        text: nickname.text
                    }
                }
            }
        }

        TLable {
            text: qsTr("Name: ")
        }
        TLable {
            id: name
            text: umediator.name
            property string enteredText: umediator.name
            Loader {
                id: nameLoader
                anchors.fill: parent
                sourceComponent: saveButton.visible ? nameEditor : null

                Connections {
                    target: nameLoader.item
                    onEditingFinished: {
                        name.enteredText = nameLoader.item.text
                    }
                }
                Component {
                    id: nameEditor
                    TInputText {
                        font.pixelSize: phone.font.pixelSize
                        text: name.text
                    }
                }
            }
        }


        TLable {
            id: surnameLbl
            text: qsTr("Surname:")
        }
        TLable {
            id: surname
            text: umediator.surname
            width: surnameLbl.width
            height: surnameLbl.height
            property string enteredText: umediator.surname
            Loader {
                id: surnameLoader
                anchors.fill: parent
                sourceComponent: saveButton.visible ? surnameEditor : null

                Connections {
                    target: surnameLoader.item
                    onEditingFinished: {
                        surname.enteredText = surnameLoader.item.text
                    }
                }
                Component {
                    id: surnameEditor
                    TInputText {
                        font.pixelSize: phone.font.pixelSize
                        text: surname.text
                    }
                }
            }
        }

        TLable {
            id: phoneLbl
            text: qsTr("Phone: ")
        }
        TLable {
            id: phone
            text: umediator.phone
            implicitWidth: phoneLbl.width
            property string enteredText: umediator.phone
            Loader {
                id: phoneLoader
                anchors.fill: parent
                sourceComponent: saveButton.visible ? phoneEditor : null

                Connections {
                    target: phoneLoader.item
                    onEditingFinished: {
                        phone.enteredText = phoneLoader.item.text
                    }
                }
                Component {
                    id: phoneEditor
                    TInputText {
                        font.pixelSize: phone.font.pixelSize
                        text: phone.text
                    }
                }
            }
        }

        TLable {
            text: qsTr("Email: ")
        }
        TLable {
            id: email
            text: umediator.email
            property string enteredText: umediator.email
            Loader {
                id: emailLoader
                anchors.fill: parent
                sourceComponent: saveButton.visible ? emailEditor : null

                Connections {
                    target: emailLoader.item
                    onEditingFinished: {
                        email.enteredText = emailLoader.item.text
                    }
                }
                Component {
                    id: emailEditor
                    TInputText {
                        font.pixelSize: phone.font.pixelSize
                        text: email.text
                    }
                }
            }
        }

        TLable {
            text: qsTr("Rang: ")
        }
        TLable {
            text: umediator.rang
            font.italic: true
        }
    } // grid

    Row {
        anchors {
            top: body.bottom
            left: body.left
            topMargin: nConst.margin
        }
        spacing: 5

        TButton {
            id: saveButton
            text: qsTr("Save")
            visible: false
            onClicked: {
                console.log("Save button clicked")

                //set
                if (nickname.enteredText !== umediator.nickname) { umediator.nickname = nickname.enteredText; nickname.text = umediator.nickname }
                if (name.enteredText !== umediator.name)         { umediator.name = name.enteredText; name.text = umediator.name }
                if (surname.enteredText !== umediator.surname)   { umediator.surname = surname.enteredText; surname.text = umediator.surname }
                if (email.enteredText !== umediator.email)       { umediator.email = email.enteredText; email.text = umediator.email }
                if (phone.enteredText !== umediator.phone)       { umediator.phone = phone.enteredText; phone.text = umediator.phone }

                saveButton.visible = false
                editButton.text = qsTr("Edit")
            }
        } // saveButton

        TButton {
            id: editButton
            text: qsTr("Edit")
            visible: true
            onClicked: {
                saveButton.visible = !saveButton.visible
                editButton.text = saveButton.visible ? qsTr("Cancel") : qsTr("Edit")

                if (saveButton.visible) {
                    nickname.text = umediator.nickname
                    name.text     = umediator.name
                    surname.text  = umediator.surname
                    email.text    = umediator.email
                    phone.text    = umediator.phone
                }
            }
        } // editButton
    }
}

