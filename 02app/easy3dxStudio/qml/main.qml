import QtQuick 1.1
import "logic.js" as Logic


Rectangle {
    width: bg.width
    height: bg.height

    Image {
        id: bg
        source: ""
        objectName: "bg"
    }

    Item{
        id:container
        width: parent.width
        height: parent.width

        property int z_index: 1
    }
    function loadbg(src ,name ){
        Logic.loadBackground(src ,name)
    }
    function loadimg(src,name ){
        Logic.loadOtherPix(src,name)
    }
}


