import QtQuick 2.0
import QtQuick.Controls 1.3
import "../controls"

TItem {
    id: root

    TItem {
        id: background
        focused: true
        anchors.fill: parent
    }

    Column {
        spacing: 5
        anchors {
            top: root.top
            left: root.left
            leftMargin: 5
            topMargin: 10
        }

        Row {
            id: lastGame
            spacing: 5
            TLableText {
                text: qsTr("Last Game: ")
            }
            TTextInput {
                text: qsTr(ginfomediator.lastPlayed)
                readOnly: true;
                horizontalAlignment: TextInput.AlignHCenter

            }
        }

        Row {
            id: participated
            spacing: 5
            TLableText {
                text: qsTr("Participated in: ")
            }
            TTextInput {
                text: ginfomediator.participatedIn
                readOnly: true
                horizontalAlignment: TextInput.AlignHCenter
                width: 40
            }
            TButton {
                id: button
                width: 60
                text: qsTr("Details")

                onClicked: {
                    console.log("More in button clicked")
                    fsmEvent.gameStat()
                }
            }
        }
    }
}
