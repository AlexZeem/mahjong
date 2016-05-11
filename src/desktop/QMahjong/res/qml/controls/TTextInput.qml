import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

TextField {
    id: input
    style: TextFieldStyle {
        textColor: input.activeFocus ? cScheme.activeFocusTextColor : cScheme.inactiveFocusTextColor
        background: Rectangle {
            radius: 5
            border {
                width: 1
                color: cScheme.borderColor
            }
        }
    }
}
