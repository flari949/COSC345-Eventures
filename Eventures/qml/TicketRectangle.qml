import QtQuick 2.15
import QtQuick.Controls 2.4


Item {

    function updateIndex(change) {
        desc.index += change;
        model.showInfo(desc.index);
//        refresh();
    }

    function refresh() {
        desc.title = model.getTitle(desc.index);
        desc.url = model.getUrl(desc.index);
        desc.date = model.getDate(desc.index);
        desc.location = model.getLocation(desc.index);
    }

    id: desc
    property bool ticketVisible: model.ticketVisible
    property int index: 0
    property string title: ""
    property string url: ""
    property string date: ""
    property string location: ""


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
                    model.ticketVisible = false; // Set to false to hide the ticketRectangle
                }

        Image {
            anchors.centerIn: parent
            source: "images/cross.png"
            width: 15
            height: 15
        }
    }

    RoundButton {
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.bottom: parent.bottom
         anchors.bottomMargin: 20
        visible: ticketVisible
        onClicked: updateIndex(-1)

        Image {
            anchors.centerIn: parent
            source: "images/angle-left.png"
            width: 15
            height: 15
        }
    }

    RoundButton {
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        visible: ticketVisible
        onClicked: updateIndex(1)

        Image {
            anchors.centerIn: parent
            source: "images/angle-right.png"
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
                color: "transparent"

                Text {
                    id: title
                    text: desc.title
                    font.family: customFont.name
                    font.bold: true
                    font.pixelSize: 20
                    color: "black"
                    width: parent.width
                    wrapMode: Text.WordWrap
                }

                Rectangle {
                    id: colorRectangle
                    width: parent.width
                    anchors.top: title.bottom
                    anchors.topMargin: 10
                    color: "#fe817b" // Background color for location and date/time
                    radius: 10 // Adjust the radius for the rounded corners

                    property int totalHeight: date.implicitHeight + 20 + location.implicitHeight

                    height: totalHeight // Set the height of the Rectangle

                    Text {
                        id: date
                        anchors.top: parent.top
                        anchors.topMargin: 5
                        text: "Date and Start time: " + desc.date
                        font.pixelSize: 12
                        color: "black"
                        anchors.left: parent.left
                        anchors.leftMargin: 5
                        width: parent.width
                        wrapMode: Text.WordWrap
                    }

                    Text {
                        id: location
                        anchors.top: date.bottom
                        anchors.topMargin: 10
                        text: "Location: " + desc.location
                        font.pixelSize: 12
                        color: "black"
                        width: parent.width
                        anchors.left: parent.left
                        anchors.leftMargin: 5
                        wrapMode: Text.WordWrap
                    }
                }

                Text {
                    id: link
                    anchors.top: colorRectangle.bottom
                    anchors.topMargin: 20
                    textFormat: Text.RichText  // Set the textFormat to RichText
                    text: "Link to event: <a href='" + desc.url + "'>" + desc.url + "</a>"
                    font.pixelSize: 12
                    color: "black"  // You can set the color to a different color for hyperlinks
                    width: parent.width
                    wrapMode: Text.WordWrap
                    onLinkActivated: Qt.openUrlExternally(link)
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
                    onTextChanged: refresh()
                }
            }
        }

    }
}
