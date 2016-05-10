import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item{
    id: root

    Image {
        id: background
        anchors.fill: parent
        opacity: 0.2
        source: "qrc:///res/icons/cabinet/lightBackground.png"
    }

    Rectangle {
        id: form
        anchors.centerIn: parent
        width: parent.width / 2
        height: parent.height / 2
        color: cScheme.itemBackgroungColor
        radius: 5
        border {
            width: 3
            color: cScheme.borderColor
        }

        Text {
            id: header
            anchors {
                top: form.top
                topMargin: 30
                horizontalCenter: form.horizontalCenter
            }

            text: qsTr("SIGN IN")
            font.pixelSize: 30
            color: cScheme.activeFocusTitleColor
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

            Text {
                text: qsTr("Login:")
                font.pixelSize: 16
                color: cScheme.textColor
            }

            TextField {
                id: loginInput
                maximumLength: 10
                style: TextFieldStyle {
                    textColor: loginInput.activeFocus ? cScheme.activeFocusTextColor : cScheme.inactiveFocusTextColor
                    background: Rectangle {
                        radius: 5
                        border {
                            width: 1
                            color: cScheme.borderColor
                        }
                    }
                }
            }

            Text {
                text: qsTr("Password:")
                font.pixelSize: 16
                color: cScheme.textColor
            }

            TextField {
                id: passInput
                maximumLength: 10
                echoMode: TextInput.Password
                style: TextFieldStyle {
                    textColor: passInput.activeFocus ? cScheme.activeFocusTextColor : cScheme.inactiveFocusTextColor
                    background: Rectangle {
                        radius: 5
                        border {
                            width: 1
                            color: cScheme.borderColor
                        }
                    }
                }
            }
        }

        Button {
            id: button
            anchors {
                top: body.bottom
                topMargin: 10
                right: body.right
            }

            style: ButtonStyle {
                background: Rectangle {
                    id: styleRect
                    implicitWidth: 75
                    implicitHeight: 25
                    radius: 5
                    border {
                        width: 1
                        color: cScheme.borderColor
                    }
                }
                label: Text {
                    text: qsTr("Sign in")
                    color: button.pressed ? cScheme.activeFocusTextColor : cScheme.inactiveFocusTextColor
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            onClicked: {
                console.log("Sign in button clicked")
                auth.validate(loginInput.text, passInput.text);
            }
        }
    }
}
