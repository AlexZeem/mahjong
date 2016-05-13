import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    id: control
    signal checkedChanged

    CheckBox {
        id: box
        anchors.centerIn: parent
        style: CheckBoxStyle {
            indicator:  Rectangle {
                implicitWidth: nConst.moreBtnWidth
                implicitHeight: nConst.moreBtnHeight
                radius: nConst.btnRadius
                border {
                    width: nConst.borderWidth
                    color: cScheme.border
                }
                color: cScheme.backgroung
                Rectangle {
                    visible: control.checked
                    color: cScheme.focusedBtnText
                    radius: nConst.btnRadius
                    border {
                        width: nConst.borderWidth
                        color: cScheme.border
                    }
                    anchors.margins: nConst.chBoxMargin
                    anchors.fill: parent
                }
            }
        }

        onCheckedChanged: control.checkedChanged()
    }
}
