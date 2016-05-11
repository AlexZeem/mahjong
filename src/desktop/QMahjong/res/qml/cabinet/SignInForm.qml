import QtQuick 2.0
import "../controls"

Item{
    id: root

    TItem {
        id: background
        focused: false
        anchors.fill: parent
        radius: 0
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
            topMargin: nConst.margin * 2
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
            topMargin: nConst.margin
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
            maximumLength: nConst.inputMaxLength
            echoMode: TextInput.Password
        }
    }

    TButton {
        id: button
        anchors {
            top: body.bottom
            topMargin: nConst.inputMaxLength
            right: body.right
        }
        text: qsTr("Sign in")
        onClicked: {
            console.log("Sign in button clicked")
            auth.validate(loginInput.text, passInput.text)
        }
    }
}
