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
                player1wind: "E"
                player1mahjong: true
                player1point: 21
                player1score: 41
                player2wind: "S"
                player2mahjong: false
                player2point: 8
                player2score: 8
                player3wind: "W"
                player3mahjong: false
                player3point: 2
                player3score: 4
                player4wind: "N"
                player4mahjong: false
                player4point: 6
                player4score: 12
            }
        }

        Component {
            id: checkBoxDelegate

            Item {
                CheckBox {
                    checked: model.player1mahjong
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
            width: headerTable.width;

            TableViewColumn {
                role: "player1wind"
                width: 30
            }
            TableViewColumn {
                role: "player1mahjong"
                width: 30
                delegate: checkBoxDelegate
            }
            TableViewColumn {
                role: "player1point"
                width: 30
            }
            TableViewColumn {
                role: "player1score"
                width: 30
            }

            TableViewColumn {
                role: "player2wind"
                width: 30
            }
            TableViewColumn {
                role: "player2mahjong"
                width: 30
                delegate: CheckBox {
                    checked: model.player2mahjong
                    enabled: false
                }
            }
            TableViewColumn {
                role: "player2point"
                width: 30
            }
            TableViewColumn {
                role: "player2score"
                width: 30
            }

            TableViewColumn {
                role: "player3wind"
                width: 30
            }
            TableViewColumn {
                role: "player3mahjong"
                width: 30
                delegate: CheckBox {
                    checked: model.player3mahjong
                    enabled: false
                }
            }
            TableViewColumn {
                role: "player3point"
                width: 30
            }
            TableViewColumn {
                role: "player3score"
                width: 30
            }

            TableViewColumn {
                role: "player4wind"
                width: 30
            }
            TableViewColumn {
                role: "player4mahjong"
                width: 30
                delegate: CheckBox {
                    checked: model.player4mahjong
                    enabled: false
                }
            }
            TableViewColumn {
                role: "player4point"
                width: 30
            }
            TableViewColumn {
                role: "player4score"
                width: 30
            }
        }
    }
}
