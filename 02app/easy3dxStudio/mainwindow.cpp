#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../01public/logout/log.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pView(NULL),
    sm_cfg(NULL)
{
    ui->setupUi(this);
    vbox = new QVBoxLayout;
    m_pView = new QDeclarativeView() ;
    QDeclarativeContext *context = m_pView->rootContext();
    context->setContextProperty("processor", this);

    m_pView->setSource(QUrl("qrc:qml/main.qml"));
    m_pView->setResizeMode(QDeclarativeView::SizeViewToRootObject);
    m_pView->move(QPoint(0,0));
    ui->scrollArea->setBackgroundRole(QPalette::Dark);

    ui->scrollArea->setWidget(m_pView);
    ui->scrollArea->setWidgetResizable(true);
    trcInfo("显示qml界面");

    root = qobject_cast<QDeclarativeItem*>(m_pView->rootObject());
    sm_cfg = CCfg::Instance();
    int ret = sm_cfg->readIni();
    sdkdir = sm_cfg->m_client.getSDKDir();
    prooutdir = sm_cfg->m_client.getProOutDir();
    releasedir = sm_cfg->m_client.getReleaseDir();
    importdir = sm_cfg->m_client.getImportDir();

    ui->sdkdir->setText(sdkdir);
    ui->outdir->setText(prooutdir);
    ui->importdir->setText(importdir);

    cmd = new QProcess;
    connect(cmd, SIGNAL(readyRead()), this, SLOT(readmess()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_selBg_clicked()
{
    //init
    initData();
    //add bg
    bg = QFileDialog::getOpenFileName(this,
                                      tr("Open bg"),
                                      QDir::homePath(),
                                      tr("Images (*.png *.jpg)"));


    QFileInfo file(bg);
    QString name = file.baseName();
    ui->bg->setText(file.fileName());
    path = file.absolutePath();
    QMetaObject::invokeMethod(m_pView->rootObject(), "loadbg",Q_ARG(QVariant,QVariant(bg)),Q_ARG(QVariant,QVariant(name)));
    QImage img(bg);
    bg_w = img.width();
    bg_h = img.height();


    //scene.xml for bg
    material =  QString("<Material name=\"bg_material\">\n")+
                "   <Pass\n"+
                "       vertex_program_ref=\"texture.vert\"\n"+
                "       fragment_program_ref=\"texture.frag\"\n"+
                "       culling_mode=\"anticlockwise\"\n"+
                "       depth_write=\"false\">\n"+
                "       <TextureUnit texture=\""+file.fileName()+"\"/>\n"+
                "   </Pass>\n"+
                "</Material>\n";
    erect = "<eRect name=\"bg_rect\" anchor=\"top_left\" scale=\"1 1 0 2\"/>\n";
}

void MainWindow::on_selOther_clicked()
{
    if(path.isEmpty())
        return;
    otherimages = QFileDialog::getOpenFileNames(this,
                             "Select one or more images to open",
                             path,
                             "Images (*.png *.jpg)");
    QString o;

    for(int i = otherimages.length() -1;i>=0;i--)
    {
        QString src = otherimages.at(i);
        QFileInfo file(src);
        QString name = file.baseName();
        filelist.append(name);
        QMetaObject::invokeMethod(m_pView->rootObject(), "loadimg",Q_ARG(QVariant,QVariant(src)),
                                  Q_ARG(QVariant,QVariant(name)));

         o += file.fileName();
         o +="\n";

         QImage img(file.absoluteFilePath());
         int sel_w = img.width();
         int sel_h = img.height();
         double scale_x = sel_w*1.0/bg_w;
         double scale_y = sel_h*1.0/sel_w;

    //scene.xml for other
     material += "<Material name=\""+name+"_material\">\n"+
                 "   <Pass\n"+
                 "       vertex_program_ref=\"texture.vert\"\n"+
                 "       fragment_program_ref=\"texture.frag\"\n"+
                 "       culling_mode=\"anticlockwise\"\n"+
                 "       depth_write=\"false\"\n"+
                 "       scene_blend=\"src_alpha one_minus_src_alpha\">\n"+
                 "       <TextureUnit texture=\""+file.fileName()+"\"/>\n"+
                 "   </Pass>\n"+
                 "</Material>\n";
     erect += "<eRect name=\""+name+"_rect\" anchor=\"top_left\" scale=\""+QString::number(scale_x)+" "+QString::number(scale_y)+" 0 1\"/>\n";
    }
    ui->others->setPlainText(o);

}

void MainWindow::on_createScene_clicked()
{
    gameobj =   QString("<GameObject name=\"container\">\n")+
                "<GameObject name=\"bg\">\n"+
                "    <Transform position=\"0 0 0 1\"/>\n"+
                "    <Renderer material=\"bg_material\"/>\n"+
                "    <MeshFilter mesh=\"bg_rect\"/>\n"+
                "</GameObject>\n";

    for(int i = filelist.length() -1 ;i >=0;i--)
    {
        QString name = filelist.at(i);
        QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(name);
        int tm_x = tm->property("x").toInt();
        int tm_y = tm->property("y").toInt();
        double scale_x = tm_x*1.0/bg_w;
        double scale_y = tm_y*1.0/bg_h;


        gameobj +=  "<GameObject name=\""+name+"\">\n"+
                    "    <Transform position=\""+QString::number(scale_x)+" "+QString::number(scale_y)+" 0 1\"/>\n"+
                    "    <Renderer material=\""+name+"_material\"/>\n"+
                    "    <MeshFilter mesh=\""+name+"_rect\"/>\n"+
                    "</GameObject>\n";
    }

    gameobj +="     <!--<ParticleSystem name=\"ps_root\" src=\"particle_system.particle\" />-->\n"
              "</GameObject>\n";

    createSceneXML(material,erect,gameobj);
}

void MainWindow::createSceneXML(QString material,QString erect,QString gameobj)
{
    if(filelist.isEmpty())
        return;

    QString info;
    info =  QString("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n\n")+

            "<Scene clear_depth=\"1.0\" >\n"+
            "    <Camera name=\"main_camera\" width=\"1\" height=\"1\" auto_screen_size=\"true\" />\n"+
            "    <RenderTarget width=\"1\" height=\"1\" >\n"+
            "        <Viewport name=\"main_viewport\" camera=\"main_camera\" background_color=\"0.2 0.3 0.4 1\" left=\"0\" top=\"0\" width=\"1\" height=\"1\" />\n"+
            "    </RenderTarget>\n\n"+

            "<!-- -------------------------------------------------------------------------------------------------------\n"+
            "----- Scene config ---------------------------------------------------------------------------------------->\n"+
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



    info    += material;
    info    +="\n";
    info    += erect;
    info    +="\n";
    info    += gameobj;
    info    +="\n";

    info  += QString("    <!--<Lua src=\"main.lua\"/>-->\n\n")+

            "</Scene>\n";



    QFile file(path+"/scene.xml");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << info;
    file.close();
    ui->statusbar->showMessage(path+"/scene.xml");

}

void MainWindow::initData()
{
    m_pView->setSource(QUrl("qrc:qml/main.qml"));
    ui->bg->clear();
    ui->others->clear();
    filelist.clear();
    material.clear();
    erect.clear();
    gameobj.clear();
    ui->statusbar->clearMessage();
}

void MainWindow::on_fontconvt_clicked()
{
    QString tm = ui->znfont->text();
    if(tm.isEmpty())
        return;
    int len = tm.length();
    QString show;
    foreach (QString word, tm) {
        show += convert.zh2Han(word);
    }
    ui->twfont->setText(show);
}

void MainWindow::on_sdkconfig_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     sdkdir,
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    if(path.isEmpty())
        return;
    sm_cfg->m_client.setSDKDir(path);
    ui->sdkdir->setText(path);
    sm_cfg->writeIni();
}

void MainWindow::on_outdirconfig_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     prooutdir,
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    if(path.isEmpty())
        return;
    sm_cfg->m_client.setProOutDir(path);
    ui->outdir->setText(path);
    sm_cfg->writeIni();
}

void MainWindow::on_importdirconfig_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     importdir,
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    if(path.isEmpty())
        return;
    sm_cfg->m_client.setImportDir(path);
    ui->importdir->setText(path);
    sm_cfg->writeIni();
}

