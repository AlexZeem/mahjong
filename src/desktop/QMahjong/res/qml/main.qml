import QtQuick 2.4

FocusScope {
    id: main

    Rectangle {
        color: "red"
        width: 100
        height: 100
    }

    Image {
        id: tile
        source: "qrc:///res/icons/tiles/bamboo/1.png"
    }
}
