import QtQuick 2.0

Item {
    id: wall

    Row {
        Repeater {
            model: 18
            Image {
                id: tile
                width: 20
                height: 42
                fillMode: Image.PreserveAspectFit
                source: "qrc:///res/icons/tiles/other/tileBack.png"
            }
        }
    }

    states: [
        State {
            name: "top"
            PropertyChanges { target: wall }
        },
        State {
            name: "right"
            PropertyChanges { target: wall; rotation: 90 }
        },
        State {
            name: "bottom"
            PropertyChanges { target: wall }
        },
        State {
            name: "left"
            PropertyChanges { target: wall; rotation: 90 }
        }
    ]
}
