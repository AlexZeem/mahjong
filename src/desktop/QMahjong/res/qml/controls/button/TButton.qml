import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Button {
    id: btn

    style: ButtonStyle {
        background: Rectangle {
            id: styleRect
            implicitWidth: nConst.btnWidth
            implicitHeight: nConst.btnHeight
            radius: nConst.radius
            border {
                width: nConst.border
                color: cScheme.border
            }
        }
        label: Text {
            text: btn.text
            clip: true
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            color: btn.pressed ? cScheme.activeText : cScheme.inactiveText
            font {
                weight: Font.DemiBold
                pixelSize: nConst.btnTextSize
            }
        }
    }

    onClicked: focus = true
}
