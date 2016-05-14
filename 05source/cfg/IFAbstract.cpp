#include "IFAbstract.h"

#include "trace.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qfile.h>
#include "SpyCrypt.h"

CIFAbstract::CIFAbstract(QObject *parent) :
    QObject(parent)
{
}

CIFAbstract::~CIFAbstract()
{

}

int CIFAbstract::Read(QString strFile /*= ""*/)
{
    //必须先读取到设备编号才能记录日志,因为日志文件名称中包含设备编号
    if (!strFile.contains("static_fortuna.ini"))
    {
        trcInfo(QString("读取配置文件:开始[%1]").arg(strFile));
    }

    int iret = -1;
    if (1 != (iret = CheckFile(strFile)))
    {
        return iret;
    }

    if (1 != (iret = ExistFile(strFile)))
    {
        return iret;
    }

    bool bEncrypt = false;
    bEncrypt = IsEncryptFile(strFile);

    //需要解密
    if (bEncrypt)
    {
        QString strTmpFile = strFile.left(strFile.lastIndexOf(".")) + ".tmp";
        //解密数据库配置ini文件到临时文件
        int iDecrypt = -1;
        iDecrypt = CSpyCrypt::DecrptyIniFile(strFile, strTmpFile);

        QSettings set(strTmpFile, QSettings::IniFormat);
        set.setIniCodec(QTextCodec::codecForName("UTF-8"));

        //读取数据
        iret = ReadData(set);

        //删除临时文件
        QFile::remove(strTmpFile);
    }
    //不需要解密
    else
    {
        QSettings set(strFile, QSettings::IniFormat);
        set.setIniCodec(QTextCodec::codecForName("UTF-8"));
        //读取数据
        iret = ReadData(set);
    }

    if (!strFile.contains("static_fortuna.ini"))
    {
        trcInfo(QString("读取配置文件:结束[%1]").arg(strFile));
    }

    return iret;
}


int CIFAbstract::Write(QString strFile /*= ""*/, bool bCoverIfExist /*= true*/, bool bEncrypt /*= false*/)
{
    int iret = -1;
    CheckFile(strFile);
    QString strlog = "";
    //如果存在,覆盖原文件
    if (bCoverIfExist)
    {
        if (QFile::exists(strFile))
        {
            QFile::remove(strFile);
        }
    }
    else
    {
        if (QFile::exists(strFile))
        {
            //strlog = QString("CIFAbstract::Write failed errorno:-2000. cfg file is exist[%1]").arg(strFile);
            strlog = QString("修改配置文件:失败.文件[%1]不存在.").arg(strFile);
            trcError(strlog);
            return -2000;
        }
    }

    //获取路径
    QString strPath = "";
    int iindex = -1;
    iindex = strFile.lastIndexOf("/");
    if (-1 == iindex)
    {
        //strlog = QString("CIFAbstract::Write failed errorno:-2001. cfg file path is error[%1]").arg(strFile);
        strlog = QString("修改配置文件:失败.文件路径[%1]错误.").arg(strFile);
        trcError(strlog);
        return -2001;
    }
    else
    {
        strPath = strFile.left(iindex);
    }

    //验证路径
    QDir dir(strPath);
    if (!dir.exists())
    {
        dir.mkpath(strPath);
        dir.setPath(strPath);
    }
    if (!dir.exists())
    {
        //strlog = QString("CIFAbstract::Write failed errorno:-2002. create path failed[%1]").arg(strPath);
        strlog = QString("修改配置文件:失败.创建路径[%1]失败.").arg(strPath);
        trcError(strlog);
        return -2002;
    }

    //先删除，避免数据重复
    QFile::remove(strFile);

    //需要加密
    if (bEncrypt)
    {
        QString strTmpFile = strFile.left(strFile.lastIndexOf(".")) + ".tmp";

        QSettings set(strTmpFile, QSettings::IniFormat);
        set.setIniCodec(QTextCodec::codecForName("UTF-8"));

        //增加无用的节点作为第一个节点,避免读取utf8格式的文件时utf8应bom问题导致第一个节点不能读取
        WriteUTF8(set);

        //保存数据
        iret = WriteData(set);

        //强制保存
        set.sync();

        //加密临时文件到保存文件
        int iEncrypt = -1;
        iEncrypt = CSpyCrypt::EncrptyIniFile(strTmpFile, strFile);
        //删除临时文件
        bool bRemove = false;
        bRemove = QFile::remove(strTmpFile);
    }
    //不需要加密
    else
    {
        QSettings set(strFile, QSettings::IniFormat);
        set.setIniCodec(QTextCodec::codecForName("UTF-8"));
        //增加无用的节点作为第一个节点,避免读取utf8格式的文件时utf8应bom问题导致第一个节点不能读取
        WriteUTF8(set);
        //保存数据
        iret = WriteData(set);
    }

    return iret;
}

int CIFAbstract::WriteUTF8(QSettings& set)
{
    set.beginGroup("UTF8");
    set.setValue("donot_delete","1");
    set.endGroup();

    return 1;
}

int CIFAbstract::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/static_com.ini";
    }

    return 1;
}

int CIFAbstract::ReadData(QSettings& set)
{
    return 1;
}

int CIFAbstract::WriteData(QSettings& set)
{
    return 1;
}

void CIFAbstract::Clear()
{

}

bool CIFAbstract::IsEncryptFile(const QString& strFile)
{
    QFile file(strFile);
    if (!file.open(QIODevice::ReadOnly))
    {
        file.close();
        return false;
    }

    QByteArray ba;
    ba = file.readAll();
    if (ba.indexOf("[") >= 0)
    {
        file.close();
        return false;
    }
    else
    {
        file.close();
        return true;
    }
}

int CIFAbstract::ExistFile(const QString& strFile)
{
    QString strlog = "";
    //判断配置文件是否存在
    if(!QFile::exists(strFile))
    {
        //strlog = QString("CXFCom::Read failed errorno:-1000. cfg file is not exist[%1]").arg(strFile);
        strlog = QString("配置文件[%1]不存在").arg(strFile);
        trcError(strlog);
        return -1000;
    }

    return 1;
}
