#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QWidget>
#include <QGraphicsObject>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QDeclarativeItem>
#include <QMetaObject>

#include "propertiespane.h"
#include "DragListWidget.h"
#include "scenexml.h"

class PropertiesPane;
class DragListWidget;
class SceneXML;
namespace Ui {
class SceneWidget;
}

class SceneWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SceneWidget(QWidget *parent = 0);
    ~SceneWidget();

private:
    Ui::SceneWidget *ui;
    QDeclarativeView*  m_pView;
    PropertiesPane* propertiesPane;
    DragListWidget* listWidget;

    QString filepath;
    QStringList fileList;
    SceneXML* xml;

public:
    //qml 操作 ui
    Q_INVOKABLE void setGameName(QString name);
    Q_INVOKABLE void setOX(int x);
    Q_INVOKABLE void setOY(int y);
    Q_INVOKABLE void setOW(int w);
    Q_INVOKABLE void setOH(int h);
    Q_INVOKABLE void setOXanchor(int anchorx);
    Q_INVOKABLE void setOYanchor(int anchory);
    Q_INVOKABLE void setOVisible(bool visible);
    Q_INVOKABLE void setORow(int r);
    Q_INVOKABLE void setOCol(int c);
    Q_INVOKABLE void setOScale(double value);
    Q_INVOKABLE void setOParent(QString f);
private slots:
    void on_selectbgBtn_clicked();
    void on_selectotherBtn_clicked();
    void on_createxmlBtn_clicked();
    void initData();
    void resetSource();

public:
    QDeclarativeItem *root;
    QString bgPath;
    QStringList imagesPathList;
};

#endif // SCENEWIDGET_H
