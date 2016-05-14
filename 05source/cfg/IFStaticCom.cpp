#include "IFStaticCom.h"

#include <QtCore/qcoreapplication.h>

CIFStaticCom::CIFStaticCom(QObject *parent) :
    CIFBase(parent)
  ,m_i32BoxNum(0)
{
}

CIFStaticCom::~CIFStaticCom()
{

}

//拷贝构造函数
CIFStaticCom::CIFStaticCom(const CIFStaticCom& src)
{
    if (this == &src)
    {
        return;
    }

    m_Notein = src.m_Notein;
    m_Noteout = src.m_Noteout;
    m_Coinin = src.m_Coinin;
    m_Coinout = src.m_Coinout;
    m_Stamping = src.m_Stamping;
    m_Scanner = src.m_Scanner;
    m_Ups = src.m_Ups;
    m_i32BoxNum = src.m_i32BoxNum;
    m_lstBoxList = src.m_lstBoxList;

}

//拷贝赋值函数
CIFStaticCom& CIFStaticCom::operator=(const CIFStaticCom& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_Notein = src.m_Notein;
    m_Noteout = src.m_Noteout;
    m_Coinin = src.m_Coinin;
    m_Coinout = src.m_Coinout;
    m_Stamping = src.m_Stamping;
    m_Scanner = src.m_Scanner;
    m_Ups = src.m_Ups;
    m_i32BoxNum = src.m_i32BoxNum;
    m_lstBoxList = src.m_lstBoxList;

    return *this;
}

CIPStaticCom CIFStaticCom::GetNotein()
{
    return m_Notein;
}

void CIFStaticCom::SetNotein(const CIPStaticCom& notein)
{
    m_Notein = notein;
}

CIPStaticCom CIFStaticCom::GetNoteout()
{
    return m_Noteout;
}

void CIFStaticCom::SetNoteout(const CIPStaticCom& noteout)
{
    m_Noteout = noteout;
}

CIPStaticCom CIFStaticCom::GetCoinin()
{
    return m_Coinin;
}

void CIFStaticCom::SetCoinin(const CIPStaticCom& coinin)
{
    m_Coinin = coinin;
}

CIPStaticCom CIFStaticCom::GetCoinout()
{
    return m_Coinout;
}

void CIFStaticCom::SetCoinout(const CIPStaticCom& coinout)
{
    m_Coinout = coinout;
}

CIPStaticCom CIFStaticCom::GetStamping()
{
    return m_Stamping;
}

void CIFStaticCom::SetStamping(const CIPStaticCom& stamping)
{
    m_Stamping = stamping;
}

CIPStaticCom CIFStaticCom::GetScanner()
{
    return m_Scanner;
}

void CIFStaticCom::SetScanner(const CIPStaticCom& scanner)
{
    m_Scanner = scanner;
}

CIPStaticCom CIFStaticCom::GetUps()
{
    return m_Ups;
}

void CIFStaticCom::SetUps(const CIPStaticCom& ups)
{
    m_Ups = ups;
}

qint32 CIFStaticCom::GetBoxNum() const
{
    return m_i32BoxNum;
}

void CIFStaticCom::SetBoxNum(qint32 i32BoxNum)
{
    m_i32BoxNum = i32BoxNum;
}

QList<CIPStaticCom> CIFStaticCom::GetBoxList()
{
    return m_lstBoxList;
}

void CIFStaticCom::SetBoxList(const QList<CIPStaticCom>& lstBoxList)
{
    m_lstBoxList = lstBoxList;
}

/*
*@brief             获取票箱串口信息
*@param     in|out  dest            要获取的票箱串口信息
*@param     in      i32BoxIndex     票箱序号
*@retval            true            获取成功
*@retval            false           获取失败
*/
bool CIFStaticCom::GetBox(CIPStaticCom& dest, qint32 i32BoxIndex) const
{
    if (i32BoxIndex < 0 || i32BoxIndex >= m_lstBoxList.count())
    {
        return false;
    }

    dest = m_lstBoxList.at(i32BoxIndex);

    return true;
}

