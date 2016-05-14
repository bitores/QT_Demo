#ifndef PROPERTIESPANE_H
#define PROPERTIESPANE_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDeclarativeItem>
#include <QCheckBox>
#include <QComboBox>

#include "scenewidget.h"

class SceneWidget;
namespace Ui {
class PropertiesPane;
}

class PropertiesPane : public QWidget
{
    Q_OBJECT

public:
    explicit PropertiesPane(QWidget *parent = 0);
    ~PropertiesPane();

private:
    Ui::PropertiesPane *ui;

private:
    QDeclarativeItem *root;
    QString namepr;
    SceneWidget *scene;
    QLineEdit nameEdit;
    QSpinBox xBox;
    QSpinBox yBox;
    QSpinBox widthBox;
    QSpinBox heightBox;
    QCheckBox visibleBox;
    QSpinBox rowsBox;
    QSpinBox colsBox;
    QDoubleSpinBox scaleBox;
    QComboBox parentBox;
    QSpinBox anchorxBox;
    QSpinBox anchoryBox;

public:
    // qml->scene->properties->kongjian
    void setOGameName(QString name);
    void setOX(int x);
    void setOY(int y);
    void setOW(int w);
    void setOH(int h);
    void setOXanchor(int xanchor);
    void setOYanchor(int yanchor);
    void setOVisible(bool value);
    void setORow(int row);
    void setOCol(int col);
    void setOScale(double value);
    void setOParent(QString f);
    void insertParentGroup(QString f);
    void clearParentGroup();

    SceneWidget* getOScene();
    QString getOGameName();
    int getOX();
    int getOY();
    int getOW();
    int getOH();
    int getOXanchor();
    int getOYanchor();
    bool getOVisible();
    int getORow();
    int getOCol();
    double getOScale();
    QString getOParent();

private slots:
    //ui->scene->qml
    void setSGameName(QString name);
    void setSX(int x);
    void setSY(int y);
    void setSW(int w);
    void setSH(int h);
    void setSXanchor(int xanchor);
    void setSYanchor(int yanchor);
    void setSVisible(bool value);
    void setSRow(int row);
    void setSCol(int col);
    void setSScale(double value);
    void setSParent(QString f);
};

#endif // PROPERTIESPANE_H
