import QtQuick 1.0
import "logic.js" as Logic


Rectangle {
    id:main
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
        scale: 1.0

        property int cols: 1
        property int rows: 1

        onRowsChanged: {
            main.height = bg.height / rows
        }
        onColsChanged: {
            main.width  = bg.width / cols
        }
        onScaleChanged: {
            main.height = bg.height / rows * scale
            main.height = bg.height / rows * scale
        }

        MouseArea{

            anchors.fill: bg
            onPressed: {
                Logic.noticeName(bg.objectName)
                Logic.noticeX(bg.x)
                Logic.noticeY(bg.y)
                Logic.noticeW(bg.width)
                Logic.noticeH(bg.height)
                Logic.noticeAnchorX(0)
                Logic.noticeAnchorY(0)
                Logic.noticeScale(bg.scale)
                Logic.noticeRow(bg.rows)
                Logic.noticeCol(bg.cols)
                Logic.noticeParentwhich("")
            }
        }
    }

    Item{
        id:container
        width: parent.width
        height: parent.width

        property int z_index: 2
    }







//load images
    function loadbg(src ,name ){
        bg.source = "file:///"+src
    }
    function loadimg(src,name ){
        var component = Qt.createComponent("DragSprite.qml");
        if (component.status === Component.Ready)
        {
            var dragimg = component.createObject(container);
            dragimg.source = "file:///"+src;
            dragimg.objectName = name;
        }
    }
//clear scene
    function clearScene()
    {
        main.destroy();
    }

    function changRect(){

    }

}