void MainWindow::on_createBtn_clicked()
{   QString proname = ui->proname->text();
    QString serial = ui->series->text();
    if(proname.isEmpty())
        return;
    ui->message->setPlainText("start...");
    if(serial.isEmpty())
    {
        QStringList arguments;
        arguments<<sdkdir+"myshare/tools/create-subproj-from-templateproj.py" <<"LWP"<<"-"<<proname<<prooutdir;
        ui->message->setPlainText("start...\n");
        cmd->start("python",arguments);
    }else{
        QStringList arguments;
        arguments<<sdkdir+"myshare/tools/create-subproj-from-templateproj.py" <<"LWP"<<serial<<proname<<prooutdir;
        ui->message->setPlainText("start...\n");
        cmd->start("python",arguments);
    }
}

void MainWindow::readmess()
{
    QString outmess = cmd->readAll();
    QString tx = ui->message->toPlainText();
    ui->message->setPlainText(tx+outmess);
}

void MainWindow::on_importBtn_clicked()
{
    QString predirpath = ui->predir->text();
    if(predirpath.isEmpty() || proPath.isEmpty())
        return;
    QProcess cmd2 ;
    QStringList arguments;
    arguments<<importdir+"/beReady.py"<<proPath<<predirpath;
    cmd2.start("python",arguments);
    ui->importmessage->setText("start...");
}

void MainWindow::on_pushButton_6_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     "",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    if(path.isEmpty())
        return;
    ui->predir->setText(path);
}

void MainWindow::on_propathBtn_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     prooutdir,
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    if(path.isEmpty())
        return;
    ui->propah->setText(path);
    proPath = path;
}

void MainWindow::on_selectICO_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open Image"), "", tr("Image Files (*.png *.jpg)"));
    if(path.isEmpty())
        return;
    ui->iconpath->setText(path);
}

void MainWindow::on_createICO_clicked()
{
    QString path = ui->iconpath->text();
    if(path.isEmpty())
        return;
    QProcess cmd1;
    QStringList arguments;
    arguments<<path;
    cmd1.start("Drop4IconSize.exe",arguments);
}
