#include "fontconvert.h"

Fontconvert::Fontconvert()
{
//    QFile file("ZhConversion.db");
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//             return;

//    QTextStream in(&file);
//    fontdb = in.read(1024);
//    while(!in.atEnd())
//    {
//        QString line = in.readLine();
//        qDebug()<<line;
//        fontdb += line;
//        qDebug()<<fontdb;
//    }
//    fontdb = in.readAll();
//    file.close();
//    qDebug()<<fontdb;

//    std::string strValue =fontdb.toStdString();
//    if (!reader.parse(strValue, root))
//    {
//        qDebug()<<"error.........";
//        return ;

//    }
//    qDebug()<<"read fontdb success.";

}

QString Fontconvert::zh2Han(QString str)
{
    qDebug() << str;
    std::string result =  root[str.toStdString()].asString();

    QString value = QString(result.c_str());
    if(value.isEmpty())
        return str;
    return value;
}
