import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root
    property alias selectedRow: tableView.currentRow

    TableView {
        id: tableView
        anchors.fill: parent
        frameVisible: true

        TableViewColumn {
            id: dateColumn
            title: "Date"
            role: "date"
            movable: false
            resizable: false
            width: tableView.viewport.width / 6
        }

        TableViewColumn {
            id: winnerColumn
            title: "Winner"
            role: "winner"
            movable: false
            resizable: false
            width: tableView.viewport.width / 6
        }

        TableViewColumn {
            id: score1Column
            title: "Score 1"
            role: "score1"
            movable: false
            resizable: false
            width: tableView.viewport.width / 6
        }

        TableViewColumn {
            id: score2Column
            title: "Score 2"
            role: "score2"
            movable: false
            resizable: false
            width: tableView.viewport.width / 6
        }

        TableViewColumn {
            id: score3Column
            title: "Score 3"
            role: "score3"
            movable: false
            resizable: false
            width: tableView.viewport.width / 6
        }

        TableViewColumn {
            id: score4Column
            title: "Score 4"
            role: "score4"
            movable: false
            resizable: false
            width: tableView.viewport.width / 6
        }

        model: gmediator.gamesModel

        itemDelegate: Component {
            id: editableDelegate
            Item {
                Text {
                    width: parent.width
                    anchors.margins: 4
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    elide: styleData.elideMode
                    text: styleData.value !== undefined ? styleData.value : ""
                    color: styleData.textColor
                    visible: !styleData.selected
                }
                Loader { // Initialize text editor lazily to improve performance
                    id: loaderEditor
                    anchors.fill: parent
                    anchors.margins: 4
                    Connections {
                        target: loaderEditor.item
                        onAccepted: {
                            gmediator.gamesModel.editEntry(loaderEditor.item.text, styleData.row, styleData.column)
                            tableView.selection.deselect(0, tableView.rowCount - 1)
                        }
                    }
                    sourceComponent: styleData.selected ? ( styleData.role === "winner" ? winnerEditor : editor) : null
                    Component {
                        id: editor
                        TextInput {
                            id: textinput
                            color: styleData.textColor
                            text: styleData.value
                            MouseArea {
                                id: mouseArea
                                anchors.fill: parent
                                hoverEnabled: true
                                onClicked: textinput.forceActiveFocus()
                            }
                        }
                    }
                    Component {
                        id: winnerEditor
                        ComboBox {
                            id: combobox
                            model: gmediator.players

                            onCurrentIndexChanged: {
                                if (find(styleData.value) > 0) {
                                    gmediator.gamesModel.editEntry(combobox.model[currentIndex], styleData.row, styleData.column)
                                    tableView.selection.deselect(0, tableView.rowCount - 1)
                                }
                            }

                            Component.onCompleted: gmediator.getPlayers(gmediator.gamesModel ? gmediator.gamesModel.gameId(styleData.row) : 0, true)
                        }
                    }
                }
            }
        }
    }
}
