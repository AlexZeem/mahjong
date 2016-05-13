import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    id: control
    property alias text: btn.text
    signal clicked

    Button {
        id: btn
        style: ButtonStyle {
            background: /*Rectangle {
                implicitWidth: nConst.btnImplicitWidth
                implicitHeight: nConst.btnImplicitHeight
                radius: nConst.btnRadius
                border {
                    width: nConst.borderWidth
                    color: cScheme.border
                }
                color: cScheme.backgroung


            }*/
                Canvas {
                id: canvas
                implicitWidth: nConst.btnImplicitWidth
                implicitHeight: nConst.btnImplicitHeight
                antialiasing: true

                property color strokeStyle:  Qt.darker(fillStyle, 1.6)
                property color fillStyle: cScheme.backgroung
                property int lineWidth: nConst.borderWidth
                property bool fill: true
                property bool stroke: true

                onLineWidthChanged:requestPaint();
                onFillChanged:requestPaint();
                onStrokeChanged:requestPaint();

                onPaint: {
                    var ctx = canvas.getContext('2d');
                    var originX = btn.horizontalCenter
                    var originY = btn.verticalCenter
                    ctx.save();
                    ctx.clearRect(0, 0, canvas.width, canvas.height);
                    ctx.translate(originX, originX);
                    ctx.globalAlpha = canvas.alpha;
                    ctx.strokeStyle = canvas.strokeStyle;
                    ctx.fillStyle = canvas.fillStyle;
                    ctx.lineWidth = canvas.lineWidth;

                    ctx.beginPath();
                    ctx.moveTo(75 + 50  * Math.cos(0),
                               75 - 50  * Math.sin(Math.PI*2));
                    ctx.arc(75,75,50,0,Math.PI*2,true); // Outer circle
                    ctx.moveTo(75,70);
                    ctx.arc(75,70,35,0,Math.PI,false);   // Mouth (clockwise)
                    ctx.moveTo(60,65);
                    ctx.arc(60,65,5,0,Math.PI*2,true);  // Left eye
                    ctx.moveTo(90 + 5  * Math.cos(0),
                               65 - 5  * Math.sin(Math.PI*2));
                    ctx.moveTo(90,65);
                    ctx.arc(90,65,5,0,Math.PI*2,true);  // Right eye
                    ctx.closePath();
                    if (canvas.fill)
                        ctx.fill();
                    if (canvas.stroke)
                        ctx.stroke();
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
