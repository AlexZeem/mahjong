import QtQuick 2.0

Item {
    id : root
    property int gameSelected: 0

    Rectangle {
        anchors.fill: parent
        color: "green"
    }

    ListView {
        anchors.fill: parent
        model: gameSelected > -1 ? (gmediator.players(gmediator.gamesModel ? gmediator.gamesModel.gameId(gameSelected) : 0)) : ListModel
        delegate: Text {
            text: modelData
        }
    }
}

