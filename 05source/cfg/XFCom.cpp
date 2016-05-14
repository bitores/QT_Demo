#include "XFCom.h"

#include <QtCore/qcoreapplication.h>
#include <QtCore/qfile.h>
#include <QtCore/qxmlstream.h>

#include "trace.h"

CXFCom::CXFCom(QObject *parent) :
    CXFBase(parent)
{
}


CXFCom::~CXFCom()
{

}

//拷贝构造函数
CXFCom::CXFCom(const CXFCom& src)
{
    if (this == &src)
    {
        return;
    }

    m_notein = src.m_notein;        //纸币进币器
    m_noteout = src.m_noteout;      //纸币出币器
    m_coinin = src.m_coinin;        //硬币进币器
    m_coinout = src.m_coinout;      //硬币出币器
    m_stamping = src.m_stamping;    //兑奖模块

    m_scanner = src.m_scanner;      //扫描仪
    m_ups = src.m_ups;              //ups

    m_lotbox1 = src.m_lotbox1;      //出票模块1
    m_lotbox2 = src.m_lotbox2;      //出票模块2
    m_lotbox3 = src.m_lotbox3;      //出票模块3
    m_lotbox4 = src.m_lotbox4;      //出票模块4
    m_lotbox5 = src.m_lotbox5;      //出票模块5
    m_lotbox6 = src.m_lotbox6;      //出票模块6
    m_lotbox7 = src.m_lotbox7;      //出票模块7
    m_lotbox8 = src.m_lotbox8;      //出票模块8
}

//拷贝赋值函数
CXFCom& CXFCom::operator=(const CXFCom& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_notein = src.m_notein;        //纸币进币器
    m_noteout = src.m_noteout;      //纸币出币器
    m_coinin = src.m_coinin;        //硬币进币器
    m_coinout = src.m_coinout;      //硬币出币器
    m_stamping = src.m_stamping;    //兑奖模块

    m_scanner = src.m_scanner;      //扫描仪
    m_ups = src.m_ups;              //ups

    m_lotbox1 = src.m_lotbox1;      //出票模块1
    m_lotbox2 = src.m_lotbox2;      //出票模块2
    m_lotbox3 = src.m_lotbox3;      //出票模块3
    m_lotbox4 = src.m_lotbox4;      //出票模块4
    m_lotbox5 = src.m_lotbox5;      //出票模块5
    m_lotbox6 = src.m_lotbox6;      //出票模块6
    m_lotbox7 = src.m_lotbox7;      //出票模块7
    m_lotbox8 = src.m_lotbox8;      //出票模块8

    return *this;
}

int CXFCom::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/com.xml";
    }

    return 1;
}

int CXFCom::ParseXml(const QDomDocument& qdoc, const QString& strFile)
{
    int iret = -1;
    //获得根节点fortuna
    QDomElement deRoot;
    if (1 != (iret = ParseRoot(qdoc, deRoot, strFile)))
    {
        return iret;
    }

    QDomElement deNotein, deNoteout, deCoinin, deCoinout, deStamping, deScanner, deUps;
    //解析子节点notein
    if (1 != (iret = ParseNode(deRoot, deNotein, "notein", strFile)))
    {
        return iret;
    }
    //解析子节点noteout
    if (1 != (iret = ParseNode(deRoot, deNoteout, "noteout", strFile)))
    {
        return iret;
    }
    //解析子节点coinin
    if (1 != (iret = ParseNode(deRoot, deCoinin, "coinin", strFile)))
    {
        return iret;
    }
    //解析子节点coinout
    if (1 != (iret = ParseNode(deRoot, deCoinout, "coinout", strFile)))
    {
        return iret;
    }
    //解析子节点stamping
    if (1 != (iret = ParseNode(deRoot, deStamping, "stamping", strFile)))
    {
        return iret;
    }
    //解析子节点scanner
    if (1 != (iret = ParseNode(deRoot, deScanner, "scanner", strFile)))
    {
        return iret;
    }
    //解析子节点ups
    if (1 != (iret = ParseNode(deRoot, deUps, "ups", strFile)))
    {
        return iret;
    }
    QDomElement deLotbox1,deLotbox2,deLotbox3,deLotbox4,deLotbox5,deLotbox6,deLotbox7,deLotbox8;
    //解析子节点lotbox1
    if (1 != (iret = ParseNode(deRoot, deLotbox1, "lotbox1", strFile)))
    {
        return iret;
    }
    //解析子节点lotbox2
    if (1 != (iret = ParseNode(deRoot, deLotbox2, "lotbox2", strFile)))
    {
        return iret;
    }
    //解析子节点lotbox3
    if (1 != (iret = ParseNode(deRoot, deLotbox3, "lotbox3", strFile)))
    {
        return iret;
    }
    //解析子节点lotbox4
    if (1 != (iret = ParseNode(deRoot, deLotbox4, "lotbox4", strFile)))
    {
        return iret;
    }
    //解析子节点lotbox5
    if (1 != (iret = ParseNode(deRoot, deLotbox5, "lotbox5", strFile)))
    {
        return iret;
    }
    //解析子节点lotbox6
    if (1 != (iret = ParseNode(deRoot, deLotbox6, "lotbox6", strFile)))
    {
        return iret;
    }
    //解析子节点lotbox7
    if (1 != (iret = ParseNode(deRoot, deLotbox7, "lotbox7", strFile)))
    {
        return iret;
    }
    //解析子节点lotbox8
    if (1 != (iret = ParseNode(deRoot, deLotbox8, "lotbox8", strFile)))
    {
        return iret;
    }

    return 1;
}

