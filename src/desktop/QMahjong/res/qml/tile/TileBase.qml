import QtQuick 2.4

Item {
    id: root
    readonly property real tileWidth: 25
    readonly property real tileHeight: 35
    readonly property real tileDepth: 15
    property string imagePath: ""
    property bool faceVisible: true
    property bool sideVisible: true

    Item {
        anchors.fill: parent
        Image {
            id: face
            fillMode: Image.PreserveAspectFit
        }
        Image {
            id: side
            fillMode: Image.PreserveAspectFit
        }
    }

    states: [
        State {
            name: "HLUp" //horisontal lying face up
            PropertyChanges { target: face; source: imagePath; width: tileHeight; height: tileWidth; visible: faceVisible }
            PropertyChanges { target: side; source: "qrc:///res/icons/tiles/other/tileSideH.png"; width: tileHeight; height: tileDepth; anchors.top: face.bottom; visible: sideVisible }
        },
        State {
            name: "HLDown" //horisontal lying face down
            PropertyChanges { target: face; source: "qrc:///res/icons/tiles/other/tileBackH.png"; width: tileHeight; height: tileWidth; visible: faceVisible }
            PropertyChanges { target: side; source: "qrc:///res/icons/tiles/other/tileSideH.png"; width: tileHeight; height: tileDepth; anchors.top: face.bottom; visible: sideVisible }
        },
        State {
            name: "VSForward" //vertical standing face forward
            PropertyChanges { target: face; source: "qrc:///res/icons/tiles/other/tileBottom.png"; width: tileWidth; height: tileDepth; visible: faceVisible }
            PropertyChanges { target: side; source: imagePath; width: tileWidth; height: tileDepth; anchors.top: face.bottom; visible: sideVisible }
        },
        State {
            name: "VSBackward" //vertical standing face backward
            PropertyChanges { target: face; source: "qrc:///res/icons/tiles/other/tileBottom.png"; width: tileWidth; height: tileDepth; visible: faceVisible }
            PropertyChanges { target: side; source: "qrc:///res/icons/tiles/other/tileBackV.png"; width: tileWidth; height: tileHeight; anchors.top: face.bottom; visible: sideVisible }
        },
        State {
            name: "VSRight" //vertical standing face right
            PropertyChanges { target: face; source: "qrc:///res/icons/tiles/other/tileBottom.png"; width: tileDepth; height: tileWidth; visible: faceVisible }
            PropertyChanges { target: side; source: "qrc:///res/icons/tiles/other/tileSideVR.png"; width: tileDepth; height: tileHeight; anchors.top: face.bottom; visible: sideVisible }
        },
        State {
            name: "VSLeft" //vertical standing face left
            PropertyChanges { target: face; source: "qrc:///res/icons/tiles/other/tileBottom.png"; width: tileDepth; height: tileWidth; visible: faceVisible }
            PropertyChanges { target: side; source: "qrc:///res/icons/tiles/other/tileSideVL.png"; width: tileDepth; height: tileHeight; anchors.top: face.bottom; visible: sideVisible }
        }
    ]
}
