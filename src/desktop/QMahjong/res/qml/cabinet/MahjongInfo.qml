import QtQuick 2.0
import QtQuick.Controls 1.3
import "../controls"

Item {
    id: root

    TItem {
        id: form
        anchors.centerIn: background
        width: parent.width / 2
        height: parent.height / 2
    }

    Column {
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
            topMargin: 15
        }

        Row {
            id: wins
            Text {
                text: qsTr("Mahjongs: ")
            }
            Text {
                width: 25
                text: "2"
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
