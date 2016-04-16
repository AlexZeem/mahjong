import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    id: item1
    height: main.height
    width: main.width

    GroupBox {
        id: playerGB;
        title: "Player info"
        anchors.left: parent.left;

        Column{
            spacing: 5
            width: 213
            anchors.horizontalCenter: parent.horizontalCenter

            Image {
                id: avatar
                source: "UserIcon.png"
                width: 150;
                height: 150;
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Row {
                id: nickname
                width: avatar.width
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    text: qsTr("Nickname: ")
                    color: "black"
                }
            }

            Row{
                id:name
                width: avatar.width
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    text: qsTr("Name: ")
                    color: "black"
                }
            }

            Row{
                id: surname
                width: avatar.width
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    text: qsTr("Surname: ")
                    color: "black"
                }
            }

            Row {
                id: rank
                width: avatar.width
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    text: qsTr("Rank: ")
                    color: "black"
                }

                Rectangle {
                    width: 100;
                    height: 15;
                    color: "white"
                    border.color: "black"
                    border.width: control.activeFocus ? 2 : 1
                    radius: 3

                    Text{
                        text: qsTr("0000");
                        color: "black"
                        anchors.centerIn: parent
                    }
                }
            }

            Button {
                id:button;
                anchors.horizontalCenter: parent.horizontalCenter

                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 20
                        color: "light grey"
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "grey"
                        radius: 3
                    }
                    label: Text{
                        text:qsTr("Edit")
                        horizontalAlignment: Text.AlignHCenter
                        style: Text.Sunken;
                        color: "black"
                        styleColor: "grey"
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: clicked();
                }
            }
        }
    }

    GroupBox {
        id: infoGB;
        title: "Info";
        width: 320;
        anchors.left: playerGB.right;

        Row {
            id: lastgame;
            anchors.left: parent.left;
            Label {
                text: qsTr("Last Game: ")
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
                id: pilabel;
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
                style: ButtonStyle {
                    background: Rectangle {
                        color: "light grey";
                        border.width: control.activeFocus ? 2 : 1;
                        border.color: "grey";
                        radius: 1;
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: clicked();
                }
            }

            Label {
                id: mahjongLabel;
                text: qsTr("Mahjongs: ")
            }

            Rectangle {
                id: mahjongText
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
                anchors.top: mahjongDetailsBtn.bottom;
                anchors.topMargin:2;
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
