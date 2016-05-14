#include "log.h"
#include <QDate>
#include <QTime>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QCoreApplication>
#include <QTextCodec>


QString Log::logFilePath = "../log"; //一定要在类体外初始化
Log::Log()
{
}

Log::~Log()
{

}

void Log::debug(const QString& content)
{
    out(1,content);
}

void Log::info(const QString& content)
{
    out(0,content);
}

void Log::out(const int& flag,const QString& content)
{
    QString data = QDate::currentDate().toString("yyyy-MM-dd");
    QString time = QTime::currentTime().toString("hh:mm:ss.zzz");
    QString str;
    QString tmp = QDate::currentDate().toString("yyyyMMdd");
    QString dirPath = logFilePath+"/"+tmp;
    QDir dir(dirPath);
    if(!dir.exists())
    {
        dir.mkdir(dir.absolutePath());
    }
    QString appName = QCoreApplication::applicationName();
    QString filename = dirPath+"/"+appName+"_"+tmp+".log";
    QFile file(filename);
    if(!file.exists())
    {
        file.open(QIODevice::WriteOnly);
        file.close();
    }

    switch (flag) {
    case 0:
         str = data+" "+time+" [INFO] "+content;
        break;
    case 1:
         str = data+" "+time+" [DBUG] "+content;
        break;
    default:
         str = data+" "+time+" [INFO] "+content;
        break;
    }

    if(file.open(QFile::WriteOnly |
                 QIODevice::Append |
                 QIODevice::Text))
    {
        QTextStream outfile(&file);
        outfile.setCodec("UTF-8");
        outfile<<str<<endl;
    }
    file.close();
}

void Log::setFilePath(const QString& content)
{
    Log::logFilePath = content;
}

QString Log::getFilePath()
{
    return Log::logFilePath;
}


void trcFilePathSet(const QString& content)
{
    Log log;
    log.setFilePath(content);
}

void trcDebug(const QString& content)
{
    Log::debug(content);
}

void trcInfo(const QString& content)
{
    Log::info(content);
}
