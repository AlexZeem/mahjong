import QtQuick 2.4
import "../controls/background"

Item {
    id: root

    TItem {
        id: background
        anchors.fill: parent
    }

    TableBase {
        anchors.centerIn: parent
        implicitWidth: nConst.tableSize
        implicitHeight: nConst.tableSize
    }
}
