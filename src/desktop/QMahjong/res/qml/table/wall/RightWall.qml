import QtQuick 2.0

Item {
    id: root

    WallBase {
        id: topRow
        state: "horizontal"
        wallLength: 2
        height: 42
        width: 30*2
    }

    WallBase {
        id: middleCol
        state: "vertical"
        anchors {
            top: topRow.bottom
            right: topRow.right
        }
    }

    WallBase {
        id: bottomCol
        state: "vertical"
        //height: 20
        wallLength: 2
        tileWidth: 18
        tileImage: "qrc:///res/icons/tiles/other/tileSide.png"

        anchors {
            top: middleCol.bottom
            right: middleCol.right
            topMargin: 30*18
        }
    }
}


