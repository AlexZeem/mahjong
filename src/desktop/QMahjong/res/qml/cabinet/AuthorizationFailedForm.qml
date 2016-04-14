import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    width: main.width;
    height: main.height;

    Rectangle{
        id: backgr
        anchors.centerIn: parent
        width: parent.width / 1.5;
        height: parent.height / 1.5;
        color: "white"
        border.color: "black"
        border.width: 5
        radius: 15

    }

    Text{
     id:header
     anchors.centerIn: parent
     text: qsTr("Authorization Failed")
     font.pixelSize: 32
     color: "black"
    }

    Button{
        id: back
        anchors.top: backgr.top
        anchors.right: backgr.right
        anchors.topMargin: 15
        anchors.rightMargin: 15

        style: ButtonStyle {
            background: Rectangle {
                id: btnbg
                implicitWidth: 100
                implicitHeight: 24
                color: "light grey"
                border.color: "black"
                border.width: 1
                radius: 4
            }

            label: Text {
                text: qsTr("Back")
                color: "black"
                font.pixelSize: 22
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea{
                anchors.fill: parent
                onClicked: clicked();
            }

        }

    }

}
