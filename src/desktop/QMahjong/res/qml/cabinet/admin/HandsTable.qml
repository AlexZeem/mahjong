import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root

    TableView {
        id: tableView
        width: 500
        frameVisible: true

        TableViewColumn {
            id: windColumn
            title: "W"
            role: "wind"
            movable: false
            resizable: false
            width: 30
        }

        TableViewColumn {
            id: mahjong1Column
            title:"M"
            role: "mahjong1"
            movable: false
            resizable: false
            width: (tableView.viewport.width  - 30) / 20
        }

        TableViewColumn {
            id: combo1Column
            title: "Combo"
            role: "combo1"
            movable: false
            resizable: false
            width: (tableView.viewport.width  - 30) / 10
        }

        TableViewColumn {
            id: score1Column
            title: "Score"
            role: "score1"
            movable: false
            resizable: false
            width: (tableView.viewport.width  - 30) / 10
        }

        TableViewColumn {
            id: mahjong2Column
            title:"M"
            role: "mahjong2"
            movable: false
            resizable: false
            width: (tableView.viewport.width  - 30) / 20
        }

        TableViewColumn {
            id: combo2Column
            title: "Combo"
            role: "combo2"
            movable: false
            resizable: false
            width: (tableView.viewport.width  - 30) / 10
        }

        TableViewColumn {
            id: score2Column
            title: "Score"
            role: "score2"
            movable: false
            resizable: false
            width: (tableView.viewport.width  - 30) / 10
        }

        TableViewColumn {
            id: mahjong3Column
            title:"M"
            role: "mahjong3"
            movable: false
            resizable: false
            width: (tableView.viewport.width  - 30) / 20
        }

        TableViewColumn {
            id: combo3Column
            title: "Combo"
            role: "combo3"
            movable: false
            resizable: false
            width: (tableView.viewport.width  - 30) / 10
        }

        TableViewColumn {
            id: score3Column
            title: "Score"
            role: "score3"
            movable: false
            resizable: false
            width: (tableView.viewport.width  - 30) / 10
        }

        TableViewColumn {
            id: mahjong4Column
            title:"M"
            role: "mahjong4"
            movable: false
            resizable: false
            width: (tableView.viewport.width  - 30) / 20
        }

        TableViewColumn {
            id: combo4Column
            title: "Combo"
            role: "combo4"
            movable: false
            resizable: false
            width: tableView.viewport.width / 10
        }

        TableViewColumn {
            id: score4Column
            title: "Score"
            role: "score4"
            movable: false
            resizable: false
            width: tableView.viewport.width / 10
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
                            //gmediator.gamesModel.editItem(loaderEditor.item.text, styleData.row, styleData.column, styleData.role)
                            tableView.selection.deselect(0, tableView.model.length - 1)
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
                            id: winners
                            model: gmediator.gamesModel.players(tableView.currentRow)
                            currentIndex: 0

                            onCurrentIndexChanged: {
                                if (currentText !== "") {
                                    if (styleData.row > -1)
                                        gmediator.gamesModel.editItem(currentText, styleData.row, styleData.column, styleData.role)
                                    tableView.selection.deselect(0, tableView.model.length - 1)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
