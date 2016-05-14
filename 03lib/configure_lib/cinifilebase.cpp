#include "cinifilebase.h"
#include <QFile>

#include "../../01public/logout/log.h"
#include <qcoreapplication.h>

CIniFileBase::CIniFileBase(QObject *parent) :
    QObject(parent)
{
}

//virtual
CIniFileBase::~CIniFileBase()
{

}

int CIniFileBase::read(QString strFile)
{
    defaultFile(strFile);
    if(!checkFile(strFile))
    {
        return -1;
    }

    QSettings sett(strFile,QSettings::IniFormat);
    readData(sett);
    return 0;
}

int CIniFileBase::write(QString strFile)
{
    defaultFile(strFile);
    if(checkFile(strFile))
    {
        QFile file(strFile);
        file.remove();
    }
    QSettings sett(strFile, QSettings::IniFormat);
    sett.setIniCodec("UTF-8");
    writeData(sett);
}

bool CIniFileBase::checkFile(const QString& strFile)
{
    //判断配置文件是否存在
    if(!QFile::exists(strFile))
    {
        trcInfo("缺少配置文件["+strFile+"]");
        return false;
    }
    return true;
}

void CIniFileBase::defaultFile(QString& str)
{
    if(0>=str.size())
    {
        QString filepath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        str = filepath.left(filepath.size()-4) + "/cfg/static_app.ini";
    }

    trcInfo(str);
}
