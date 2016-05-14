#include "XFCoinerStock.h"

#include <QtCore/qcoreapplication.h>
#include <QtCore/qxmlstream.h>
#include "trace.h"

CXFCoinerStock::CXFCoinerStock(QObject *parent) :
    CXFBase(parent)
{
}

CXFCoinerStock::~CXFCoinerStock()
{

}

//拷贝构造函数
CXFCoinerStock::CXFCoinerStock(const CXFCoinerStock& src)
{
    if (this == &src)
    {
        return;
    }

    m_stock = src.m_stock;
}

//拷贝赋值函数
CXFCoinerStock& CXFCoinerStock::operator=(const CXFCoinerStock& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_stock = src.m_stock;

    return *this;
}

CXPCoinerStock CXFCoinerStock::GetStock()
{
    return m_stock;
}

void CXFCoinerStock::SetStock(CXPCoinerStock stock)
{
    m_stock = stock;
}

int CXFCoinerStock::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/coiner_stock.xml";
    }

    return 1;
}

int CXFCoinerStock::ParseXml(const QDomDocument& qdoc, const QString& strFile)
{
    int iret = -1;
    //获得根节点fortuna
    QDomElement deRoot;
    if (1 != (iret = ParseRoot(qdoc, deRoot, strFile)))
    {
        return iret;
    }

    QDomElement deCoiner;
    //解析子节点coiner
    if (1 != (iret = ParseNode(deRoot, deCoiner, "coiner", strFile)))
    {
        return iret;
    }

    return 1;
}

int CXFCoinerStock::ParseNode(const QDomElement& deParent, QDomElement& deThis, const QString& strNodeName, const QString& strFile)
{
    QString strlog = "";
    deThis = deParent.elementsByTagName(strNodeName).at(0).toElement();
    if(deThis.isNull())
    {
        strlog = QString("CXFCoinerStock::Read errorno:-1003. cfg file not exist node of [%1][%2]")
                .arg(strNodeName).arg(strFile);
        trcError(strlog);
        return -1003;
    }

    m_stock.SetFace(deThis.attribute("face").toInt());
    m_stock.SetCurNum(deThis.attribute("cur_num").toInt());

    return 1;
}

int CXFCoinerStock::SaveXml(QFile& file)
{
    QXmlStreamWriter xsw;
    xsw.setDevice(&file);
    xsw.setAutoFormatting(true);

    xsw.writeStartDocument();

        //保存根节点
        xsw.writeStartElement("fortuna");
            //保存子节点coiner
            xsw.writeStartElement("coiner");
            xsw.writeAttribute("face", QString::number(m_stock.GetFace()));
            xsw.writeAttribute("cur_num", QString::number(m_stock.GetCurNum()));
            xsw.writeEndElement();
        xsw.writeEndElement();

        xsw.writeEndDocument();

    return 1;
}
