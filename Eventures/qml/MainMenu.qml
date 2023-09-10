import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: menuItemStyle

    Rectangle {
        width: parent.width
        height: 30 // Customize the height as needed
        color: "black"

        Text {
            anchors.centerIn: parent
            text: modelData
            color: "white"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // Handle the click event here if needed
            }
        }
    }
}
