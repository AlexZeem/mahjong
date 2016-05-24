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
            horizontalCenter: parent.horizontalCenter
            topMargin: 15
        }

        Row {
            id: wins
            TTextInput {
                text: qsTr("Mahjongs: ")
                readOnly: true
            }
            TTextInput {
                width: 25
                text: ginfomediator.countMahjong
                readOnly: true
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
