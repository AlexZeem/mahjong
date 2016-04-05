import QtQuick 2.0

Item {
    id: root

    WallBase {
        id: top
        state: "horizontal"
        height: 35
    }

    WallBase {
        id: middle
        state: "horizontal"
        tileState: "bottom"
        height: 15
        anchors {
            top: top.bottom
            //topMargin: -2
        }
    }

    WallBase {
        id: bottom
        state: "horizontal"
        tileState: "bottom"
        anchors {
            top: middle.bottom
            //topMargin: -4
        }
    }
}


