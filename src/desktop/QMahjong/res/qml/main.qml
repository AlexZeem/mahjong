import QtQuick 2.4

import "table"
import "wall"
import "tile"

FocusScope {
    id: main

    width: 640
    height: 640

    TableBase {
        id: table
        anchors.centerIn: main

        TopWall {
            id: topWall
            width: 18*25
            anchors {
                left: table.left
                top: table.top
                leftMargin: 35
            }
        }

        RightWall {
            id: rightWall
            height: 25*18 + 25
            anchors {
                right: topWall.right
                top: table.top
                topMargin: 35
                rightMargin: 35
            }
        }

        BottomWall {
            id: bottomWall
            width: 18*25
            anchors {
                right: rightWall.left
                bottom: rightWall.bottom
                bottomMargin: 60
            }
        }

        LeftWall {
            id: lefttWall
            anchors {
                left: bottomWall.left
                top: table.top
            }
        }
    }

}
