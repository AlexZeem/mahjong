import QtQuick 2.0
import QtQuick.Controls 1.3

ListView {
    id: list
    anchors.fill: parent
    delegate: TTextDelegate {}
    highlight: THighlightDelegate {}
    focus: true
}
