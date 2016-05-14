#ifndef SCENEXML_H
#define SCENEXML_H

#include <QObject>
#include <QDeclarativeItem>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDomDocument>
#include "scenewidget.h"

class SceneWidget;
class SceneXML : public QObject
{
    Q_OBJECT
public:
    explicit SceneXML(QObject *parent = 0);

signals:

public slots:

public:
    bool createXML(QString filepath,QStringList list);
    bool closeXML();
    QString headCreate();
    QString MaterialCreate(QStringList objlist);
    QString eRectCreate(QStringList objlist);
    QString containerCreate();
    void GameObjectCreate(QStringList objlist);
    QString footCreate();

private:
    QDeclarativeItem *root;
    SceneWidget *scene;
    QString filepath;

private:
    inline QString getPropertyValue(QString aProperty ,QString obj);
    inline double getPropertyValueD(QString aProperty ,QString obj);
    inline QString getSuffixName(QString aProperty ,QString obj);
};

#endif // SCENEXML_H
