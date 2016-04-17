import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item{
    id: root

    Rectangle {
        id: form
        anchors.centerIn: parent
        width: parent.width / 2
        height: parent.height / 2
        color: "white"
        border.width: 5
        border.color: "black"
        radius: 15

        Text {
            id: header
            anchors {
                top: form.top
                topMargin: 5
                horizontalCenter: form.horizontalCenter
            }

            text: qsTr("SIGN IN")
            font.pixelSize: 50
        }

        Row {
            id: body
            spacing: 5

            anchors {
                top: header.bottom
                topMargin: 5
                horizontalCenter: form.horizontalCenter
            }

            Column {
                spacing: 5

                Text {
                    text: qsTr("Login:")
                    font.pixelSize:20
                }

                Text {
                    text: qsTr("Password:")
                    font.pixelSize:20
                }
            }

            Column {
                spacing: 5

                TextField {
                    id: loginInput
                    maximumLength: 20
                }

                TextField {
                    id: passInput
                    maximumLength: 20
                    echoMode: TextInput.Password
                }
            }
        }

        Button {
            id: button
            anchors {
                top: body.bottom
                topMargin: 5
                right: body.right
            }

            text: qsTr("Sign in")

            onClicked: {
                console.log("Sign in button clicked")
                auth.validate(loginInput.text, passInput.text);
            }
        }
    }
}
