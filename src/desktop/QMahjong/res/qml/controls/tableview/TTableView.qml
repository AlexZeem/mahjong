import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

TableView {
    style: TableViewStyle {
        textColor: cScheme.textColor
        backgroundColor: cScheme.itemBackgroungColor
        alternateBackgroundColor: cScheme.backgroungColor

        frame: Rectangle {}

        headerDelegate: TText {
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            text: styleData.value
        }

        itemDelegate: TItemDelegate {}

        rowDelegate: TRowDelegate {
           focused: styleData.selected
        }
    }
}

