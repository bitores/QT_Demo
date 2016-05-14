import QtQuick 2.0
import "logic.js" as Logic


Rectangle {

    width: bg.width
    height: bg.height
//    border.color: "red"
//    border.width: 3
//    clip: true

    Image {
        id: bg
        source: ""
        objectName: "bg"
        visible: true

        MouseArea{

            anchors.fill: bg
            onPressed: {
                Logic.noticeName(bg.objectName)
                Logic.noticeX(bg.x)
                Logic.noticeY(bg.y)
                Logic.noticeW(bg.width)
                Logic.noticeH(bg.height)
            }
        }
    }

    Item{
        id:container
        width: parent.width
        height: parent.width

        property int z_index: 2
    }








    function loadbg(src ,name ){
        bg.source = "file:///"+src
    }
    function loadimg(src,name ){
        var component = Qt.createComponent("DragSprite.qml");
        if (component.status === Component.Ready)
        {
    //        console.log(""+src);
            var dragimg = component.createObject(container);
            dragimg.source = "file:///"+src;
            dragimg.objectName = name;
            console.log(":"+name)
        }
    }
}
