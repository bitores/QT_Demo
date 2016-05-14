import QtQuick 1.0
import "logic.js" as Logic

Item {
    id:father
    objectName: ""
    x:img.x
    y:img.y
    width: frameWidth
    height: frameHeight
    clip: true
    scale: 1.0

    property int anchorX: 0
    property int anchorY: 0
    property alias shadowVisible: shadow.visible
    property int cols: 1
    property int rows: 1

    property int z_index:2
    property alias source: img.source
    property string parentName:" "
    property bool isSequenceFrame: false

    property int frameCount: cols * rows
    property int frameDuration: 0

    property int frameX: 0
    property int frameY: 0
    property int frameWidth: img.width
    property int frameHeight: img.height
    property int duration: 0

    onIsSequenceFrameChanged: {
        if(isSequenceFrame)
        {
            engine.running = true
            canstop.running = true
            console.log("frame start ...")
        }else{
            engine.running = false
            canstop.running = false
        }
    }

    onRowsChanged: changRect()
    onColsChanged: changRect()

    onParentNameChanged: {
//        console.log(objectName+":"+parentName)
    }

    onAnchorXChanged: {
//        console.log("xanchor:"+anchorX)
    }

    Rectangle{
        id:shadow
        anchors.fill: parent
        opacity: 0.05
    }

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
        MouseArea {
                anchors.fill: img
                property int startX: 0
                property int  startY: 0

                onPressed: {
                    father.z =++father.parent.z_index
                    startX = mouse.x
                    startY = mouse.y

                    Logic.noticeName(father.objectName)
                    Logic.noticeX(father.x)
                    Logic.noticeY(father.y)
                    Logic.noticeW(father.width)
                    Logic.noticeH(father.height)
                    Logic.noticeVisible(shadow.visible)
                    Logic.noticeAnchorX(father.anchorX)
                    Logic.noticeAnchorY(father.anchorY)
                    Logic.noticeScale(father.scale)
                    Logic.noticeRow(father.rows)
                    Logic.noticeCol(father.cols)
                    Logic.noticeParentwhich(father.parentName)
                }
                onPositionChanged: {
                    father.x += mouse.x -startX
                    father.y += mouse.y - startY
                    out.text = father.objectName+":"+ father.x +":"+father.y

                    Logic.noticeX(father.x)
                    Logic.noticeY(father.y)
                }
                onReleased: {
                    out.text = father.x +":"+father.y

                    Logic.noticeX(father.x)
                    Logic.noticeY(father.y)
                }
            }
    }

    Timer {
        id:engine
        property int currentframe: 0
        interval: 30
        repeat: true
        running: false
        onTriggered: {
            changFrame(currentframe++)
        }
    }

    Timer {
        id:canstop
        interval: duration
        repeat: false
        running: false
        onTriggered: {
            engine.stop()
        }
    }

    function changRect(){
        frameWidth = img.width / cols;
        frameHeight = img.height / rows;
    }

    function changFrame(frame){

        img.x = -(frame%cols)*frameWidth
        img.y = -(frame%rows)*frameHeight

    }
}
