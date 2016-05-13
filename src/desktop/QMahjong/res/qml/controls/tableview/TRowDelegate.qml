import QtQuick 2.0
import "../"

Item {
    id: control
    height: nConst.tableRowHeight

    TBackgroundItem {
        id: background
        anchors.fill: parent
        color: cScheme.backgroung

        TItem {
            id: row
            anchors.fill: parent
            anchors.margins: 4 * nConst.borderWidth
            color: styleData.selected ? cScheme.tableHighlighter : cScheme.backgroungItem
        }
    }
}

