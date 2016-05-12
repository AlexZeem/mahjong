import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Button {
    id: btn
    property string text: ""
    style: ButtonStyle {
        background: Rectangle {
            id: styleRect
            implicitWidth: nConst.btnImplicitWidth
            implicitHeight: nConst.btnImplicitHeight
            radius: nConst.cornerRadius
            border {
                width: nConst.borderWidth
                color: cScheme.borderColor
            }
        }
        label: Text {
            text: btn.text
            color: btn.pressed ? cScheme.activeFocusTextColor : cScheme.inactiveFocusTextColor
            font.pixelSize: nConst.btnPixelSize
            horizontalAlignment: Text.AlignHCenter
        }
    }

    onClicked: focus = true
}
