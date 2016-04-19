import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root
    Rectangle {
        anchors.fill: parent
        color: "white"

        Button {
            id: button
            text: qsTr("Back")
            anchors {
                top: parent.top
                right: parent.right
                topMargin: 15
                rightMargin: 15
            }
            onClicked: {
                console.log ("Back is pressed")
                fsmEvent.back()
            }
        }

        // 1st part of game details table;
        ListModel {
            id: scoreModel
            ListElement {
                player1Score: 312
                player2Score: 313
                player3Score: 31
                player4Score: 31
            }
        }

        TableView {
            id: headerTable
            model: scoreModel
            width: parent.width
            height: 40
            anchors {
                top: button.bottom
                topMargin: 15
                horizontalCenter: parent.horizontalCenter
            }

            TableViewColumn {
                role: "player1Score"
                title: qsTr("Player1")
                width: 120
            }
            TableViewColumn {
                role: "player2Score"
                title: qsTr("Player2")
                width: 120
            }
            TableViewColumn {
                role: "player3Score"
                title: qsTr("Player3")
                width: 120
            }
            TableViewColumn {
                role: "player4Score"
                title: qsTr("Player4")
                width: 120
            }
        }

        // count table part
        ListModel {
            id: countModel
            ListElement {
                wind: "E"
                mahjong: true
                point: 21
                score: 41
            }
        }

        Component {
            id: checkBoxDelegate

            Item {
                CheckBox {
                    checked: model.mahjong
                    enabled: false
                }
            }
        }

        TableView {
            id: countTable
            model: countModel
            headerVisible: false
            anchors {
                top: headerTable.bottom
            }

            TableViewColumn {
                role: "wind"
                width: 30
            }
            TableViewColumn {
                role: "mahjong"
                width: 30
                delegate: checkBoxDelegate
            }
            TableViewColumn {
                role: "point"
                width: 30
            }
            TableViewColumn {
                role: "score"
                width: 30
            }
        }
    }
}
