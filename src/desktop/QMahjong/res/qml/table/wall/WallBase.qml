import QtQuick 2.0

Item {
    id: root
    property real tileWidth : 30
    property real tileHeight : 42
    property real wallLength: 18
    property string tileImage: "qrc:///res/icons/tiles/other/tileBack.png"

    Row {
        id: wall
        spacing: 0
        Repeater {
            model: wallLength
            Image {
                id: tile
                width: tileWidth
                height: tileHeight
                fillMode: Image.PreserveAspectFit
                source: tileImage
            }
        }
    }

    states: [
        State {
            name: "horizontal"
            PropertyChanges { target: root;}
        },
        State {
            name: "vertical"
            PropertyChanges { target: root; rotation: 90; }
        }
    ]
}
