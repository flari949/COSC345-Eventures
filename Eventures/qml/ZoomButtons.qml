import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: buttons
    anchors.fill: parent

    // Function to iterate over markers
    function switchPoint(next) {
        model.switchViews(next);
    }

    // Function to check subsequent pages exist
    function reload() {
        inc.valid=model.checkPage(true)
        dec.valid=model.checkPage(false)
    }

    // Function to find central coordinates
    function getCoords() {
        model.mapCentre()
    }

    Column {
        id: col
        anchors.top: parent.top
        anchors.topMargin: 120
        anchors.rightMargin: 10
        anchors.right: parent.right

        //spacing: 10


        Button {
            width: 30
            height: 30

            MouseArea {
                id: getCentre
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor

                onClicked: {
                    getCoords();
                }

                Rectangle {
                    color: getCentre.pressed ? "#fe817b" : "white"
                    width: parent.width
                    height: parent.height
                }

                Text {
                    anchors.centerIn: parent
                    text: "|*|"
                    width: 20
                    height: 20
                }
            }
        }


        // Spacer item
        Item {
            width: 1
            height: 40
        }


        Button {
            width: 30
            height: 30


            MouseArea {
                id: nextItem
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    switchPoint(true);
                }

                Rectangle {
                    color: nextItem.pressed ? "#fe817b" : "white"
                    width: parent.width
                    height: parent.height
                }

                Image {
                    anchors.centerIn: parent
                    source: "images/angle-left.png"
                    width: 15
                    height: 15
                }
            }
        }

        Button {
            width: 30
            height: 30

            MouseArea {
                id: prevItem
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor

                onClicked: {
                    switchPoint(false);
                }

                Rectangle {
                    color: prevItem.pressed ? "#fe817b" : "white"
                    width: parent.width
                    height: parent.height
                }

                Image {
                    anchors.centerIn: parent
                    source: "images/angle-right.png"
                    width: 15
                    height: 15
                }
            }
        }


        Button {
            id: inc
            width: 30
            height: 30
            property int valid: model.checkPage(true)


            MouseArea {
                id: incPage
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor

                onClicked: {
                    model.searchHandler("", inc.valid)
                    reload()
                }

                enabled: (inc.valid !== -1) ? true : false

                Rectangle {
                    color: (inc.valid !== -1) ? "white" : "grey"
                    width: parent.width
                    height: parent.height
                }

                Image {
                    anchors.centerIn: parent
                    source: "images/angle-double-left.png"
                    width: 15
                    height: 15
                }
            }
        }

        Button {
            id: dec
            width: 30
            height: 30
            property int valid: model.checkPage(false)


            MouseArea {
                id: decPage
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor

                onClicked: {
                    model.searchHandler("", dec.valid)
                    reload()
                }

                enabled: (dec.valid !== -1) ? true : false

                Rectangle {
                    color: (dec.valid !== -1) ? "white" : "grey"
                    width: parent.width
                    height: parent.height
                }

                Image {
                    anchors.centerIn: parent
                    source: "images/angle-double-right.png"
                    width: 15
                    height: 15
                }
            }
        }
    }

    Column {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: 30
        anchors.rightMargin: 10


        Button {
            width: 30
            height: 30


            MouseArea {
                id: plusButtonArea
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor

                onClicked: {
                    zoom(true);
                }

                Rectangle {
                    color: plusButtonArea.pressed ? "#fe817b" : "white"
                    width: parent.width
                    height: parent.height
                }

                Image {
                    anchors.centerIn: parent
                    source: "images/plus.png"
                    width: 20
                    height: 20
                }
            }
        }

        Button {
            width: 30
            height: 30


            MouseArea {
                id: minusButtonArea
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor

                onClicked: {
                    zoom(false);
                }

                Rectangle {
                    color: minusButtonArea.pressed ? "#fe817b" : "white"
                    width: parent.width
                    height: parent.height
                }

                Image {
                    anchors.centerIn: parent
                    source: "images/minus.png"
                    width: 20
                    height: 20
                }
            }
        }
    }
}
