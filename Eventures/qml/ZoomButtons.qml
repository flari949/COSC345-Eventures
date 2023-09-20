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

    Column {
        id: col
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        spacing: 10


        Button {
            width: 40
            height: 40


            MouseArea {
                id: nextItem
                anchors.fill: parent

                onClicked: {
                    switchPoint(true);
                }

                Rectangle {
                    color: nextItem.pressed ? "#fe817b" : "white"
                    width: parent.width
                    height: parent.height
                }

                Text {
                    anchors.centerIn: parent
                    text: ">"
                    width: 20
                    height: 20
                }
            }
        }

        Button {
            width: 40
            height: 40

            MouseArea {
                id: prevItem
                anchors.fill: parent

                onClicked: {
                    switchPoint(false);
                }

                Rectangle {
                    color: prevItem.pressed ? "#fe817b" : "white"
                    width: parent.width
                    height: parent.height
                }

                Text {
                    anchors.centerIn: parent
                    text: "<"
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
            id: inc
            width: 40
            height: 40
            property int valid: model.checkPage(true)


            MouseArea {
                id: incPage
                anchors.fill: parent

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

                Text {
                    anchors.centerIn: parent
                    text: ">>"
                    width: 20
                    height: 20
                }
            }
        }

        Button {
            id: dec
            width: 40
            height: 40
            property int valid: model.checkPage(false)


            MouseArea {
                id: decPage
                anchors.fill: parent

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

                Text {
                    anchors.centerIn: parent
                    text: "<<"
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
            width: 40
            height: 40


            MouseArea {
                id: plusButtonArea
                anchors.fill: parent

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
            width: 40
            height: 40

            MouseArea {
                id: minusButtonArea
                anchors.fill: parent

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
