#include "propertiespane.h"
#include "ui_propertiespane.h"
#include <qdebug.h>

PropertiesPane::PropertiesPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertiesPane),
    scene(NULL)
{
    ui->setupUi(this);
    this->scene = (SceneWidget*)parent;
    this->root = scene->root;
    this->nameEdit.setEnabled(false);
    this->nameEdit.setFrame(false);
    this->xBox.setFrame(false);
    this->yBox.setFrame(false);
    this->widthBox.setFrame(false);
    this->heightBox.setFrame(false);
    this->visibleBox.setChecked(true);
    this->rowsBox.setValue(1);
    this->rowsBox.setFrame(false);
    this->rowsBox.setMinimum(1);
    this->colsBox.setValue(1);
    this->colsBox.setFrame(false);
    this->colsBox.setMinimum(1);
    this->xBox.setMinimum(-2000);
    this->xBox.setMaximum(2000);
    this->yBox.setMinimum(-2000);
    this->yBox.setMaximum(2000);
    this->widthBox.setMaximum(2000);
    this->heightBox.setMaximum(2000);
    this->scaleBox.setFrame(false);
    this->scaleBox.setValue(1.0000);
    this->scaleBox.setMaximum(1.0000);
    this->scaleBox.setDecimals(5);
    this->scaleBox.setSingleStep(0.00001);
    this->anchorxBox.setMinimum(-2000);
    this->anchorxBox.setMaximum(2000);
    this->anchoryBox.setMinimum(-2000);
    this->anchoryBox.setMaximum(2000);
    ui->tableWidget->setCellWidget(0,1,&nameEdit);
    ui->tableWidget->setCellWidget(1,1,&xBox);
    ui->tableWidget->setCellWidget(2,1,&yBox);
    ui->tableWidget->setCellWidget(3,1,&widthBox);
    ui->tableWidget->setCellWidget(4,1,&heightBox);
    ui->tableWidget->setCellWidget(5,1,&anchorxBox);
    ui->tableWidget->setCellWidget(6,1,&anchoryBox);
    ui->tableWidget->setCellWidget(7,1,&visibleBox);
    ui->tableWidget->setCellWidget(8,1,&rowsBox);
    ui->tableWidget->setCellWidget(9,1,&colsBox);
    ui->tableWidget->setCellWidget(10,1,&scaleBox);
    ui->tableWidget->setCellWidget(11,1,&parentBox);

    connect(&anchorxBox,SIGNAL(valueChanged(int)),this,SLOT(setSXanchor(int)));
    connect(&anchoryBox,SIGNAL(valueChanged(int)),this,SLOT(setSYanchor(int)));

    connect(&visibleBox,SIGNAL(clicked(bool)),this,SLOT(setSVisible(bool)));
    connect(&rowsBox,SIGNAL(valueChanged(int)),this,SLOT(setSRow(int)));
    connect(&colsBox,SIGNAL(valueChanged(int)),this,SLOT(setSCol(int)));
    connect(&scaleBox,SIGNAL(valueChanged(double)),this,SLOT(setSScale(double)));
    connect(&parentBox,SIGNAL(currentTextChanged(QString)),this,SLOT(setSParent(QString)));
}

PropertiesPane::~PropertiesPane()
{
    delete ui;
}

void PropertiesPane::setOGameName(QString name)
{
    this->nameEdit.setText(name);
    this->namepr = name;
}

void PropertiesPane::setOX(int x)
{
    this->xBox.setValue(x);
}

void PropertiesPane::setOY(int y)
{
    this->yBox.setValue(y);
}

void PropertiesPane::setOW(int w)
{
    this->widthBox.setValue(w);
}

void PropertiesPane::setOH(int h)
{
    this->heightBox.setValue(h);
}

void PropertiesPane::setOXanchor(int xanchor)
{
    this->anchorxBox.setValue(xanchor);
}

void PropertiesPane::setOYanchor(int yanchor)
{
    this->anchoryBox.setValue(yanchor);
}

void PropertiesPane::setOVisible(bool value)
{
    this->visibleBox.setChecked(value);
}

void PropertiesPane::setORow(int row)
{
    this->rowsBox.setValue(row);
}

void PropertiesPane::setOCol(int col)
{
    this->colsBox.setValue(col);
}

void PropertiesPane::setOScale(double value)
{
    this->scaleBox.setValue(value);
}

void PropertiesPane::setOParent(QString f)
{
//    this->parentBox.setCurrentText(f);

    int index = this->parentBox.findText(f);
    this->parentBox.setCurrentIndex(index);

}

void PropertiesPane::insertParentGroup(QString f)
{
    this->parentBox.addItem(f);
}

void PropertiesPane::clearParentGroup()
{
    this->parentBox.clear();
}


SceneWidget* PropertiesPane::getOScene()
{
    return this->scene;
}

QString PropertiesPane::getOGameName()
{
    return this->nameEdit.text();
}

int PropertiesPane::getOX()
{
    return this->xBox.value();
}

int PropertiesPane::getOY()
{
    return this->yBox.value();
}

int PropertiesPane::getOW()
{
    return this->widthBox.value();
}

int PropertiesPane::getOH()
{
    return this->heightBox.value();
}

int PropertiesPane::getOXanchor()
{
    return this->anchorxBox.value();
}

int PropertiesPane::getOYanchor()
{
    return this->anchoryBox.value();
}

bool PropertiesPane::getOVisible()
{
    return this->visibleBox.isChecked();
}

int PropertiesPane::getORow()
{
    return this->rowsBox.value();
}

int PropertiesPane::getOCol()
{
    return this->colsBox.value();
}

double PropertiesPane::getOScale()
{
    return this->scaleBox.value();
}

QString PropertiesPane::getOParent()
{
    return this->parentBox.currentText();
}

//ui--->qml
void PropertiesPane::setSGameName(QString name)
{
    if(namepr.isEmpty())
        return;
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("objectName",name);
}

void PropertiesPane::setSX(int x)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("x",x);
}

void PropertiesPane::setSY(int y)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("y",y);
}

void PropertiesPane::setSW(int w)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("w",w);
}

void PropertiesPane::setSH(int h)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("h",h);
}

void PropertiesPane::setSXanchor(int xanchor)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("anchorX",xanchor);
//    qDebug()<<"anchorx:"<<xanchor;
}

void PropertiesPane::setSYanchor(int yanchor)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("anchorY",yanchor);
}

void PropertiesPane::setSVisible(bool value)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("shadowVisible",value);
}

void PropertiesPane::setSRow(int row)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("rows",row);
}

void PropertiesPane::setSCol(int col)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("cols",col);
}

void PropertiesPane::setSScale(double value)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("scale",value);
}

void PropertiesPane::setSParent(QString f)
{
    QDeclarativeItem* tm = root->findChild<QDeclarativeItem *>(namepr);
    tm->setProperty("parentName",f);
//    qDebug()<<f;

}