int CIFStaticCom::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/static_com.ini";
    }

    return 1;
}

int CIFStaticCom::ReadData(QSettings& set)
{
    ReadCom(set, "NOTEIN", m_Notein);
    ReadCom(set, "NOTEOUT", m_Noteout);
    ReadCom(set, "COININ", m_Coinin);
    ReadCom(set, "COINOUT", m_Coinout);
    ReadCom(set, "STAMPING", m_Stamping);
    ReadCom(set, "SCANNER", m_Scanner);
    ReadCom(set, "UPS", m_Ups);

    set.beginGroup("LOTBOX");
    m_i32BoxNum = set.value("box_num", "0").toInt();
    set.endGroup();

    for(int i=0;i<m_i32BoxNum;i++)
    {
        ReadBox(set, i);
    }

    return 1;
}

int CIFStaticCom::WriteData(QSettings& set)
{
    WriteCom(set, "NOTEIN", m_Notein);
    WriteCom(set, "NOTEOUT", m_Noteout);
    WriteCom(set, "COININ", m_Coinin);
    WriteCom(set, "COINOUT", m_Coinout);
    WriteCom(set, "STAMPING", m_Stamping);
    WriteCom(set, "SCANNER", m_Scanner);
    WriteCom(set, "UPS", m_Ups);

    set.beginGroup("LOTBOX");
    set.setValue("box_num", m_i32BoxNum);
    set.endGroup();

    for(int i=0;i<m_i32BoxNum;i++)
    {
        WriteBox(set, i);
    }

    return 1;
}



void CIFStaticCom::Clear()
{
    m_Notein.Clear();
    m_Noteout.Clear();
    m_Coinin.Clear();
    m_Coinout.Clear();
    m_Stamping.Clear();
    m_Scanner.Clear();
    m_Ups.Clear();
    m_i32BoxNum = 0;
    m_lstBoxList.clear();
}

int CIFStaticCom::ReadCom(QSettings& set, const QString& strGroup, CIPStaticCom& com)
{
    set.beginGroup(strGroup);
    com.SetName(set.value("com_name").toString());
    com.SetRate(set.value("baud_rate").toString());
    com.SetParity(set.value("parity").toString());
    com.SetDataBit(set.value("data_bits").toString());
    com.SetStopBit(set.value("stop_bits").toString());
    set.endGroup();

    return 1;
}

int CIFStaticCom::WriteCom(QSettings& set, const QString& strGroup, CIPStaticCom& com)
{
    set.beginGroup(strGroup);
    set.setValue("com_name", com.GetName());
    set.setValue("baud_rate", com.GetRateValue());
    set.setValue("parity", com.GetParityValue());
    set.setValue("data_bits", com.GetDataBitValue());
    set.setValue("stop_bits", com.GetStopBitValue());
    set.endGroup();

    return 1;
}

int CIFStaticCom::ReadBox(QSettings& set, qint32 i32Index)
{
    CIPStaticCom box;
    set.beginGroup(QString("LOTBOX_%1").arg(QString::number(i32Index).rightJustified(3, '0',true)));
    box.SetName(set.value("com_name").toString());
    box.SetRate(set.value("baud_rate").toString());
    box.SetParity(set.value("parity").toString());
    box.SetDataBit(set.value("data_bits").toString());
    box.SetStopBit(set.value("stop_bits").toString());
    set.endGroup();

    m_lstBoxList.append(box);

    return 1;
}

int CIFStaticCom::WriteBox(QSettings& set, qint32 i32Index)
{
    set.beginGroup(QString("LOTBOX_%1").arg(QString::number(i32Index).rightJustified(3, '0',true)));
    set.setValue("com_name", m_lstBoxList.at(i32Index).GetName());
    set.setValue("baud_rate", m_lstBoxList.at(i32Index).GetRateValue());
    set.setValue("parity", m_lstBoxList.at(i32Index).GetParityValue());
    set.setValue("data_bits", m_lstBoxList.at(i32Index).GetDataBitValue());
    set.setValue("stop_bits", m_lstBoxList.at(i32Index).GetStopBitValue());
    set.endGroup();

    return 1;
}
