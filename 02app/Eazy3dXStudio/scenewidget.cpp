#include "scenewidget.h"
#include "ui_scenewidget.h"

#include <QFileDialog>
#include <QDir>
#include <QFileInfo>

#include "../../01public/logout/log.h"

SceneWidget::SceneWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SceneWidget),
    m_pView(NULL),
    propertiesPane(NULL),
    listWidget(NULL),
    xml(NULL)
{
    ui->setupUi(this);

    m_pView = new QDeclarativeView() ;
    m_pView->setSource(QUrl("qrc:qml/main.qml"));

    QDeclarativeContext *context = m_pView->rootContext();
    context->setContextProperty("processor", this);

    m_pView->setResizeMode(QDeclarativeView::SizeViewToRootObject);
    m_pView->move(QPoint(0,0));
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setAutoFillBackground(true);
    ui->scrollArea->setWidget(m_pView);
    root = qobject_cast<QDeclarativeItem*>(m_pView->rootObject());
    propertiesPane = new PropertiesPane(this);
    ui->propertyPane->setWidget(propertiesPane);
    listWidget = new DragListWidget(this);
    ui->listArea->setWidget(listWidget);

//    trcInfo("显示qml界面");
    xml = new SceneXML(this);
}

SceneWidget::~SceneWidget()
{
    delete ui;
    delete m_pView;
    delete propertiesPane;
}

void SceneWidget::setGameName(QString name)
{
    propertiesPane->setOGameName(name);
}

void SceneWidget::setOX(int x)
{
    propertiesPane->setOX(x);
}

void SceneWidget::setOY(int y)
{
    propertiesPane->setOY(y);
}

void SceneWidget::setOW(int w)
{
    propertiesPane->setOW(w);
}

void SceneWidget::setOH(int h)
{
    propertiesPane->setOH(h);
}

void SceneWidget::setOXanchor(int anchorx)
{
    propertiesPane->setOXanchor(anchorx);
}

void SceneWidget::setOYanchor(int anchory)
{
    propertiesPane->setOYanchor(anchory);
}

void SceneWidget::setOVisible(bool visible)
{
    propertiesPane->setOVisible(visible);
}

void SceneWidget::setORow(int r)
{
    propertiesPane->setORow(r);
}

void SceneWidget::setOCol(int c)
{
    propertiesPane->setOCol(c);
}

void SceneWidget::setOScale(double value)
{
    propertiesPane->setOScale(value);
}

void SceneWidget::setOParent(QString f)
{
    propertiesPane->setOParent(f);
}


void SceneWidget::on_selectbgBtn_clicked()
{


    bgPath = QFileDialog::getOpenFileName(this,
                                      tr("Open bg"),
                                      QDir::homePath(),
                                      tr("Images (*.png *.jpg)"));
    if(bgPath.isEmpty())
        return;
    initData();
    QFileInfo file(bgPath);
    QString tm = file.baseName();
    filepath = file.absolutePath();
    QMetaObject::invokeMethod(m_pView->rootObject(), "loadbg",
                              Q_ARG(QVariant,QVariant(bgPath)),
                              Q_ARG(QVariant,QVariant(tm)));
    new QListWidgetItem(QString("bg"),listWidget);
    fileList.append("bg");
    propertiesPane->insertParentGroup("");
    propertiesPane->insertParentGroup("bg");

}

void SceneWidget::on_selectotherBtn_clicked()
{
    if(bgPath.isEmpty())
        return;
    imagesPathList = QFileDialog::getOpenFileNames(this,
                             "Select one or more images to open",
                             filepath,
                             "Images (*.png *.jpg)");
    if(imagesPathList.isEmpty())
        return;
    foreach (QString src, imagesPathList) {
        QFileInfo file(src);
        QString tm = file.baseName();
        new QListWidgetItem(tm,listWidget);
        fileList.append(tm);
        //加入到parentgroup
        propertiesPane->insertParentGroup(tm);
        QMetaObject::invokeMethod(m_pView->rootObject(), "loadimg",
                                  Q_ARG(QVariant,QVariant(src)),
                                  Q_ARG(QVariant,QVariant(tm)));
    }


}

void SceneWidget::on_createxmlBtn_clicked()
{
    QString path = filepath+"/scene.xml";
    xml->createXML(path,fileList);
    xml->GameObjectCreate(fileList);













}

void SceneWidget::initData()
{
    listWidget->clear();
    propertiesPane->clearParentGroup();
//    m_pView->setSource(QUrl(""));
//    ui->scrollArea->setWidget(NULL);
    resetSource();
}

void SceneWidget::resetSource()
{

//    m_pView->setSource(QUrl("qrc:qml/main.qml"));
}
