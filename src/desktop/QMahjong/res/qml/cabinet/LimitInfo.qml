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
            TLableText {
                text: qsTr("Limits: ")
            }
            TTextInput {
                width: 50
                text: ginfomediator.countLimit
                readOnly: true
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
            model: ginfomediator.ulimit
        }
    }
}
