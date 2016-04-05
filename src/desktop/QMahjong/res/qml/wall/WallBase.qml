import QtQuick 2.0
import "../tile"

Item {
    property real wallLength: 18
    property string tileState: "face"

    Loader {
        id: loader
        sourceComponent: row
    }

    Component {
           id: row
           Row {
               spacing: 0
               Repeater {
                   model: wallLength
                   TileBase {
                       state: tileState + "Up"
                   }
               }
           }
       }

    Component {
           id: column
           Column {
               spacing: 0
               Repeater {
                   model: wallLength
                   TileBase {
                       state: tileState + "Rotate"
                   }
               }
           }
       }

    states: [
        State {
            name: "horizontal"
            PropertyChanges { target: loader; sourceComponent: row;}
        },
        State {
            name: "vertical"
            PropertyChanges { target: loader; sourceComponent: column;}
        }
    ]
}
