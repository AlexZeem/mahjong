import QtQuick 2.4

import "../"
import "wall"

Item {
    id: root
    readonly property real tableWidth  : 600
    readonly property real tableHeight  : 600

    width: tableWidth
    height: tableHeight

    Image {
        id: table
        anchors.fill: root
        fillMode: Image.PreserveAspectFit
        source: "qrc:///res/icons/table/background.png"
    }

    TopWall {
        id: topWall
        anchors {
            left: table.left
            top: table.top
            leftMargin: 42
        }
    }

    RightWall {
        id: rightWall
        anchors {
            right: table.right
            top: table.top
            rightMargin: 60
        }
    }

//    WallBase {
//        state: "right"
//        anchors {
//            right: table.right
//            top: table.top
//        }
//    }

//    WallBase {
//        state: "bottom"
//        anchors {
//            left: table.left
//            bottom: table.bottom
//            bottomMargin: 80
//        }
//    }

    //    WallBase {
    //        state: "left"
    //        anchors {
    //            left: table.left
    //            top: table.top
    //        }
    //    }

}
