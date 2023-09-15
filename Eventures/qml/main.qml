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
                source: "images/idea9.png" // Set the path to your image
                width: 40 // Set the width of the image
                height: 40 // Set the height of the image
            }
        }

        CustomMenuItem {
            text: "Eventures"
            onClicked: {
                // Handle the button click event for "Eventures"
            }
            anchors {
                right: parent.right
                verticalCenter: parent.verticalCenter
                rightMargin: 10
            }
        }

        Row {
            spacing: 10
            anchors.centerIn: parent

            TextField {
                id: searchBar
                placeholderText: "Search"
                Keys.onReturnPressed: {
                    searchSubmit();
                }
            }

            Button {
                text: "Go!"
                onClicked: {
                    searchSubmit();
                }
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

                    onClicked: {
                        // Handle button click here
                    }

                    Rectangle {
                        color: homeButtonArea.pressed ? "#fe817b" : "black"
                        width: parent.width
                        height: parent.height
                    }

                    Image {
                        anchors.centerIn: parent
                        source: "images/home.png" // Replace with your icon image
                        width: 30 // Adjust the image width as needed
                        height: 30 // Adjust the image height as needed
                    }
                }
            }

            Button {
                width: 40
                height: 40

                MouseArea {
                    id: heartButtonArea
                    anchors.fill: parent

                    onClicked: {
                        // Handle button click here
                    }

                    Rectangle {
                        color: heartButtonArea.pressed ? "#fe817b" : "black"
                        width: parent.width
                        height: parent.height
                    }

                    Image {
                        anchors.centerIn: parent
                        source: "images/heart.png" // Replace with your icon image
                        width: 30 // Adjust the image width as needed
                        height: 30 // Adjust the image height as needed
                    }
                }
            }

            Button {
                width: 40
                height: 40

                MouseArea {
                    id: calendarButtonArea
                    anchors.fill: parent

                    onClicked: {
                        // Handle button click here
                    }

                    Rectangle {
                        color: calendarButtonArea.pressed ? "#fe817b" : "black"
                        width: parent.width
                        height: parent.height
                    }

                    Image {
                        anchors.centerIn: parent
                        source: "images/calendar.png" // Replace with your icon image
                        width: 30 // Adjust the image width as needed
                        height: 30 // Adjust the image height as needed
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

    ZoomButtons {
        anchors.fill: parent
        anchors.bottomMargin: 30
        anchors.rightMargin: 10
    }

    // Function to parse search values and update graphics
    function searchSubmit() {
        model.searchHandler(searchBar.text);
    }
}