int CXFCom::ParseNode(const QDomElement& deParent, QDomElement& deThis, const QString& strNodeName, const QString& strFile)
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

    if ("notein" == strNodeName)
    {
        SetXFCom(m_notein, deThis);
    }
    else if ("noteout" == strNodeName)
    {
        SetXFCom(m_noteout, deThis);
    }
    else if ("coinin" == strNodeName)
    {
        SetXFCom(m_coinin, deThis);
    }
    else if ("coinout" == strNodeName)
    {
        SetXFCom(m_coinout, deThis);
    }
    else if ("stamping" == strNodeName)
    {
        SetXFCom(m_stamping, deThis);
    }
    else if ("scanner" == strNodeName)
    {
        SetXFCom(m_scanner, deThis);
    }
    else if ("ups" == strNodeName)
    {
        SetXFCom(m_ups, deThis);
    }
    else if ("lotbox1" == strNodeName)
    {
        SetXFCom(m_lotbox1, deThis);
    }
    else if ("lotbox2" == strNodeName)
    {
        SetXFCom(m_lotbox2, deThis);
    }
    else if ("lotbox3" == strNodeName)
    {
        SetXFCom(m_lotbox3, deThis);
    }
    else if ("lotbox4" == strNodeName)
    {
        SetXFCom(m_lotbox4, deThis);
    }
    else if ("lotbox5" == strNodeName)
    {
        SetXFCom(m_lotbox5, deThis);
    }
    else if ("lotbox6" == strNodeName)
    {
        SetXFCom(m_lotbox6, deThis);
    }
    else if ("lotbox7" == strNodeName)
    {
        SetXFCom(m_lotbox7, deThis);
    }
    else if ("lotbox8" == strNodeName)
    {
        SetXFCom(m_lotbox8, deThis);
    }

    return 1;
}

int CXFCom::SaveXml(QFile& file)
{
    QXmlStreamWriter xsw;
    xsw.setDevice(&file);
    xsw.setAutoFormatting(true);
    xsw.writeStartDocument();

    //保存根节点
    xsw.writeStartElement("fortuna");
        //保存子节点notein
        SaveElement(xsw, "notein");
        //保存子节点noteout
        SaveElement(xsw, "noteout");
        //保存子节点coinin
        SaveElement(xsw, "coinin");
        //保存子节点coinout
        SaveElement(xsw, "coinout");
        //保存子节点stamping
        SaveElement(xsw, "stamping");
        //保存子节点scanner
        SaveElement(xsw, "scanner");
        //保存子节点ups
        SaveElement(xsw, "ups");
        //保存子节点lotbox1
        SaveElement(xsw, "lotbox1");
        //保存子节点lotbox2
        SaveElement(xsw, "lotbox2");
        //保存子节点lotbox3
        SaveElement(xsw, "lotbox3");
        //保存子节点lotbox4
        SaveElement(xsw, "lotbox4");
        //保存子节点lotbox5
        SaveElement(xsw, "lotbox5");
        //保存子节点lotbox6
        SaveElement(xsw, "lotbox6");
        //保存子节点lotbox7
        SaveElement(xsw, "lotbox7");
        //保存子节点lotbox8
        SaveElement(xsw, "lotbox8");
    xsw.writeEndElement();

    xsw.writeEndDocument();

    return 1;
}

void CXFCom::SetXFCom(CXPCom& dest, const QDomElement& de)
{
    dest.SetName(de.attribute("com_name"));
    dest.SetRate(de.attribute("baud_rate"));
    dest.SetParity(de.attribute("parity"));
    dest.SetDataBit(de.attribute("data_bits"));
    dest.SetStopBit(de.attribute("stop_bits"));
}

