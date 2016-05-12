import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    id: control
    property alias text: input.text
    property alias maximumLength: input.maximumLength
    property alias echoMode: input.echoMode
    signal accepted
    signal editingFinished

    TextField {
        id: input
        maximumLength: nConst.inputLength
        style: TextFieldStyle {
            textColor: input.activeFocus ? cScheme.focusedInputText : cScheme.inputText
            background: Rectangle {
                anchors.margins: nConst.margin
                radius: nConst.inputRadius
                border {
                    width: nConst.borderWidth
                    color: cScheme.border
                }
            }
        }
        font.pixelSize: nConst.inputTextSize

        onAccepted: control.accepted
        onEditingFinished: control.editingFinished
    }
}

