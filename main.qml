import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    property int a: 800
    id: root
    width: a
    height: 640
    color: "#000000"
    visible: true

    Image {
        id: base
        x: posn
        y: 328
        source: "content/M2.png"

        Image {
            id: rod
            x: 44
            y: -154
            width: 13
            height: 184
            scale: 1
            transformOrigin: Item.Bottom
            z: 0
            rotation: theta
            source: "content/arm.png"

            Image {
                id: m
                x: -18
                y: -31
                width: 50
                height: 50
                source: "content/m.png"
            }

        }
    }

    Rectangle {
        id: rectangle1
        x: 0
        y: 399
        width: 800
        height: 241
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#ffffff"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
        }
    }

    MouseArea {
        id: mouseArea1
        x: 592
        y: 87
        width: 100
        height: 100
    }

}

