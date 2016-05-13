import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

TableView {
    style: TableViewStyle {
        textColor: cScheme.label
        backgroundColor: cScheme.backgroung
        alternateBackgroundColor: cScheme.backgroungItem

        frame: Rectangle {}

        headerDelegate: THeaderDelegate{}

        rowDelegate: TRowDelegate {}

        itemDelegate: TTextDelegate {}
    }
}

