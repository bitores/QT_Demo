
function loadBackground (src , name)
{
    bg.source = "file:///"+src
    console.log(name)
}

function loadOtherPix( src ,name )
{

    console.log(""+src);
    var component = Qt.createComponent("DragImage.qml");
    if (component.status === Component.Ready)
    {

        var dragimg = component.createObject(container);
        dragimg.src = "file:///"+src;
        dragimg.objectName = name;
        console.log(name)

    }

}



