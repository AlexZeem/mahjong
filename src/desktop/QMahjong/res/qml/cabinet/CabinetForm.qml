import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    id: root
    height: main.height
    width: main.width


    Column{
        id: playerInfo
        spacing: 5
        anchors {
            top: playerGB.top;
            horizontalCenter: playerGB.horizontalCenter;
        }

        GroupBox {
            title: qsTr("Player info");

            Image {
                id: avatar
                source: "UserIcon.png"
                width: 150;
                height: 150;
            }
            Grid {
                id: playerGrid;
                anchors {
                    top: avatar.bottom;
                    topMargin: 2;
                    horizontalCenter: avatar.horizontalCenter;
                }
                columns: 2
                spacing: 2

                Label {text: qsTr("Nickname: ")}
                Text {text: qsTr("nickname")}
                Label {text: qsTr("Name: ")}
                Text {text: qsTr("name")}
                Label {text: qsTr("Surname: ")}
                Text {text: qsTr("surname")}
                Label {text: qsTr("Rank: ")}
                Text{text: qsTr("0000")}
            }
            Button {
                id:button;
                anchors {
                    horizontalCenter: playerGrid.horizontalCenter;
                    top: playerGrid.bottom;
                    topMargin: 2;
                }
                text:qsTr("Edit")

                MouseArea {
                    anchors.fill: parent
                    onClicked: console.log("Edit button clicked");
                }
            }
        }
    }

    GroupBox {
        title: "Info";
        id: infoGB;
        width: 320;
        anchors {
            left: playerInfo.right;
        }

        Row {
            id: lastgame;
            anchors.left: parent.left;
            Label {            text: qsTr("Last Game: ")
            }
            Rectangle {
                width: 100;
                height: 15;
                color: "white"
                border.color: "black"
                border.width: control.activeFocus ? 2 : 1
                radius: 3

                Text {
                    anchors.centerIn: parent;
                    text: qsTr(new Date().toLocaleDateString(Locale.ShortFormat));
                    color: "black";
                }
            }

        }

        Grid {
            id: centralgrid;
            columns: 3;
            spacing: 2;
            anchors.top: lastgame.bottom;
            anchors.topMargin: 2;

            Label {
                text: qsTr("Participated in: ")
            }

            Rectangle {
                id: pitext
                width: 100;
                height: 15;
                color: "white"
                border.color: "black"
                border.width: control.activeFocus ? 2 : 1
                radius: 3

                Text {
                    anchors.centerIn: parent;
                    text: qsTr("num of games");
                    color: "black";
                }
            }

            Button {
                id:gameStatisticBtn;
                width: 30;
                height: 15;
                text:qsTr("...");
                MouseArea {
                    anchors.fill: parent
                    onClicked: console.log("Game statistic button is clicked");
                }
            }

            Label {
                text: qsTr("Mahjongs: ")
            }

            Rectangle {
                width: 100;
                height: 15;
                color: "white"
                border.color: "black"
                border.width: control.activeFocus ? 2 : 1
                radius: 3

                Text {
                    anchors.centerIn: parent;
                    text: qsTr("# of mahjongs");
                    color: "black";
                }
            }

            Button {
                id:mahjongDetailsBtn;
                width: 30;
                height: 15;
                text: qsTr(">")
                style: ButtonStyle {
                    background: Rectangle {
                        color: "light grey";
                        border.color: "grey";
                        radius: 1;
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {mahjonglist.visible = !mahjonglist.visible}
                }
            }

            Item {
                id: mahjonglist
                anchors {
                    top: mahjongDetailsBtn.bottom;
                    topMargin:2;
                }
                visible: false;

                Rectangle {
                    id: mlbg;
                    width: 210;
                    height: 50;
                    color: "white"
                    border.color: "grey"
                    border.width: 1
                    radius: 2
                    Grid {
                        anchors.centerIn: mlbg;
                        columns:3
                        spacing:2

                        Label {text: qsTr("Best: ")}
                        Rectangle {
                            width: 50;
                            height: 15;
                            color: "white"
                            border.color: "black"
                            border.width: control.activeFocus ? 2 : 1
                            radius: 3

                            Text {
                                anchors.centerIn: parent;
                                text: qsTr("Score");
                                color: "black";
                            }
                        }
                        Rectangle {
                            width: 100;
                            height: 15;
                            color: "white"
                            border.color: "black"
                            border.width: control.activeFocus ? 2 : 1
                            radius: 3

                            Text {
                                anchors.centerIn: parent;
                                text: qsTr(new Date().toLocaleDateString(Locale.ShortFormat));
                                color: "black";
                            }
                        }
                        Label {
                            text: qsTr("Worst: ")
                        }
                        Rectangle {
                            width: 50;
                            height: 15;
                            color: "white"
                            border.color: "black"
                            border.width: control.activeFocus ? 2 : 1
                            radius: 3

                            Text {
                                anchors.centerIn: parent;
                                text: qsTr("Score");
                                color: "black";
                            }
                        }
                        Rectangle {
                            width: 100;
                            height: 15;
                            color: "white"
                            border.color: "black"
                            border.width: control.activeFocus ? 2 : 1
                            radius: 3

                            Text {
                                anchors.centerIn: parent;
                                text: qsTr(new Date().toLocaleDateString(Locale.ShortFormat));
                                color: "black";
                            }
                        }
                    }
                }
            }

        }

    }
}
