#include "scenexml.h"
#include <qdebug.h>

SceneXML::SceneXML(QObject *parent) :
    QObject(parent),
    root(NULL),
    scene(NULL)
{
    this->scene = (SceneWidget*)parent;
    this->root = scene->root;
}

bool SceneXML::createXML(QString filepath,QStringList list)
{
    QFile file(filepath);
    this->filepath = filepath;
    if(file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&file);
        out.setCodec("UTF-8");
        QString head = headCreate();
        QString Material = MaterialCreate(list);
        QString eRect = eRectCreate(list);
        QString container = containerCreate();
        QString foot = footCreate();
        out<<head<<Material<<eRect<<container<<foot;

    }
    file.close();
}

bool SceneXML::closeXML()
{

}

QString SceneXML::headCreate()
{
    QString info;
    info =  QString("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n\n")+

            "<Scene clear_depth=\"1.0\" >\n"+
            "    <Camera name=\"main_camera\" width=\"1\" height=\"1\" auto_screen_size=\"true\" />\n"+
            "    <RenderTarget width=\"1\" height=\"1\" >\n"+
            "        <Viewport name=\"main_viewport\" camera=\"main_camera\" background_color=\"0.2 0.3 0.4 1\" left=\"0\" top=\"0\" width=\"1\" height=\"1\" />\n"+
            "    </RenderTarget>\n\n\n"+

//            "<!-- -------------------------------------------------------------------------------------------------------\n"+
//            "----- Scene config ---------------------------------------------------------------------------------------->\n"+
            "<Programs>\n"+
            "    <vertex_program name=\"texture.vert\" source=\"texture.vert\" >\n"+
            "        <default_params pn_type=\"param_named_auto\" name=\"worldViewProj\" value=\"worldviewproj_matrix\" />\n"+
            "        <default_params pn_type=\"param_named_auto\" name=\"textureMatrix\" value=\"texture_matrix\" />\n"+
            "    </vertex_program>\n"+
            "    <fragment_program name=\"texture.frag\" source=\"texture.frag\" />\n"+
            "</Programs>\n\n"+

            "<Programs>\n"+
            "    <vertex_program name=\"texture_incolor.vert\" source=\"texture_incolor.vert\" >\n"+
            "        <default_params pn_type=\"param_named_auto\" name=\"worldViewProj\" value=\"worldviewproj_matrix\" />\n"+
            "        <default_params pn_type=\"param_named_auto\" name=\"textureMatrix\" value=\"texture_matrix\" />\n"+
            "    </vertex_program>\n"+
            "    <fragment_program name=\"texture_incolor.frag\" source=\"texture_incolor.frag\" />\n"+
            "</Programs>\n\n"+

            "<Programs>\n"+
            "    <vertex_program name=\"texture_alpha.vert\" source=\"texture_alpha.vert\" >\n"+
            "        <default_params pn_type=\"param_named_auto\" name=\"worldViewProj\" value=\"worldviewproj_matrix\" />\n"+
            "        <default_params pn_type=\"param_named_auto\" name=\"textureMatrix\" value=\"texture_matrix\" />\n"+
            "    </vertex_program>\n"+
            "    <fragment_program name=\"texture_alpha.frag\" source=\"texture_alpha.frag\" >\n"+
            "        <default_params pn_type=\"param_named_auto\" name=\"uAlpha\" value=\"surface_shininess\"/>\n"+
            "    </fragment_program>\n\n"+


            "    <vertex_program name=\"texture_incolor.vert\" source=\"texture_incolor.vert\" >\n"+
            "    <default_params pn_type=\"param_named_auto\" name=\"worldViewProj\" value=\"worldviewproj_matrix\" />\n"+
            "    <default_params pn_type=\"param_named_auto\" name=\"textureMatrix\" value=\"texture_matrix\" />\n"+
            "    </vertex_program>\n"+
            "    <fragment_program name=\"texture_incolor.frag\" source=\"texture_incolor.frag\" />\n\n"+

            "</Programs>\n\n\n";

            /*
             * 此处为Material、eRect、GameObject
            */

    return info;

}

QString SceneXML::MaterialCreate(QStringList objlist)
{
    QString info;
    int len = objlist.length();
    for(int i=0;i<len;i++)
    {
        QString obj = objlist.at(i);
        QString suffix = getSuffixName("source",obj);
        if(suffix == "png")
        {
            info = QString("<Material name=\""+obj+"_material\">\n")+
                    "   <Pass\n"+
                    "       vertex_program_ref=\"texture.vert\"\n"+
                    "       fragment_program_ref=\"texture.frag\"\n"+
                    "       culling_mode=\"anticlockwise\"\n"+
                    "       depth_write=\"false\"\n"+
                    "       scene_blend=\"src_alpha one_minus_src_alpha\">\n"+
                    "       <TextureUnit texture=\""+obj+suffix+"\"/>\n"+
                    "   </Pass>\n"+
                    "</Material>\n";
        }else if(suffix == "jpg"){
            info = QString("<Material name=\""+obj+"_material\">\n")+
                    "   <Pass\n"+
                    "       vertex_program_ref=\"texture.vert\"\n"+
                    "       fragment_program_ref=\"texture.frag\"\n"+
                    "       culling_mode=\"anticlockwise\"\n"+
                    "       depth_write=\"false\">\n"+
                    "       <TextureUnit texture=\""+obj+suffix+"\"/>\n"+
                    "   </Pass>\n"+
                    "</Material>\n";
        }
    }

    return info;
}

