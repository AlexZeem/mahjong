import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id : root
    property int gameSelected: 0

    Rectangle {
        anchors.fill: parent
        color: "green"
    }
    onGameSelectedChanged: {
        gmediator.getPlayers(gmediator.gamesModel ? gmediator.gamesModel.gameId(gameSelected) : 0)
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
        delegate: Text {
            text: modelData
        }
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
            gmediator.addPlayer(gmediator.gamesModel ? gmediator.gamesModel.gameId(gameSelected) : 0, "a")
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

