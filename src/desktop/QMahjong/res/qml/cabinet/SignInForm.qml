import QtQuick 2.0
import "../controls"

Item{
    id: root

    TItem {
        id: background
        iActiveFocus: false
        anchors.fill: parent
    }

    TItem {
        id: form
        anchors.centerIn: parent
        width: parent.width / 2
        height: parent.height / 2
    }

    TTitleText {
        id: header
        anchors {
            top: form.top
            topMargin: 30
            horizontalCenter: form.horizontalCenter
        }
        text: qsTr("SIGN IN")
    }

    Grid {
        id: body
        columns: 2
        spacing: 5
        anchors {
            top: header.bottom
            topMargin: 16
            horizontalCenter: header.horizontalCenter
        }

        TLableText {
            text: qsTr("Login:")
        }

        TTextInput {
            id: loginInput
            maximumLength: 10
        }

        TLableText {
            text: qsTr("Password:")
        }

        TTextInput {
            id: passInput
            maximumLength: 10
            echoMode: TextInput.Password
        }
    }

    TButton {
        id: button
        anchors {
            top: body.bottom
            topMargin: 10
            right: body.right
        }
        text: qsTr("Sign in")
        onClicked: {
            console.log("Sign in button clicked")
            auth.validate(loginInput.text, passInput.text);
        }
    }
}
