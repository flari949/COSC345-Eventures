import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    width: 40
    height: parent.height // Span the full vertical length of the parent
    color: "black"

    Column {
        anchors.centerIn: parent

        Button {
            text: "x"
            onClicked: {
                // Handle the button click event for "x"
            }

            background: Rectangle {
                color: parent.hovered ? "black" : "black"
            }

            contentItem: Text {
                text: parent.text
                color: parent.hovered ? "green" : "white"
                font.pixelSize: 16
                font.weight: Font.Bold
            }
        }

        Button {
            text: "y"
            onClicked: {
                // Handle the button click event for "y"
            }

            background: Rectangle {
                color: parent.hovered ? "black" : "black"
            }

            contentItem: Text {
                text: parent.text
                color: parent.hovered ? "green" : "white"
                font.pixelSize: 16
                font.weight: Font.Bold
            }
        }

        Button {
            text: "z"
            onClicked: {
                // Handle the button click event for "z"
            }

            background: Rectangle {
                color: parent.hovered ? "black" : "black"
            }

            contentItem: Text {
                text: parent.text
                color: parent.hovered ? "green" : "white"
                font.pixelSize: 16
                font.weight: Font.Bold
            }
        }
    }
}
