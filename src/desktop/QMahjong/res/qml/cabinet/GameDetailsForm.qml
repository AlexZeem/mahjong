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

    TTableView {
        id: headerTable
        model: ginfomediator.handDetail
        width: parent.width
        height: 40
        anchors {
            top: button.bottom
            topMargin: 15
            horizontalCenter: background.horizontalCenter
        }
        TableViewColumn {
            role: "player1Score"
            title: ginfomediator.playerOne
            width: parent.width/4
        }
        TableViewColumn {
            role: "player2Score"
            title: ginfomediator.playerTwo
            width: parent.width/4
        }
        TableViewColumn {
            role: "player3Score"
            title: ginfomediator.playerThree
            width: parent.width/4
        }
        TableViewColumn {
            role: "player4Score"
            title: ginfomediator.playerFour
            width: parent.width/4
        }
    } // end header table;

    TTableView {
        id: handDetailTable
        model: ginfomediator.handDetail
        headerVisible: false
        anchors {
            top: headerTable.bottom
            horizontalCenter: background.horizontalCenter
            verticalCenter: background.verticalCenter
        }
        width: headerTable.width

        TableViewColumn {
            role: "player1wind"
            width: (headerTable.width/4)/4
        }
        TableViewColumn {
            role: "player1mahjong"
            width: (headerTable.width/4)/4
            delegate: CheckBox {
                checked: model.player1mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player1point"
            width: (headerTable.width/4)/4
        }
        TableViewColumn {
            role: "player1score"
            width: (headerTable.width/4)/4
        }
        TableViewColumn {
            role: "player2mahjong"
            width: (headerTable.width/4)/3
            delegate: CheckBox {
                checked: model.player2mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player2point"
            width: (headerTable.width/4)/3
        }
        TableViewColumn {
            role: "player2score"
            width: (headerTable.width/4)/3
        }

        TableViewColumn {
            role: "player3mahjong"
            width: (headerTable.width/4)/3
            delegate: CheckBox {
                checked: model.player3mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player3point"
            width: (headerTable.width/4)/3
        }
        TableViewColumn {
            role: "player3score"
            width: (headerTable.width/4)/3
        }
        TableViewColumn {
            role: "player4mahjong"
            width: (headerTable.width/4)/3
            delegate: CheckBox {
                checked: model.player4mahjong
                enabled: false
            }
        }
        TableViewColumn {
            role: "player4point"
            width: (headerTable.width/4)/3
        }
        TableViewColumn {
            role: "player4score"
            width: (headerTable.width/4)/3
        }
    } //end handDetailTable;
}
