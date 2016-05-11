import QtQuick 2.0
import QtQuick.Controls 1.3
import "../controls"

Item {
    id: root

    TItem {
        id: background
        focused: true
        anchors.fill: parent
    }

    Column {
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
            topMargin: 15
        }

        Row {
            id: limits
            Text {
                text: qsTr("Limits: ")
            }
            Text {
                width: 25
                text: "2"
            }
        }

        TableView {
            id: table
            TableViewColumn {
                role: "name"
                title: qsTr("Name")
                width: 120
            }
            TableViewColumn {
                role: "date"
                title: qsTr("Date")
                width: 70
            }
            model: limitsModel
        }
    }

    ListModel {
        id: limitsModel
        ListElement {
            name: qsTr("13 orphans")
            date: "13/11/16"
        }
        ListElement {
            name: qsTr("Imperial jade")
            date: "13/11/16"
        }
        ListElement {
            name: qsTr("Heads and Tails")
            date: "13/11/16"
        }
    }
}
