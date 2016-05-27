import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import "../controls"

Item {
    id: root

    TItem {
        id: background
        focused: true
        anchors.fill: parent
    }

    TButton {
        id: button
        text: qsTr("Back")
        anchors {
            top: parent.top
            right: parent.right
            topMargin: 15
            rightMargin: 15
        }
        onClicked: {
            console.log ("Back is pressed")
            fsmEvent.back()
        }
    }

    Component {
        id: detailsBtnDelegate
        Item{
            TButton {
                style: ButtonStyle {
                    label: Text {
                        text: qsTr("see more")
                        font.pixelSize: 10
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: cScheme.textColor
                    }
                }
                height: 15;
                onClicked: {
                    console.log ("User wants more")
                    fsmEvent.gameDetails()
                }
            }
        }
    }

    TTableView {
        id: gameStatTable
        anchors {
            top: button.bottom
            topMargin: 15
            horizontalCenter: background.horizontalCenter
            verticalCenter: background.verticalCenter
        }
        width: 480

        model: ginfomediator.gameDetail

        TableViewColumn {
            role: "date"
            title: "Date"
            width: 120;
        }
        TableViewColumn {
            role: "personalScore"
            title: "Personal score"
            width: 120
        }
        TableViewColumn {
            role: "winner"
            title: "Winner"
            width: 120;
        }
        TableViewColumn {
            role: "details"
            title: "Details"
            delegate: detailsBtnDelegate
            width: 120
        }
    }
}
