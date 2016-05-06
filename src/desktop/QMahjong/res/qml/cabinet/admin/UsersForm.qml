import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id : root
    property int gameSelected: -1
    property bool delegateEditable: true

    Rectangle {
        anchors.fill: parent
        color: "green"
    }
    onGameSelectedChanged: {
        gmediator.getPlayers(gmediator.gamesModel ? gmediator.gamesModel.gameId(gameSelected) : 0)
    }

    Component {
        id: listItemDelegate
        Item {
            width: parent.width
            height: 15
            Text {
                id: login
                text: modelData
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    playersList.currentIndex = index
                    if (delegateEditable === false) {
                        delegateEditable = true
                        gmediator.addPlayer(gmediator.gamesModel ? gmediator.gamesModel.gameId(gameSelected) : 0, modelData)
                        playersList.model = gmediator.players

                    } else {
                        login.color = "white"
                    }
                }
            }
        }
    }

    ListView {
        id: playersList
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        height: parent.height - addPlayer.height
        model: gmediator.players
        delegate: listItemDelegate
    }

    Button {
        id: addPlayer
        text: qsTr("Add")
        anchors {
            top: playersList.bottom
            left: playersList.left
        }
        width: parent.width / 2
        enabled: gameSelected > -1 ? true : false
        onClicked: {
            delegateEditable = false
            playersList.model = gmediator.users
        }
    }

    Button {
        id: deletePlayer
        text: qsTr("Delete")
        anchors {
            top: playersList.bottom
            left: addPlayer.right
        }
        width: parent.width / 2
        enabled: gameSelected > -1 ? true : false
        onClicked: {
            //gmediator.gamesModel.removeEntry(gamesTable.selectedRow)
        }
    }
}

