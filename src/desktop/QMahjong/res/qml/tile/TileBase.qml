import QtQuick 2.4

Item {
    id: root
    readonly property real tileWidth: 25
    readonly property real tileHeight: 35
    readonly property real tileDepth: 15

    state: "faceUp"

    Image {
        id: tile
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    states: [
        State {
            name: "faceUp"
            PropertyChanges { target: root; width: tileWidth; height: tileHeight}
            PropertyChanges { target: tile; source: "qrc:///res/icons/tiles/other/tileBack.png"}
        },
        State {
            name: "sideUp"
            PropertyChanges { target: root; width: tileHeight; height: tileDepth}
            PropertyChanges { target: tile; source: "qrc:///res/icons/tiles/other/tileSide.png"}
        },
        State {
            name: "bottomUp"
            PropertyChanges { target: root; width: tileWidth; height: tileDepth}
            PropertyChanges { target: tile; source: "qrc:///res/icons/tiles/other/tileBottom.png"}
        },
        State {
            name: "faceRotate"
            PropertyChanges { target: root; width: tileHeight; height: tileWidth}
            PropertyChanges { target: tile; source: "qrc:///res/icons/tiles/other/tileBackRotate.png"}
        },
        State {
            name: "sideRotate"
            PropertyChanges { target: root; width: tileDepth; height: tileWidth}
            PropertyChanges { target: tile; source: "qrc:///res/icons/tiles/other/tileSideRotate.png"}
        },
        State {
            name: "bottomRotate"
            PropertyChanges { target: root; width: tileDepth; height: tileWidth}
            PropertyChanges { target: tile; source: "qrc:///res/icons/tiles/other/tileBottomRotate.png"}
        }
    ]
}
