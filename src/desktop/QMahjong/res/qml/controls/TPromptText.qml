import QtQuick 2.0

Text {
    id: prompt
    property string promptText: ""

    text: "* " + prompt.promptText
    font.pixelSize: 10
    horizontalAlignment: Text.AlignRight
    color: cScheme.textColor
}
