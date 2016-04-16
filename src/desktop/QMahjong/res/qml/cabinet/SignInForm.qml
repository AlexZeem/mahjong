import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item{
    width: main.width;
    height: main.height;

    Rectangle {
        id:root
        anchors.centerIn: parent;
        width: parent.width / 2;
        height: parent.height / 2;
        color: "white"
        border.width: 5
        border.color: "black"
        radius: 15

        Text {
            id: header;
            text: qsTr("SIGN IN");
            font.pixelSize: 50
            anchors.horizontalCenter: root.horizontalCenter
            anchors.top: root.top
            anchors.topMargin: 5
        }

        Column {
            id:log;
            anchors.top:header.bottom;
            anchors.horizontalCenter: root.horizontalCenter;
            anchors.topMargin: 15;
            spacing: 5

            Row {
                spacing: 5;
                anchors.horizontalCenter: log.horizontalCenter;
                Text {text: qsTr("Login:"); font.pixelSize:20}
                TextField {
                    maximumLength: 20
                    style: TextFieldStyle {
                        textColor: "black"
                        background: Rectangle {
                            radius: 2
                            implicitWidth: 100
                            implicitHeight: 24
                            border.color: "dark blue"
                            border.width: 1
                        }
                    }
                }
            }

            Row {
                spacing: 5;
                anchors.horizontalCenter: log.horizontalCenter;
                Text {text: qsTr("Password:"); font.pixelSize:20}
                TextField {
                    maximumLength: 20
                    echoMode: TextInput.Password;
                    style: TextFieldStyle {
                        textColor: "black"
                        background: Rectangle {
                            radius: 2
                            implicitWidth: 100
                            implicitHeight: 24
                            border.color: "dark blue"
                            border.width: 1
                        }

                    }
                }
            }
        }

        Button {
            id:button;
            anchors.top: log.bottom;
            anchors.right: log.right;
            anchors.topMargin: 15;

            style: ButtonStyle {
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 24
                    color: "light grey"
                    border.width: control.activeFocus ? 2 : 1
                    border.color: "#888"
                    radius: 4
                }
                label: Text{
                    text:qsTr("Sign in")
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 22
                    style: Text.Sunken;
                    color: "black"
                    styleColor: "grey"
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: clicked();
            }
        }
    }
}
