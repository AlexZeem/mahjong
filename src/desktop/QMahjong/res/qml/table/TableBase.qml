import QtQuick 2.4

Item {
    id: root

    width: 360
    height: 360

    Image {
        id: table
        anchors.fill: root
        fillMode: Image.PreserveAspectFit
        source: "qrc:///res/icons/table/background.png"
    }

    WallBase {
        state: "top"
        anchors {
            left: table.left
            top: table.top
        }
    }

    WallBase {
        state: "right"
        anchors {
            right: table.right
            top: table.top
        }
    }

    WallBase {
        state: "bottom"
        anchors {
            left: table.left
            bottom: table.bottom
        }
    }

    WallBase {
        state: "left"
        anchors {
            left: table.left
            top: table.top
        }
    }

}
