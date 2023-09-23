import QtQuick 2.15
import QtQuick.Controls 2.4


Item {
    property bool ticketVisible: model.ticketVisible // Bind to the property in your C++ class

    width: 300
    height: 500
    anchors.top: searchRectangle.bottom;
    anchors.topMargin: 10
    anchors.right: parent.right
    anchors.rightMargin: 50

    Image {
        id: ticketRectangle
        source: "images/ticketoutlined.svg"
        width: parent.width
        height: parent.height
        fillMode: Image.PreserveAspectFit
        visible: ticketVisible // Control visibility based on the property

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
    visible: ticketVisible // Control visibility based on the property


    onClicked: {
                ticketVisible = false; // Set to false to hide the ticketRectangle
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
        height: 350
        id: contentRectangle
        anchors.top: ticketRectangle.top
        anchors.topMargin: 80
        anchors.left: ticketRectangle.left
        anchors.leftMargin: 30
        anchors.right: ticketRectangle.right
        anchors.rightMargin: 10
        visible: ticketVisible // Control visibility based on the property



        Flickable {
            anchors.fill: parent
            clip: true
            contentWidth: parent.width
            contentHeight: parent.height * 1.5
            ScrollBar.vertical: ScrollBar { id: vbar }


            Rectangle {
                id: contentRect
                width: parent.width - 30
                height: title.height + date.height + location.height + link.height + information.height
                color: "transparent"

                Text {
                    id: title
                    text: "Saturday Laughs with David Correos and Neil Thornton"
                    font.family: customFont.name
                    font.bold: true
                    font.pixelSize: 20
                    color: "black"
                    width: parent.width
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: date
                    anchors.top: title.bottom
                    anchors.topMargin: 20
                    text: "Sat 23 Sep 2023, 8:00pm–9:45pm"
                    font.pixelSize: 12
                    color: "black"
                    width: parent.width
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: location
                    anchors.top: date.bottom
                    anchors.topMargin: 10
                    text: "Abandoned Taproom, 20 Parumoana Street, Porirua - Mana"
                    font.pixelSize: 12
                    color: "black"
                    width: parent.width
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: link
                    anchors.top: location.bottom
                    anchors.topMargin: 10
                    text: "EventFinda link: "
                    font.pixelSize: 12
                    color: "black"
                    width: parent.width
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: information
                    anchors.top: link.bottom
                    anchors.topMargin: 20
                    text: model.eventInformation
                    font.pixelSize: 12
                    color: "black"
                    width: parent.width
                    wrapMode: Text.WordWrap
                }

           }
        }

    }

}
