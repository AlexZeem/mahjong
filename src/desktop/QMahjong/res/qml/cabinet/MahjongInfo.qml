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
            columns: 3
            anchors {
                top: parent.top
                left: parent.left
            }

            TLableText {
                text: qsTr("Mahjongs: ")
            }
            TTextInput {
                width: 50
                text: ginfomediator.countMahjong
                readOnly: true
                horizontalAlignment: TextInput.AlignHCenter
            }

            TLableText {
                text: qsTr(" ")
                color: cScheme.itemBackgroungColor
            }

            TLableText {
                text: qsTr("Best:")
            }
            TTextInput {
                width: 50
                text: ginfomediator.bestMahjong
                readOnly: true
                horizontalAlignment: Text.AlignHCenter
            }
            TTextInput {
                text: ginfomediator.bestMDate
                readOnly: true
                horizontalAlignment: Text.AlignHCenter
            }

            TLableText {
                text: qsTr("Worst:")
            }
            TTextInput {
                width: 50
                text: ginfomediator.worstMahjong
                readOnly: true
                horizontalAlignment: Text.AlignHCenter
            }
            TTextInput {
                text: ginfomediator.worstMDate
                readOnly: true
                horizontalAlignment: Text.AlignHCenter
            }
        } // end grid
    }
