import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    id: control
    width: btn.implicitWidth
    height: btn.implicitHeight
    property alias text: btn.text
    signal clicked

    Button {
        id: btn
        style: ButtonStyle {
            background: Canvas {
                id: canvas
                implicitWidth: nConst.backBtnWidth
                implicitHeight: nConst.backBtnHeight
                antialiasing: true

                property color strokeStyle:  cScheme.border
                property color fillStyle: cScheme.backgroung
                property int lineWidth: nConst.borderWidth
                property bool fill: true
                property bool stroke: true

                onLineWidthChanged:requestPaint()
                onFillChanged:requestPaint()
                onStrokeChanged:requestPaint()

                onPaint: {
                    var ctx = canvas.getContext('2d')
                    ctx.save()
                    ctx.clearRect(0, 0, canvas.width, canvas.height)
                    ctx.strokeStyle = canvas.strokeStyle
                    ctx.fillStyle = canvas.fillStyle
                    ctx.lineWidth = canvas.lineWidth

                    ctx.beginPath()
                    ctx.moveTo(0, btn.height / 2)
                    ctx.lineTo(btn.height / 2, 0)
                    ctx.lineTo(btn.width - btn.height / 4, 0)
                    ctx.quadraticCurveTo(btn.width, 0, btn.width, btn.height / 4)
                    ctx.lineTo(btn.width, btn.height - btn.height / 4)
                    ctx.quadraticCurveTo(btn.width, btn.height, btn.width  - btn.height / 4, btn.height)
                    ctx.lineTo(btn.height / 2, btn.height)
                    ctx.closePath()

                    if (canvas.fill) ctx.fill()
                    if (canvas.stroke) ctx.stroke()
                    ctx.restore();
                }
            }

            label: Component {
                Text {
                    anchors.fill: parent
                    text: btn.text
                    clip: true
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter

                    color: btn.pressed ? cScheme.focusedBtnText : cScheme.btnText
                    font {
                        weight: Font.DemiBold
                        pixelSize: nConst.btnTextSize
                    }
                }
            }
        }

        onClicked: {
            console.log("Back button clicked")
            control.clicked()
        }
    }
}
