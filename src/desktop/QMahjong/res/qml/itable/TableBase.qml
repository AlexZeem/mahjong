import QtQuick 2.0

Canvas {
    id: canvas
    implicitWidth: nConst.backBtnWidth
    implicitHeight: nConst.backBtnHeight
    antialiasing: true

    property color strokeStyle:  cScheme.border
    property color fillStyle: cScheme.backgroung
    property int lineWidth: nConst.border
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

        ctx.moveTo(0, nConst.tableSize - nConst.tableSize / 8)
        ctx.quadraticCurveTo(0, nConst.tableSize, nConst.tableSize / 8, nConst.tableSize)
        ctx.lineTo(nConst.tableSize - nConst.tableSize / 8, nConst.tableSize)
        ctx.quadraticCurveTo(nConst.tableSize, nConst.tableSize, nConst.tableSize, nConst.tableSize - nConst.tableSize / 8)

        ctx.lineTo(nConst.tableSize - nConst.tableSize / 16, nConst.tableSize / 8)
        ctx.quadraticCurveTo(nConst.tableSize - nConst.tableSize / 16, nConst.tableSize / 16,
                             nConst.tableSize - nConst.tableSize / 8, nConst.tableSize / 16)
        ctx.lineTo(nConst.tableSize / 8, nConst.tableSize / 16)
        ctx.quadraticCurveTo(nConst.tableSize / 16, nConst.tableSize / 16,
                             nConst.tableSize / 16, nConst.tableSize / 8)

        ctx.closePath()

        if (canvas.fill) ctx.fill()
        if (canvas.stroke) ctx.stroke()
        ctx.restore();
    }
}
