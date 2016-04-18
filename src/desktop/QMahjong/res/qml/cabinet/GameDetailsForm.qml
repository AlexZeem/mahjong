import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id:root;

    Button {
        id: button;
        text: qsTr("Back");
        anchors {
            top: root.top;
            right: root.right;
            topMargin: 15;
            rightMargin: 15;
        }
        onClicked: console.log ("Back is pressed");
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
        model: scoreModel
        width: root.width;
        height: 40;
        anchors {
            top: button.bottom;
            topMargin: 15
            horizontalCenter: root.horizontalCenter;
        }
    }

    // count table part

    /*ListModel {
        id: countModel
        ListElement {
            wind:E
            mahjong: ok
            point:21
            score:41
        }
    }*/
    TableView {
        id: countTable
        TableViewColumn {
            role: "wind"
            title: qsTr("Wind")
            width: 30
        }
        TableViewColumn {
            role: "mahjong"
            title: qsTr("Mahjong")
            width: 30
            delegate: CheckBox {
                enabled: true
                onClicked: console.log("mahjong is checked.")
            }
        }
        TableViewColumn {
            role: "point"
            title: qsTr("Point")
            width: 30
        }
        TableViewColumn {
            role: "score"
            title: qsTr("Score")
            width: 30
        }

        model: countModel
        anchors {
            top: headerTable.bottom;
        }

    }


}
