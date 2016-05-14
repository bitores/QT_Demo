#ifndef FONTCONVERT_H
#define FONTCONVERT_H
#include "json/json.h"
#include <QVariant>
#include <QFile>
#include <QTextStream>
#include <qdebug.h>

using namespace std;

class Fontconvert
{
public:
    Fontconvert();
    QString zh2Han(QString);

private:
    QString fontdb;
    Json::Reader reader;
    Json::Value root;
};

#endif // FONTCONVERT_H
