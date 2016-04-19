import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: root;

    Rectangle {
        anchors.fill: parent

        Button {
            id: button
            text: qsTr("Back")
            anchors {
                top: parent.top
                right: parent.right
                topMargin: 15
                rightMargin: 15
            }
            onClicked: {
                console.log ("Back is pressed")
                fsmEvent.back()
            }
        }

        Component {
            id: detailsBtnDelegate
            Item{
                Button {
                    text: qsTr("see more")
                    height: 15;
                    onClicked: {
                        console.log ("User wants more")
                        fsmEvent.gameDetails()
                    }
                }
            }
        }

        ListModel {
            id: gameStatModel
            ListElement {
                date: "12/03/2012"
                personalScore: -126
                winner: "Player 1"
            }
        }
            TableView {
                id: gameStatTable
                anchors {
                    top: button.bottom
                    topMargin: 15
                }
                model: gameStatModel
                width: root.width

                TableViewColumn {
                    role: "date"
                    title: "Date"
                    width: 120;
                }
                TableViewColumn {
                    role: "personalScore"
                    title: "Personal score"
                    width: 120
                }
                TableViewColumn {
                    role: "winner"
                    title: "Winner"
                    width: 120;
                }
                TableViewColumn {
                    role: "details"
                    title: "Details"
                    delegate: detailsBtnDelegate
                    width: 120
                }
            }
        }

    }
