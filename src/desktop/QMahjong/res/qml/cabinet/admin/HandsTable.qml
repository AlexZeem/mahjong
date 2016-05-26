import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root
    property alias selectedRow: tableView.currentRow
    property int gameSelected: -1
    onGameSelectedChanged: {
        gmediator.handsModel.setGame(gmediator.gamesModel ? gmediator.gamesModel.gameId(gameSelected) : 0)
    }

    TableView {
        id: tableView
        anchors.fill: parent
        frameVisible: true

        TableViewColumn {
            id: windColumn
            title: "W"
            role: "wind"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: mahjong1Column
            title: "M"
            role: "mahjong1"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: combo1Column
            title: "C 1"
            role: "combo1"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: score1Column
            title: "S 1"
            role: "score1"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: mahjong2Column
            title: "M"
            role: "mahjong2"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: combo2Column
            title: "C 2"
            role: "combo2"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: score2Column
            title: "S 2"
            role: "score2"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: mahjong3Column
            title: "M"
            role: "mahjong3"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: combo3Column
            title: "C 3"
            role: "combo3"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: score3Column
            title: "S 3"
            role: "score3"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: mahjong4Column
            title: "M"
            role: "mahjong4"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: combo4Column
            title: "C 4"
            role: "combo4"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: score4Column
            title: "S 4"
            role: "score4"
            movable: false
            resizable: false
            width: tableView.viewport.width / 14
        }

        TableViewColumn {
            id: limitColumn
            title: "L"
            role: "limit"
            movable: false
            resizable: false
        }

        model: gmediator.handsModel

        itemDelegate: Component {
            id: editableDelegate
            Item {
                Text {
                    id: itemText
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
                            gmediator.handsModel.editEntry(loaderEditor.item.text, styleData.row, styleData.column)
                            tableView.selection.deselect(0, tableView.rowCount - 1)
                        }
                    }
                    sourceComponent: styleData.selected ? ( styleData.role === "limit" ? limitEditor : editor) : null

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
                        id: limitEditor
                        ComboBox {
                            id: combobox
                            model: gmediator.limits
                            currentIndex: find(styleData.value)

                            onCurrentIndexChanged: {
                                if (model.length > 0 && currentIndex > -1 && currentText !== "") {
                                    gmediator.handsModel.editEntry(model[currentIndex], styleData.row, styleData.column)
                                    tableView.selection.deselect(0, tableView.rowCount - 1)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
