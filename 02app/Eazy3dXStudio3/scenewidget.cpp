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
    listWidget(NULL)
{
    ui->setupUi(this);

    m_pView = new QQuickView() ;
    m_pView->setResizeMode(QQuickView::SizeViewToRootObject);
    container = QWidget::createWindowContainer(m_pView);
    m_pView->setSource(QUrl("qrc:qml/main.qml"));

    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setAutoFillBackground(true);
//    QVBoxLayout* vLayout = new QVBoxLayout(this);
//    ui->scrollArea->setLayout(vLayout);
//    container->setMinimumSize(200, 200);

//    vLayout->addWidget(container);
    ui->scrollArea->setWidget(container);

    QQmlContext *context = m_pView->rootContext();
    context->setContextProperty("processor", this);
    root = qobject_cast<QQuickItem*>(m_pView->rootObject());

    propertiesPane = new PropertiesPane(this);
    ui->propertyPane->setWidget(propertiesPane);
    listWidget = new DragListWidget(this);
    ui->listArea->setWidget(listWidget);

//    trcInfo("显示qml界面");
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

//    container->resize();
    QString tm = file.baseName();
    QMetaObject::invokeMethod(m_pView->rootObject(), "loadbg",
                              Q_ARG(QVariant,QVariant(bgPath)),
                              Q_ARG(QVariant,QVariant(tm)));
    new QListWidgetItem(QString("bg"),listWidget);
    propertiesPane->insertParentGroup("bg");
}

void SceneWidget::on_selectotherBtn_clicked()
{
    if(bgPath.isEmpty())
        return;
    imagesPathList = QFileDialog::getOpenFileNames(this,
                             "Select one or more images to open",
                             bgPath,
                             "Images (*.png *.jpg)");
    if(imagesPathList.isEmpty())
        return;
    foreach (QString src, imagesPathList) {
        QFileInfo file(src);
        QString tm = file.baseName();
        new QListWidgetItem(tm,listWidget);
        //加入到parentgroup
        propertiesPane->insertParentGroup(tm);
        QMetaObject::invokeMethod(m_pView->rootObject(), "loadimg",
                                  Q_ARG(QVariant,QVariant(src)),
                                  Q_ARG(QVariant,QVariant(tm)));
    }


}

void SceneWidget::on_createxmlBtn_clicked()
{

}

void SceneWidget::initData()
{
    listWidget->clear();
    propertiesPane->clearParentGroup();
//    m_pView->setSource(QUrl("qrc:qml/main.qml"));
}
