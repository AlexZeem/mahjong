import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root

    Button {
        id: addNew
        text: qsTr("Add new")
        anchors {
            top: parent.top
            left: parent.left
        }
        onClicked: {
            users.addEntry()
        }
    }

    Button {
        id: deleteSelected
        text: qsTr("Delete")
        anchors {
            top: parent.top
            right: parent.right
        }
        onClicked: {
            users.removeEntry(tableView.currentRow)
        }
    }

    TableView {
        id: tableView
        anchors {
            top: addNew.bottom
            topMargin: 15
            left: parent.left
            right: parent.right
        }
        frameVisible: true

        TableViewColumn {
            id: loginColumn
            title: "Login"
            role: "login"
            movable: false
            resizable: false
            width: tableView.viewport.width / 7
        }

        TableViewColumn {
            id: passColumn
            title: "Password"
            role: "pass"
            movable: false
            resizable: false
            width: tableView.viewport.width / 7
        }

        TableViewColumn {
            id: nameColumn
            title: "Name"
            role: "name"
            movable: false
            resizable: false
            width: tableView.viewport.width / 7
        }

        TableViewColumn {
            id: surnameColumn
            title: "Surname"
            role: "surname"
            movable: false
            resizable: false
            width: tableView.viewport.width / 7
        }

        TableViewColumn {
            id: phoneColumn
            title: "Phone"
            role: "phone"
            movable: false
            resizable: false
            width: tableView.viewport.width / 7
        }

        TableViewColumn {
            id: emailColumn
            title: "Email"
            role: "email"
            movable: false
            resizable: false
            width: tableView.viewport.width / 7
        }

        TableViewColumn {
            id: rangColumn
            title: "Rang"
            role: "rang"
            movable: false
            resizable: false
            width: tableView.viewport.width / 7
        }

        model: users

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
                            users.editEntry(loaderEditor.item.text, styleData.row, styleData.column)
                            tableView.selection.deselect(0, tableView.rowCount - 1)
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
