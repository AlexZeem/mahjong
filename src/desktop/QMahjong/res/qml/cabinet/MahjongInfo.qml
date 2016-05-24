import QtQuick 2.0
import QtQuick.Controls 1.3
import "../controls"

Item {
    id: root

    TItem {
        id: background
        focused: true
        anchors.fill: parent
    }

    Column {
        anchors {
            top: parent.top
            left: parent.left
        }

        Row {
            id: wins
            TLableText {
                text: qsTr("Mahjongs: ")
            }
            TTextInput {
                width: 25
                text: ginfomediator.countMahjong
                readOnly: true
                horizontalAlignment: TextInput.AlignHCenter
            }
        }

        Row {
            id: bestResults
            spacing: 10
            Text {
                text: qsTr("Best:")
            }
            Text {
                width: 25
                text: "2"
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                text: qsTr(new Date().toLocaleDateString(Locale.ShortFormat))
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Row {
            id: worstResults
            spacing: 10

            Text {
                text: qsTr("Worst:")
            }
            Text {
                width: 25
                text: "2"
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                text: qsTr(new Date().toLocaleDateString(Locale.ShortFormat))
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }

}
