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

    TButton {
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

    TableView {
        id: headerTable
        model: ginfomediator.handDetail
        width: parent.width
        height: 40
        anchors {
            top: button.bottom
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
    } // end header table;

    TableView {
        id: handDetailTable
        model: ginfomediator.handDetail
        headerVisible: false
        anchors {
            top: headerTable.bottom
        }
        width: headerTable.width

        TableViewColumn {
            role: "player1wind"
            width: 30
        }
        TableViewColumn {
            role: model.modelData.player1mahjong
            width: 30
            delegate: CheckBox {
                checked: model.player1mahjong
                enabled: false
            }
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
            role: "player2mahjong"
            width: 40
            delegate: CheckBox {
                checked: model.player2mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player2point"
            width: 40
        }
        TableViewColumn {
            role: "player2score"
            width: 40
        }

        TableViewColumn {
            role: "player3mahjong"
            width: 40
            delegate: CheckBox {
                checked: model.player3mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player3point"
            width: 40
        }
        TableViewColumn {
            role: "player3score"
            width: 40
        }
        TableViewColumn {
            role: "player4mahjong"
            width: 40
            delegate: CheckBox {
                checked: model.player4mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player4point"
            width: 40
        }
        TableViewColumn {
            role: "player4score"
            width: 40
        }
    } //end handDetailTable;
}
