#include "XFAbstract.h"

#include <QtCore/qcoreapplication.h>
#include <QtCore/qdir.h>
#include "trace.h"

CXFAbstract::CXFAbstract(QObject *parent) :
    QObject(parent)
{
}

//virtual
CXFAbstract::~CXFAbstract()
{

}

int CXFAbstract::Read(QString strFile /*= ""*/)
{
    int iret = -1;
    if (1 != (iret = CheckFile(strFile)))
    {
        return iret;
    }

    if (1 != (iret = ExistFile(strFile)))
    {
        return iret;
    }

    QFile file(strFile);
    if (1 != (iret = OpenFile(file, strFile)))
    {
        return iret;
    }

    QDomDocument qdoc;
    if (1 != (iret = SetContent(file, qdoc, strFile)))
    {
        return iret;
    }

    qdoc.documentElement();

    //解析xml文件
    if (1 != (iret = ParseXml(qdoc, strFile)))
    {
        return iret;
    }

    return 1;
}


int CXFAbstract::Write(QString strFile, bool bCoverIfExist /*= true*/)
{
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
            strlog = QString("CXFAbstract::Write failed errorno:-2000. cfg file is exist[%1]").arg(strFile);
            trcError(strlog);
            return -2000;
        }
    }

    //获取路径
    QString strPath = "";
    int iindex = -1;
    iindex = strFile.lastIndexOf(QDir::separator());
    if (-1 == iindex)
    {
        strlog = QString("CXFAbstract::Write failed errorno:-2001. cfg file path is error[%1]").arg(strFile);
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
        strlog = QString("CXFAbstract::Write failed errorno:-2002. create path failed[%1]").arg(strPath);
        trcError(strlog);
        return -2002;
    }

    //打开文件
    QFile file(strFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        strlog = QString("CXFAbstract::Write failed errorno:-2003. open file failed[%1]").arg(strFile);
        trcError(strlog);
        return -2003;
    }

    QDomDocument qdoc;
    QString strErrorMsg = "";
    int iErrorLine = 0;
    int iErrorColumn = 0;
    if (!qdoc.setContent(&file,&strErrorMsg, &iErrorLine, &iErrorColumn))
    {
        file.close();
        strlog = QString("CXFAbstract::Write failed errorno:-2004. setContent failed[%1]"
                         ",错误行号[%2],错误列号[%3],错误原因[%4]")
                .arg(strFile).arg(strErrorMsg).arg(iErrorLine).arg(iErrorColumn);
        trcError(strlog);
        return -2004;
    }
    file.close();

    if (1 != SaveXml(file))
    {
        file.close();
        strlog = QString("CXFAbstract::Write failed errorno:-2005. 保存xml文件失败[%1]").arg(strFile);
        trcError(strlog);
        return -2005;
    }

//    QTextStream out(&file);
//    out.setCodec("UTF-8");
//    qdoc.save(out,4);
//    file.close();

    return 1;
}



int CXFAbstract::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/com.xml";
    }

    return 1;
}

int CXFAbstract::ExistFile(const QString& strFile)
{
    QString strlog = "";
    //判断配置文件是否存在
    if(!QFile::exists(strFile))
    {
        strlog = QString("CXFCom::Read failed errorno:-1000. cfg file is not exist[%1]").arg(strFile);
        trcError(strlog);
        return -1000;
    }

    return 1;
}

int CXFAbstract::OpenFile(QFile& file, const QString& strFile)
{
    QString strlog = "";
    //打开配置文件
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        strlog = QString("CXFCom::Read errorno:-1001. cfg file open failed[%1]").arg(strFile);
        trcError(strlog);
        return -1001;
    }

    return 1;
}

int CXFAbstract::SetContent(QFile& file, QDomDocument& qdoc, const QString& strFile)
{
    QString strlog = "";
    //验证xml格式
    if(!qdoc.setContent(&file))
    {
        file.close();
        strlog = QString("CXFCom::Read errorno:-1002. cfg file format failed[%1]").arg(strFile);
        trcError(strlog);
        return -1002;
    }
    file.close();

    return 1;
}

int CXFAbstract::ParseXml(const QDomDocument& qdoc, const QString& strFile)
{
    int iret = -1;
    //获得根节点fortuna
    QDomElement deRoot;
    if (1 != (iret = ParseRoot(qdoc, deRoot, strFile)))
    {
        return iret;
    }

    QDomElement deParent, deThis;
    deParent = deRoot;
    if (1 != (iret = ParseNode(deParent, deThis, "notein", strFile)))
    {
        return iret;
    }

    return 1;
}

int CXFAbstract::ParseRoot(const QDomDocument& qdoc, QDomElement& deRoot, const QString& strFile)
{
    QString strlog = "";
    deRoot = qdoc.elementsByTagName("fortuna").at(0).toElement();
    if(deRoot.isNull())
    {
        strlog = QString("CXFCom::Read errorno:-1003. cfg file not exist node of fortuna[%1]").arg(strFile);
        trcError(strlog);
        return -1003;
    }

    return 1;
}

int CXFAbstract::ParseNode(const QDomElement& deParent, QDomElement& deThis
                           , const QString& strNodeName, const QString& strFile)
{
    QString strlog = "";
    //获得子节点notein
    deThis = deParent.elementsByTagName(strNodeName).at(0).toElement();
    if(deThis.isNull())
    {
        strlog = QString("CXFCom::Read errorno:-1003. cfg file not exist node of [%1][%2]")
                .arg(strNodeName).arg(strFile);
        trcError(strlog);
        return -1003;
    }
//    SetXFCom(m_notein, deNotein);

    return 1;
}

int CXFAbstract::SaveXml(const QFile& file)
{
    return 1;
}
