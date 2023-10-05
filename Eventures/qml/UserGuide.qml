import QtQuick 2.15
import QtQuick.Controls 2.4


Popup {

    id: desc
    property bool guideVisible: true
    width: 300
    height: 500
    x: 35   //parent.width / 2 - width /3
    y: -270
    background: Rectangle{
        color: "transparent"
    }

    Image {
        id: ticketRectangle
        source: "images/ticketoutlined.svg"
        width: parent.width
        height: parent.height
        fillMode: Image.PreserveAspectFit
        visible: guideVisible // Control visibility based on the property
    }

    FontLoader {
        id: customFont
        source: "fonts/Mirage.otf"
    }

    Component.onCompleted: {
        if (customFont.status === FontLoader.Ready) {
        }
    }

    RoundButton{
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 20
        visible: guideVisible // Control visibility based on the property


        onClicked: {
            desc.close();
        }

        Image {
            anchors.centerIn: parent
            source: "images/cross.png"
            width: 15
            height: 15
        }
    }

    Rectangle {
        width: 300
        height: 340
        id: contentRectangle
        anchors.top: ticketRectangle.top
        anchors.topMargin: 80
        anchors.left: ticketRectangle.left
        anchors.leftMargin: 30
        anchors.right: ticketRectangle.right
        anchors.rightMargin: 10
        visible: guideVisible // Control visibility based on the property


        Flickable {
            anchors.fill: parent
            clip: true
            contentWidth: parent.width
            contentHeight: parent.height * 1.8
            ScrollBar.vertical: ScrollBar { id: vbar }


            Rectangle {
                id: contentRect
                width: parent.width - 30
                height: title.height + information.height
                color: "transparent"

                Text {
                    id: title
                    text: "User Guide"
                    font.family: customFont.name
                    font.bold: true
                    font.pixelSize: 20
                    color: "black"
                    width: parent.width
                    wrapMode: Text.WordWrap
                }
                Text {
                    id: information
                    anchors.top: title.bottom
                    font.bold: true
                    text: "Eventures App Controls"
                    font.pixelSize: 12
                    color: "black"
                    width: parent.width
                    wrapMode: Text.WordWrap
                }

                //Search bar icon and info
                Rectangle {
                    id: searchBar
                    color: "black"
                    width: 110
                    height: 25
                    radius: 50
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: 50
                    Text {
                        text: "Auckland...      "
                        anchors.centerIn: parent
                        color: "white"
                        font.bold: true
                        font.pixelSize: 12
                    }
                }
                Text{
                    id: searchBarText
                    width: 120
                    font.italic: true
                    text: "Enter a location"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 120
                    anchors.topMargin: 55
                }

                //Search button and info
                Rectangle {
                    id: searchButton
                    color: "black"
                    width: 25
                    height: 25
                    radius: Math.min(width,height)
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: 100
                    Image {
                        source: "images/white-search.png"
                        width: 20
                        height: 20
                        anchors.centerIn: parent
                    }
                }

                Text{
                    id: searchButtonText
                    width: 180
                    font.italic: true
                    text: "Filter events by search location"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 40
                    anchors.topMargin: 102
                }
                //Marker icon and info
                Rectangle {
                    id: markerIcon
                    color: "black"
                    width: 25
                    height: 25
                    radius: Math.min(width,height)
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: 150
                    Image {
                        source: "images/white-marker.png"
                        width: 20
                        height: 20
                        anchors.centerIn: parent
                    }
                }
                Text{
                    id: markerIconText
                    width: 180
                    font.italic: true
                    text: "Represents an event at a location. Click to show event details"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 40
                    anchors.topMargin: 145
                }

                //Home button icon and info
                Rectangle {
                    id: homeButton
                    color: "black"
                    width: 25
                    height: 25
                    radius: Math.min(width,height)
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: 200
                    Image {
                        source: "images/home.png"
                        width: 20
                        height: 20
                        anchors.centerIn: parent
                    }
                }
                Text{
                    id: homeButtonText
                    width: 170
                    font.italic: true
                    text: "Reset map to default view of New Zealand"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 40
                    anchors.topMargin: 195
                }

                //Refresh button icon and info
                Rectangle {
                    id: refreshButton
                    color: "black"
                    width: 25
                    height: 25
                    radius: Math.min(width,height)
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: 250
                    Image {
                        source: "images/load2.png"
                        width: 20
                        height: 20
                        anchors.centerIn: parent
                    }
                }
                Text{
                    id: refreshButtonText
                    font.italic: true
                    text: "Load events in current map position"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 40
                    anchors.topMargin: 252
                }

                //Single Left Arrow button icon and info
                Rectangle {
                    id: singleLeftArrowButton
                    color: "black"
                    width: 25
                    height: 25
                    radius: Math.min(width,height)
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin:300
                    Image {
                        source: "images/white-angle-left.png"
                        width: 20
                        height: 20
                        anchors.centerIn: parent
                    }
                }
                Text{
                    id: singleLeftArrowButtonText
                    width: 180
                    font.italic: true
                    text: "Pan to previous event"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 40
                    anchors.topMargin: 302
                }

                //Single Right Arrow button icon and info
                Rectangle {
                    id: singleRightArrowButton
                    color: "black"
                    width: 25
                    height: 25
                    radius: Math.min(width,height)
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: 350
                    Image {
                        source: "images/white-angle-right.png"
                        width: 20
                        height: 20
                        anchors.centerIn: parent
                    }
                }
                Text{
                    id: singleRightArrowButtonText
                    width: 180
                    font.italic: true
                    text: "Pan to next event"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 40
                    anchors.topMargin: 352
                }

                //Double Left Arrow button icon and info
                Rectangle {
                    id: doubleLeftArrowButton
                    color: "black"
                    width: 25
                    height: 25
                    radius: Math.min(width,height)
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: 400
                    Image {
                        source: "images/white-angle-double-left.png"
                        width: 20
                        height: 20
                        anchors.centerIn: parent
                    }
                }
                Text{
                    id: doubleLeftArrowButtonText
                    width: 180
                    font.italic: true
                    text: "View the previous page of results"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 40
                    anchors.topMargin: 402
                }

                //Double Right Arrow button icon and info
                Rectangle {
                    id: doubleRightArrowButton
                    color: "black"
                    width: 25
                    height: 25
                    radius: Math.min(width,height)
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: 450
                    Image {
                        source: "images/white-angle-double-right.png"
                        width: 20
                        height: 20
                        anchors.centerIn: parent
                    }
                }
                Text{
                    id: doubleRightArrowButtonText
                    width: 180
                    font.italic: true
                    text: "View the next page of results"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 40
                    anchors.topMargin: 452
                }

                //+ button icon and info
                Rectangle {
                    id: plusButton
                    color: "black"
                    width: 25
                    height: 25
                    radius: Math.min(width,height)
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: 500
                    Image {
                        source: "images/white-plus.png"
                        width: 20
                        height: 20
                        anchors.centerIn: parent
                    }
                }
                Text{
                    id: plusButtonText
                    width: 180
                    font.italic: true
                    text: "Zoom in map"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 40
                    anchors.topMargin: 502
                }

                //- button icon and info
                Rectangle {
                    id: minusButton
                    color: "black"
                    width: 25
                    height: 25
                    radius: Math.min(width,height)
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: 550
                    Image {
                        source: "images/white-minus.png"
                        width: 20
                        height: 20
                        anchors.centerIn: parent
                    }
                }
                Text{
                    id: minusButtonText
                    width: 180
                    font.italic: true
                    text: "Zoom out map"
                    font.pixelSize: 12
                    color: "black"
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 40
                    anchors.topMargin: 552
                }




           }
        }
    }
}
