import QtQuick 2.0

Rectangle {
    id: root
    width: 200
    height: 200
    color: "red"

    signal move()

    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.move()
        }
    }
}
