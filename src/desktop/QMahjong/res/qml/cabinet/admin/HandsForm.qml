import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root
    property alias gameSelected: handsTable.gameSelected

    Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Button {
        id: addNew
        text: qsTr("Add new")
        anchors {
            top: parent.top
            left: parent.left
        }
        enabled: gameSelected > -1 ? true : false
        onClicked: {
            gmediator.handsModel.addEntry(gmediator.gamesModel ? gmediator.gamesModel.gameId(gameSelected) : 0)
        }
    }

    Button {
        id: deleteSelected
        text: qsTr("Delete")
        anchors {
            top: parent.top
            right: parent.right
        }
        enabled: handsTable.selectedRow > -1 ? true : false
        onClicked: {
            gmediator.handsModel.removeEntry(handsTable.selectedRow)
        }
    }

    HandsTable {
        id: handsTable
        anchors {
            top: addNew.bottom
            topMargin: 15
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

    }
}
