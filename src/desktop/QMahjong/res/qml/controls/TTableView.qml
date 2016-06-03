import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

TableView {
    horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
    highlightOnFocus: true

    style: TableViewStyle {
        headerDelegate: Rectangle {
            height: textItem.implicitHeight * 1.2
            width: textItem.implicitWidth
            color: cScheme.tableHeaderBGColor
            border.color: cScheme.borderColor
            radius: nConst.cornerRadius
            Text {
                id: textItem
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: styleData.value
                color: cScheme.tableHeaderTextColor
                elide: styleData.elideMode
            }
        }
    }
} // end tableview
