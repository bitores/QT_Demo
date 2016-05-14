#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QWidget>
#include <QGraphicsObject>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickItem>
#include <QMetaObject>

#include "propertiespane.h"
#include "DragListWidget.h"

class PropertiesPane;
class DragListWidget;
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
    QQuickView*  m_pView;
    QWidget *container;
    PropertiesPane* propertiesPane;
    DragListWidget* listWidget;

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

public:
    QQuickItem *root;
    QString bgPath;
    QStringList imagesPathList;
};

#endif // SCENEWIDGET_H
