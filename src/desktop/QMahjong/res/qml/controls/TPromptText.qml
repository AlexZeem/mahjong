import QtQuick 2.0

Text {
    id: prompt
    property string promptText: ""

    text: "* " + prompt.promptText
    font.pixelSize: nConst.promptPixelSize
    horizontalAlignment: Text.AlignRight
    color: cScheme.lableTextColor
}
