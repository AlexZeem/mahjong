import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root
    state: "edit"

    Button {
        id: addNew
        text: qsTr("Add new")
        anchors {
            top: parent.top
            left: parent.left
        }
        onClicked: {
            gmediator.gamesModel.addNew();
        }
    }

    Button {
        id: deleteSelected
        text: qsTr("Delete")
        anchors {
            top: addNew.top
            left: addNew.right
            leftMargin: 15
        }
        onClicked: {
            gmediator.gamesModel.deleteSelected(gamesTable.currentRow)
        }
    }

    GamesTable {
        id: gamesTable
        height: 150
        anchors {
            top: addNew.bottom
            topMargin: 15
        }
    }

    HandsTable {
        id: handsTable
        height: 150
        anchors {
            top: gamesTable.bottom
            topMargin: 15
        }
    }
}
