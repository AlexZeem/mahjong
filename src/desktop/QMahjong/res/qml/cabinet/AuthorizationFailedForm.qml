import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    id: root

    Rectangle {
        id: backgr
        anchors.centerIn: parent
        width: parent.width / 1.5
        height: parent.height / 1.5
        color: "white"
        border.color: "black"
        border.width: 5
        radius: 15
    }

    Text {
        id:header
        anchors.centerIn: parent
        text: qsTr("Authorization Failed")
        font.pixelSize: 32
        color: "black"
    }

    Button {
        id: back

        anchors {
            top: backgr.top
            right: backgr.right
            topMargin: 15
            rightMargin: 15
        }

        text: qsTr("Back")

        onClicked: {
            console.log("Back button clicked")
        }
    }
}
