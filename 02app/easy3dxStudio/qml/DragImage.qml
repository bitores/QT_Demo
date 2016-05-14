import QtQuick 1.1

Item {
    id:father
    x:img.x
    y:img.y
    width: img.width
    height: img.height



    property int z_index:0
    property string src: ""
    Text {
        id: out
        text: qsTr("0:0")
        x:img.x
        y:img.y
        width: img.width
        height: img.height
    }

        Image {
            id: img
            source: src
            MouseArea {

                    anchors.fill: img
                    property int startX: 0
                    property int  startY: 0

                    onPressed: {
                        father.z =++father.parent.z_index
                        console.log(parent.z)
                        startX = mouse.x
                        startY = mouse.y
                    }
                    onPositionChanged: {
                        father.x += mouse.x -startX
                        father.y += mouse.y - startY
                        out.text = father.objectName+":"+ father.x +":"+father.y
                    }

//                    onReleased: {
//                        out.text = father.x +":"+father.y
//                    }
                }

        }

}
