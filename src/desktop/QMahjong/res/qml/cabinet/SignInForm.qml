import QtQuick 2.4
import "../controls"

Item{
    id: root

    TBackgroundItem {
        id: background
        anchors.fill: parent
    }

    TItem {
        id: form
        anchors.centerIn: background
        width: parent.width / 2
        height: parent.height / 2
    }

    TTitle {
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

        TLable {
            text: qsTr("Login:")
        }

        TInputText {
            id: loginInput
        }

        TLable {
            text: qsTr("Password:")
        }

        TInputText {
            id: passInput
            echoMode: TextInput.Password
        }
    }

    TButton {
        id: button
        anchors {
            top: body.bottom
            topMargin: nConst.margin
            right: body.right
        }
        text: qsTr("Sign in")
        onClicked: {
            console.log("Sign in button clicked")
            auth.validate(loginInput.text, passInput.text)
        }
    }
}
