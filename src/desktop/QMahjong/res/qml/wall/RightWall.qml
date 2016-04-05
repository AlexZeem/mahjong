import QtQuick 2.0

Item {
    id: root

    WallBase {
        id: top
        state: "vertical"
        height: 25*18
    }

    WallBase {
        id: middle
        state: "horizontal"
        tileState: "side"
        wallLength: 1
        height: 15
        anchors {
            top: top.bottom
        }
    }

    WallBase {
        id: bottom
        state: "horizontal"
        tileState: "side"
        wallLength: 1
        anchors {
            top: middle.bottom
        }
    }
}


