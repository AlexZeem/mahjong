import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    height: main.height
    width: main.width

    GroupBox {
        title: "Player info"
        anchors.left: parent.left;

        Column{
            spacing: 5
            width: 213
            anchors.horizontalCenter: parent.horizontalCenter

            Image {
                id: avatar
                source: "UserIcon.png"
                width: 150;
                height: 150;
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Row {
                id: nickname
                width: avatar.width
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    text: qsTr("Nickname: ")
                    color: "black"
                }
            }

            Row{
                id:name
                width: avatar.width
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    text: qsTr("Name: ")
                    color: "black"
                }
            }

            Row{
                id: surname
                width: avatar.width
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    text: qsTr("Surname: ")
                    color: "black"
                }
            }

            Row {
                id: rank
                width: avatar.width
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    text: qsTr("Rank: ")
                    color: "black"
                }

                Rectangle {
                    width: 100;
                    height: 15;
                    color: "white"
                    border.color: "black"
                    border.width: control.activeFocus ? 2 : 1
                    radius: 3

                    Text{
                        text: qsTr("0000");
                        color: "black"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }

            Button {
                id:button;
                anchors.horizontalCenter: parent.horizontalCenter

                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 20
                        color: "light grey"
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "grey"
                        radius: 3
                    }
                    label: Text{
                        text:qsTr("Edit")
                        horizontalAlignment: Text.AlignHCenter
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

}
