// Copyright 2023 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

import QtQuick 2.15
import QtQuick.Controls 2.15
import Esri.map_display

ApplicationWindow {
    visible: true
    width: 1000
    height: 800
    minimumWidth: 400
    minimumHeight: 300


    Rectangle {
        width: parent.width
        height: 50
        color: "black"
        anchors.top: parent.top

        CustomMenuItem {
            text: ""
            onClicked: {
                // Handle the button click event for "logo"
            }
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
                leftMargin: 10
            }

            Image {
                source: "images/idea9.png"
                width: 40 // Set the width of the image
                height: 40 // Set the height of the image
            }
        }

        CustomMenuItem {
            text: "Eventures"
            onClicked: {
                // Handle the button click event
            }
            anchors {
                right: parent.right
                verticalCenter: parent.verticalCenter
                rightMargin: 10
            }
        }
    }

    Rectangle {
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.left: parent.left
        width: 40
        height: parent.height // Span the full vertical length of the parent
        color: "black"

        Column {
            anchors.centerIn: parent
            spacing: 10 // Set spacing between buttons

            Button {
                width: 40
                height: 40

                MouseArea {
                    id: homeButtonArea
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor

                    onClicked: {model.setupViewpoint()}

                    Rectangle {
                        color: homeButtonArea.pressed ? "#fe817b" : "black"
                        width: parent.width
                        height: parent.height
                    }

                    Image {
                        anchors.centerIn: parent
                        source: "images/home.png"
                        width: 30
                        height: 30
                    }
                }
            }

            Button {
                width: 40
                height: 40

                MouseArea {
                    id: heartButtonArea
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor

                    onClicked: {}

                    Rectangle {
                        color: heartButtonArea.pressed ? "#fe817b" : "black"
                        width: parent.width
                        height: parent.height
                    }

                    Image {
                        anchors.centerIn: parent
                        source: "images/heart.png"
                        width: 30
                        height: 30
                    }
                }
            }

            Button {
                width: 40
                height: 40

                MouseArea {
                    id: calendarButtonArea
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor

                    onClicked: {}

                    Rectangle {
                        color: calendarButtonArea.pressed ? "#fe817b" : "black"
                        width: parent.width
                        height: parent.height
                    }

                    Image {
                        anchors.centerIn: parent
                        source: "images/calendar.png"
                        width: 30
                        height: 30
                    }
                }
            }
        }
    }

    Item {
        anchors.fill: parent
        anchors.topMargin: 50
        anchors.leftMargin: 40

        // Create MapQuickView here, and create its Map etc. in C++ code
        MapView {
            id: view
            objectName: "mapView"
            anchors.fill: parent
            // set focus to enable keyboard navigation
            focus: true
        }

        // Declare the C++ instance which creates the map etc. and supply the view
        Map_display {
            id: model
            mapView: view
        }
    }

    Rectangle {
        id: searchRectangle
        width: parent.width - 70 // Span the full width of the parent
        height: 50 // Set the height of the search bar area
        color: "black" // Set the background color of the search bar area
        anchors.top: parent.top // Position it below the top bar
        anchors.topMargin: 60
        x: parent.width / 2 - width / 2 + 20 /// Centered with a 40px left margin
        radius: 40

        Rectangle {
                id: inputFieldBackground
                width: parent.width
                height: parent.height - 10
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left;
                anchors.leftMargin: 20
                anchors.right: parent.right;
                color: "black"
                radius: 20

                TextInput {
                            id: searchBar
                            anchors.fill: parent
                            text: "Auckland.."
                            color: "white"
                            font.pixelSize: 20
                            font.bold: true
                            verticalAlignment: TextInput.AlignVCenter

                            onActiveFocusChanged: {
                                if (activeFocus) {
                                    text = ""; // Clear the placeholder text when clicked
                                }
                            }
                            Keys.onReturnPressed: {
                                searchSubmit();
                            }
                            MouseArea {
                                    anchors.fill: parent
                                    cursorShape: Qt.IBeamCursor
                                }
                        }
                    }



        Item {
                anchors.top: searchRectangle.top
                anchors.topMargin: 5

                anchors.right: inputFieldBackground.right
                anchors.rightMargin: 45

                Rectangle {
                    width: 40
                    height: 40
                    color: "#fe817b"
                    radius: 30

                    Image {
                        anchors.centerIn: parent
                        source: "images/search.png"
                        width: 15
                        height: 15
                    }

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            searchSubmit();
                        }
                    }
                }
        }
    }

    TicketRectangle {

       }

    ZoomButtons {
        id: buttonsCol
        anchors.fill: parent
    }

    // Function to parse search values and update graphics
    function searchSubmit() {
        model.searchHandler(searchBar.text, 0);
        buttonsCol.reload();
    }

    // Function to change zoom
    function zoom(inc) {
        model.setZoom(inc);
    }

    // Function to focus on active point
    function findPoint() {
        model.findPoint();
    }
}







