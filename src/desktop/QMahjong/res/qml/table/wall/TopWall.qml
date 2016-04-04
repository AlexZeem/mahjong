import QtQuick 2.0

Item {
    id: root

    WallBase {
        id: topRow
        state: "horizontal"
        wallLength: 16
        height: 42
    }

    WallBase {
        id: middleRow
        state: "horizontal"
        height: 20
        wallLength: 16
        tileWidth: 30
        tileHeight: 20
        tileImage: "qrc:///res/icons/tiles/other/tileBottom.png"

        anchors {
            top: topRow.bottom
        }
    }

    WallBase {
        id: bottomRow
        state: "horizontal"
        height: 20
        wallLength: 16
        tileWidth: 30
        tileHeight: 20
        tileImage: "qrc:///res/icons/tiles/other/tileBottom.png"

        anchors {
            top: middleRow.bottom
        }
    }
}


