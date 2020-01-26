import QtQuick 2.9
import QtQuick.Controls 2.2

Rectangle {
    id: main
    width: 100
    height: 100

    Button {
        id: cb
        text: "Save"
        anchors.centerIn: parent
        PropertyAnimation {
            id: cbAnimation
            target: cb
            property: "rotation"
            from: 0
            to: 360
            duration: 5000
            loops: Animation.Infinite


            }
        }

    Component.onCompleted:  cbAnimation.start()
    }

