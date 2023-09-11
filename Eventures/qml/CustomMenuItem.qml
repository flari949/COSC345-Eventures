import QtQuick 2.15

Rectangle {
    id: customButton
    width: 100
    height: 40
    color: customButton.hovered ? "black" : "black"
    border.color: "black"

    Text {
        anchors.centerIn: parent
        text: customButton.text
        color: customButton.containsMouse ? "#fe817b" : "white"
        font.pixelSize: 16
        font.bold: true
    }

    MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: customButton.clicked()
            onEntered: customButton.containsMouse = true
            onExited: customButton.containsMouse = false
        }

        property string text: "Custom Button"
        property bool containsMouse: false

    signal clicked()
}