void CXFCom::SaveElement(QXmlStreamWriter& xsw, const QString& strNodeName)
{
    xsw.writeStartElement(strNodeName);
    if ("notein" == strNodeName)
    {
        SaveXFCom(xsw, m_notein);
    }
    else if ("noteout" == strNodeName)
    {
        SaveXFCom(xsw, m_noteout);
    }
    else if ("coinin" == strNodeName)
    {
        SaveXFCom(xsw, m_coinin);
    }
    else if ("coinout" == strNodeName)
    {
        SaveXFCom(xsw, m_coinout);
    }
    else if ("stamping" == strNodeName)
    {
        SaveXFCom(xsw, m_stamping);
    }
    else if ("scanner" == strNodeName)
    {
        SaveXFCom(xsw, m_scanner);
    }
    else if ("ups" == strNodeName)
    {
        SaveXFCom(xsw, m_ups);
    }
    else if ("lotbox1" == strNodeName)
    {
        SaveXFCom(xsw, m_lotbox1);
    }
    else if ("lotbox2" == strNodeName)
    {
        SaveXFCom(xsw, m_lotbox2);
    }
    else if ("lotbox3" == strNodeName)
    {
        SaveXFCom(xsw, m_lotbox3);
    }
    else if ("lotbox4" == strNodeName)
    {
        SaveXFCom(xsw, m_lotbox4);
    }
    else if ("lotbox5" == strNodeName)
    {
        SaveXFCom(xsw, m_lotbox5);
    }
    else if ("lotbox6" == strNodeName)
    {
        SaveXFCom(xsw, m_lotbox6);
    }
    else if ("lotbox7" == strNodeName)
    {
        SaveXFCom(xsw, m_lotbox7);
    }
    else if ("lotbox8" == strNodeName)
    {
        SaveXFCom(xsw, m_lotbox8);
    }
    xsw.writeEndElement();
}

void CXFCom::SaveXFCom(QXmlStreamWriter& xsw, CXPCom& src)
{
    xsw.writeAttribute("com_name", src.GetName());
    xsw.writeAttribute("baud_rate",QString::number((int)src.GetRate()));
    xsw.writeAttribute("parity", src.GetParityValue());
    xsw.writeAttribute("data_bits", src.GetDataBitValue());
    xsw.writeAttribute("stop_bits", src.GetStopBitValue());
}

void CXFCom::SetNotein(const CXPCom& src)
{
    m_notein = src;
}

CXPCom CXFCom::GetNotein()
{
    return m_notein;
}

void CXFCom::SetNoteout(const CXPCom& src)
{
    m_noteout = src;
}

CXPCom CXFCom::GetNoteout()
{
    return m_noteout;
}

void CXFCom::SetCoinin(const CXPCom& src)
{
    m_coinin = src;
}

CXPCom CXFCom::GetCoinin()
{
    return m_coinin;
}

void CXFCom::SetCoinout(const CXPCom& src)
{
    m_coinout = src;
}

CXPCom CXFCom::GetCoinout()
{
    return m_coinout;
}

void CXFCom::SetStamping(const CXPCom& src)
{
    m_stamping = src;
}

CXPCom CXFCom::GetStamping()
{
    return m_stamping;
}

void CXFCom::SetScanner(const CXPCom& src)
{
    m_scanner = src;
}

CXPCom CXFCom::GetScanner()
{
    return m_scanner;
}

void CXFCom::SetUps(const CXPCom& src)
{
    m_ups = src;
}

CXPCom CXFCom::GetUps()
{
    return m_ups;
}

void CXFCom::SetLotbox1(const CXPCom& src)
{
    m_lotbox1 = src;
}

CXPCom CXFCom::GetLotbox1()
{
    return m_lotbox1;
}

void CXFCom::SetLotbox2(const CXPCom& src)
{
    m_lotbox2 = src;
}

CXPCom CXFCom::GetLotbox2()
{
    return m_lotbox2;
}

void CXFCom::SetLotbox3(const CXPCom& src)
{
    m_lotbox3 = src;
}

CXPCom CXFCom::GetLotbox3()
{
    return m_lotbox3;
}

void CXFCom::SetLotbox4(const CXPCom& src)
{
    m_lotbox4 = src;
}

CXPCom CXFCom::GetLotbox4()
{
    return m_lotbox4;
}

void CXFCom::SetLotbox5(const CXPCom& src)
{
    m_lotbox5 = src;
}

CXPCom CXFCom::GetLotbox5()
{
    return m_lotbox5;
}

void CXFCom::SetLotbox6(const CXPCom& src)
{
    m_lotbox6 = src;
}

CXPCom CXFCom::GetLotbox6()
{
    return m_lotbox6;
}

void CXFCom::SetLotbox7(const CXPCom& src)
{
    m_lotbox7 = src;
}

CXPCom CXFCom::GetLotbox7()
{
    return m_lotbox7;
}

void CXFCom::SetLotbox8(const CXPCom& src)
{
    m_lotbox8 = src;
}

CXPCom CXFCom::GetLotbox8()
{
    return m_lotbox8;
}
