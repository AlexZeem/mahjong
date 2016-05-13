import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    id: control
    property alias text: btn.text
    signal clicked

    Button {
        id: btn
        anchors.centerIn: parent
        style: ButtonStyle {
            background: Rectangle {
                implicitWidth: nConst.moreBtnWidth
                implicitHeight: nConst.moreBtnHeight
                radius: nConst.btnRadius
                border {
                    width: nConst.borderWidth
                    color: cScheme.border
                }
                color: cScheme.backgroung
            }
            label: Component {
                Text {
                    anchors.fill: parent
                    text: "..."
                    clip: true
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter

                    color: btn.pressed ? cScheme.focusedBtnText : cScheme.label
                    font.pixelSize: nConst.labelSize
                }
            }
        }

        onClicked: control.clicked()
    }
}
