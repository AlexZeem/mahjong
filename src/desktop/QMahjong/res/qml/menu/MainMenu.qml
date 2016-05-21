import QtQuick 2.4
import "../controls/background"
import "../controls/button"

Item {
    id: root

    TItem {
        id: background
        anchors.fill: parent
    }

    Grid {
        anchors.centerIn: parent
        columns: 2
        spacing: nConst.spacing

        TButton {
            id: itBtn
            width: 1.75 * nConst.btnWidth

            text: qsTr("Interactive table")
            onClicked: {
                fsmEvent.openIT()
            }
        }

        TButton {
            width: itBtn.width
            text: qsTr("Cabinet")
            onClicked: {
                fsmEvent.openCabinet()
            }
        }

        TButton {
            width: itBtn.width
            text: qsTr("Rules")
            onClicked: {
                fsmEvent.openRules()
            }
        }

        TButton {
            width: itBtn.width
            text: qsTr("News")
            onClicked: {
                fsmEvent.openNews()
            }
        }
    }
}
