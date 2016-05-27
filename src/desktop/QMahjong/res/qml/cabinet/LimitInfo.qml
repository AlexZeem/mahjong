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
    Row {
        id: limits
        anchors {
            top: background.top
            topMargin: 15
            left: background.left
            leftMargin: 15
        }
        TLableText {
            text: qsTr("Limits: ")
            horizontalAlignment: TLableText.AlignHCenter
        }
        TTextInput {
            width: 50
            text: ginfomediator.countLimit
            readOnly: true
            horizontalAlignment: TextInput.AlignHCenter
        }
    }// end row

    TTableView {
        id: table
        anchors {
            top: limits.bottom
            topMargin: 15
            horizontalCenter: background.horizontalCenter
        }
        implicitWidth: 250
        TableViewColumn {
            role: "name"
            title: qsTr("Name")
            width: 175
        }
        TableViewColumn {
            role: "date"
            title: qsTr("Date")
            width: 80
        }
        model: ginfomediator.ulimit
    }
}
