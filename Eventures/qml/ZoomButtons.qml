import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    anchors.fill: parent

    Column {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        spacing: 10

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
                    source: "images/plus.png" // Replace with your icon image
                    width: 20 // Adjust the image width as needed
                    height: 20 // Adjust the image height as needed
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
                    source: "images/minus.png" // Replace with your icon image
                    width: 20 // Adjust the image width as needed
                    height: 20 // Adjust the image height as needed
                }
            }
        }
    }
}
