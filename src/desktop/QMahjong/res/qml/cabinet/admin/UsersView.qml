import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root

    TextField {
        id: searchBox
        width: parent.width / 8 * 2
        anchors.right: parent.right

        placeholderText: "Search..."
        inputMethodHints: Qt.ImhNoPredictiveText
    }

    TableView {
        id: tableView
        anchors {
            top: searchBox.bottom
            left: parent.left
            right: parent.right
            topMargin: 15
        }
        frameVisible: false
        sortIndicatorVisible: true

        TableViewColumn {
            id: loginColumn
            title: "Login"
            role: "login"
            movable: false
            resizable: false
            width: tableView.viewport.width / 8
        }

        TableViewColumn {
            id: passColumn
            title: "Password"
            role: "pass"
            movable: false
            resizable: false
            width: tableView.viewport.width / 8
        }

        TableViewColumn {
            id: nameColumn
            title: "Name"
            role: "name"
            movable: false
            resizable: false
            width: tableView.viewport.width / 8
        }

        TableViewColumn {
            id: surnameColumn
            title: "Surname"
            role: "surname"
            movable: false
            resizable: false
            width: tableView.viewport.width / 8
        }

        TableViewColumn {
            id: phoneColumn
            title: "Phone"
            role: "phone"
            movable: false
            resizable: false
            width: tableView.viewport.width / 8
        }

        TableViewColumn {
            id: emailColumn
            title: "Email"
            role: "email"
            movable: false
            resizable: false
            width: tableView.viewport.width / 8
        }

        TableViewColumn {
            id: rangColumn
            title: "Rang"
            role: "rang"
            movable: false
            resizable: false
            width: tableView.viewport.width / 8
        }
    }
}
