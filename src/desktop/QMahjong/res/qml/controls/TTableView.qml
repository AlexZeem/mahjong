import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

TableView {

    style: TableViewStyle {
        headerDelegate: Rectangle {
            height: textItem.implicitHeight * 1.2
            width: textItem.implicitWidth
            color: cScheme.textColor
            border.color: cScheme.borderColor
            radius: nConst.cornerRadius
            Text {
                id: textItem
                anchors.fill: parent
                anchors.leftMargin: 12
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: styleData.textAlignment
                text: styleData.value
                elide: Text.ElideRight
                color: cScheme.itemBackgroungColor
            }
        }
        textColor: cScheme.textColor
    }
    horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
} // end tableview