QString SceneXML::eRectCreate(QStringList objlist)
{
    QString info;
    int len = objlist.length();
    double r = getPropertyValueD("rows","bg");
    double c = getPropertyValueD("cols","bg");
    double w = getPropertyValueD("width","bg") / c;

    info = "<eRect name=\"bg_rect\" anchor=\"custom_anchor\" custom_anchor=\"0 0 0\" scale=\"1 1 0 2\"/>\n";
    for(int i=1;i<len;i++)
    {
        QString obj = objlist.at(i);

        double anchorx = getPropertyValueD("anchorX",obj);
        double anchory = getPropertyValueD("anchorY",obj);
        int row = getPropertyValueD("rows",obj);
        int col = getPropertyValueD("cols",obj);
        double scale = getPropertyValueD("scale",obj);
        double sel_w = getPropertyValueD("width",obj) / col * scale;
        double sel_h = getPropertyValueD("height",obj) / row * scale;

        double scalex = sel_w / w;
        double scaley = sel_h / sel_w;

        if(1 !=row || 1!= col)
        {
            info +="<eRect name=\""+obj+"_rect\" anchor=\"custom_anchor\" custom_anchor=\""+QString::number(anchorx/sel_w)+" "+QString::number(anchory/sel_h)+" 0\" scale=\""+QString::number(scalex)+" "+QString::number(scaley)+" 0 1\" slice=\""+QString::number(row)+" "+QString::number(col)+"\"/>\n";
        }else{
            info +="<eRect name=\""+obj+"_rect\" anchor=\"custom_anchor\" custom_anchor=\""+QString::number(anchorx/sel_w)+" "+QString::number(anchory/sel_h)+" 0\" scale=\""+QString::number(scalex)+" "+QString::number(scaley)+" 0 1\"/>\n";
        }

    }

    return info;
}

QString SceneXML::containerCreate()
{
    QString info;
    info =  QString("<GameObject name=\"container\">\n")+
            "<GameObject name=\"bg\">\n"+
            "    <Transform position=\"0 0 0 1\"/>\n"+
            "    <Renderer material=\"bg_material\"/>\n"+
            "    <MeshFilter mesh=\"bg_rect\"/>\n"+
            "</GameObject>\n\n\n"+



            "</GameObject>\n";

    return info;
}

void SceneXML::GameObjectCreate(QStringList objlist)
{
    QString info;
    QFile file(filepath);
    QDomDocument doc;
    if(file.open(QIODevice::ReadOnly|QIODevice::WriteOnly))
    {
        doc.setContent(&file);

    }

    QDomNode root = doc.childNodes().at(1);
    QDomNodeList list = root.childNodes();

    QDomNode objContainer;

    for(int i=0;i<list.length();i++)
    {
        QDomNode node = list.at(i);
        if("GameObject" == node.nodeName())
        {
            objContainer = node;

            break;
        }
        qDebug()<<node.namedItem("GameObject");
    }

//    list = objContainer.childNodes();
//    for(int i=0;i<list.length();i++)
//    {

//    }






    int len = objlist.length();
    for(int i=1;i<len;i++)
    {
        QString obj = objlist.at(i);
        double x = getPropertyValueD("x",obj);
        double y = getPropertyValueD("y",obj);
        QString father = getPropertyValue("parentName",obj);
        if(!father.isEmpty())
        {
            double w = getPropertyValueD("width",father);
            double h = getPropertyValueD("height",father);

        }else{

//            objContainer.appendChild();
        }



    }

    file.close();
}

QString SceneXML::footCreate()
{
    QString info;
    info = "</Scene>";
    return info;
}

QString SceneXML::getPropertyValue(QString aProperty ,QString obj)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(obj);
    return tm->property(aProperty.toLatin1()).toString();
}

double SceneXML::getPropertyValueD(QString aProperty ,QString obj)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(obj);
    return tm->property(aProperty.toLatin1()).toDouble();
}

QString SceneXML::getSuffixName(QString aProperty ,QString obj)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(obj);
    QString value = tm->property(aProperty.toLatin1()).toString();
    QFileInfo file(value);
    return file.baseName();
}
