import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root

    TableView {
        id: tableView
        width: 450
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
                            console.log("onAccepted", styleData.row, styleData.role)
                            gmediator.gamesModel.editItem(loaderEditor.item.text, styleData.row, styleData.column, styleData.role)
                        }
                    }
                    sourceComponent: styleData.selected ? editor : null
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
                }
            }
        }
    }
}
