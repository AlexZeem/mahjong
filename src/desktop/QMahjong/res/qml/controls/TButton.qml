import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Button {
    id: btn
    property string text: ""
    style: ButtonStyle {
        background: Rectangle {
            id: styleRect
            implicitWidth: 75
            implicitHeight: 25
            radius: 5
            border {
                width: 1
                color: cScheme.borderColor
            }
        }
        label: Text {
            text: btn.text
            color: btn.pressed ? cScheme.activeFocusTextColor : cScheme.inactiveFocusTextColor
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
