import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root

    Rectangle {
        anchors.fill: parent
        color: "white"

        Column {
            spacing: 5
            anchors {
                top: parent.top
                horizontalCenter: parent.horizontalCenter
                topMargin: 15
            }

            Row {
                id: lastGame
                Text {
                    text: qsTr("Last Game: ")
                }
                Text {
                    text: qsTr(new Date().toLocaleDateString(Locale.ShortFormat))
                }
            }

            Row {
                id: participated
                Text {
                    text: qsTr("Participated in: ")
                }
                Text {
                    width: 25
                    text: "2"
                }
                Button {
                    id: button
                    width: 25
                    text: qsTr("...")

                    onClicked: {
                        console.log("More in button clicked")
                        fsmEvent.gameStat()
                    }
                }
            }
        }
    }
}
