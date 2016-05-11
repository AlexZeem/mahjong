import QtQuick 2.0
import QtQuick.Controls 1.3
import "../controls"

Item {
    id: root

    TItem {
        id: backgroundL0
        focused: false
        anchors.fill: parent
        radius: 0
    }

    TItem {
        id: backgroundL1
        focused: true
        anchors {
            margins: nConst.margin
            top: button.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
    }

    TButton {
        id: button
        anchors {
            top: backgroundL0.top
            right: backgroundL0.right
            topMargin: nConst.margin
            rightMargin: nConst.margin
        }
        text: qsTr("Back")
        onClicked: {
            console.log ("Back is pressed")
            fsmEvent.back()
        }
    }

    TTableView {
        id: headerTable
        model: scoreModel
        width: backgroundL1.width - nConst.margin * 4
        height: nConst.headerTableHeight
        anchors {
            top: backgroundL1.top
            topMargin: nConst.margin
            horizontalCenter: backgroundL1.horizontalCenter
        }
        selectionMode: SelectionMode.NoSelection

        TableViewColumn {
            role: "player1Score"
            title: qsTr("Player1")
            width: headerTable.width / headerTable.columnCount
        }
        TableViewColumn {
            role: "player2Score"
            title: qsTr("Player2")
            width: headerTable.width / headerTable.columnCount
        }
        TableViewColumn {
            role: "player3Score"
            title: qsTr("Player3")
            width: headerTable.width / headerTable.columnCount
        }
        TableViewColumn {
            role: "player4Score"
            title: qsTr("Player4")
            width: headerTable.width / headerTable.columnCount
        }
    }

    TTableView {
        id: countTable
        model: countModel
        anchors {
            top: headerTable.bottom
            bottom: backgroundL1.bottom
            bottomMargin: 15
            horizontalCenter: backgroundL1.horizontalCenter
        }
        width: headerTable.width
        headerVisible: false
        selectionMode: SelectionMode.NoSelection

        TableViewColumn {
            role: "player1wind"
            title: qsTr("W")
            width: headerTable.width / countTable.columnCount
        }

        TableViewColumn {
            role: "player1mahjong"
            title: qsTr("M")
            width: headerTable.width / countTable.columnCount
            delegate: CheckBox {
                anchors.fill: parent
                checked: model.player1mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player1point"
            title: qsTr("C")
            width: headerTable.width / countTable.columnCount
        }
        TableViewColumn {
            role: "player1score"
            title: qsTr("S")
            width: headerTable.width / countTable.columnCount
        }

        TableViewColumn {
            role: "player2wind"
            title: qsTr("W")
            width: headerTable.width / countTable.columnCount
        }

        TableViewColumn {
            role: "player2mahjong"
            title: qsTr("M")
            width: headerTable.width / countTable.columnCount
            delegate: CheckBox {
                checked: model.player2mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player2point"
            title: qsTr("C")
            width: headerTable.width / countTable.columnCount
        }
        TableViewColumn {
            role: "player2score"
            title: qsTr("S")
            width: headerTable.width / countTable.columnCount
        }

        TableViewColumn {
            role: "player3wind"
            title: qsTr("W")
            width: headerTable.width / countTable.columnCount
        }

        TableViewColumn {
            role: "player3mahjong"
            title: qsTr("M")
            width: headerTable.width / countTable.columnCount
            delegate: CheckBox {
                checked: model.player3mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player3point"
            title: qsTr("C")
            width: headerTable.width / countTable.columnCount
        }
        TableViewColumn {
            role: "player3score"
            title: qsTr("S")
            width: headerTable.width / countTable.columnCount
        }

        TableViewColumn {
            role: "player4wind"
            title: qsTr("W")
            width: headerTable.width / countTable.columnCount
        }

        TableViewColumn {
            role: "player4mahjong"
            title: qsTr("M")
            width: headerTable.width / countTable.columnCount
            delegate: CheckBox {
                checked: model.player4mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player4point"
            title: qsTr("C")
            width: headerTable.width / countTable.columnCount
        }
        TableViewColumn {
            role: "player4score"
            title: qsTr("S")
            width: headerTable.width / countTable.columnCount
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
}
