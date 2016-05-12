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

    Grid {
        id: body
        columns: 2
        spacing: 5
        anchors {
            margins: nConst.margin
            top: parent.top
            left: parent.left
            right: parent.right
        }

        TLableText {
            text: qsTr("Last Game: ")
        }
        TText {
            text: qsTr(new Date().toLocaleDateString(Locale.ShortFormat))
        }

        TLableText {
            text: qsTr("Participated in: ")
        }
        TText {
            text: "2"
        }
    }

    TButton {
        id: button
        width: nConst.moreBtnWidth
        anchors {
            top: body.bottom
            topMargin: nConst.margins
            right: body.right
        }

        text: qsTr("...")

        onClicked: {
            console.log("More in button clicked")
            fsmEvent.gameStat()
        }
    }
}
