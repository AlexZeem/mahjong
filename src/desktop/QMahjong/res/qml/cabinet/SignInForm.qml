import QtQuick 2.0
import QtQuick.Controls 1.3

Rectangle {
    id:root
    width: 530
    height: 370
    color: "white"
    border.width: 5
    border.color: "black"
    radius: 15

    Text {
        id:header
        text: "SIGN IN"
        font.pixelSize: 50
        anchors.horizontalCenter: root.horizontalCenter
        anchors.top: root.top
        anchors.topMargin: 20
    }

    Column {
        id:log;
        anchors.centerIn: root
        spacing: 5

        Row {
            spacing: 5;
            Text {text:"Login:";font.pixelSize:20;}
            TextField {
                placeholderText: qsTr("Enter name")
                font.pixelSize:20;
            }
        }

        Row {
            spacing: 5;
            Text {text:"Password:"; font.pixelSize:20;}
            TextField {
                placeholderText: qsTr("Enter password")
                font.pixelSize: 20;
                echoMode: TextInput.Password;
            }
        }
    }

    Rectangle {
        id: button;
        anchors.horizontalCenter: log.horizontalCenter
        anchors.top: log.bottom
        anchors.topMargin: 15
        width: buttonText.width + 20;
        height: 50
        color: "light grey"
        property alias text : buttonText.text
        radius: 10
        antialiasing: true

        Text {
            id: buttonText
            text: "Sign in"
            anchors.centerIn: parent
            font.pixelSize: parent.height/2;
            style: Text.Sunken
            color: "black"
            styleColor: "dark grey"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: parent.clicked()
        }
    }
}

