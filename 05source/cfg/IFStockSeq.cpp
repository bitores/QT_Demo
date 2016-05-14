#include "IFStockSeq.h"

#include <QtCore/qcoreapplication.h>

CIFStockSeq::CIFStockSeq(QObject *parent) :
    CIFBase(parent)
{
}

CIFStockSeq::~CIFStockSeq()
{

}

//拷贝构造函数
CIFStockSeq::CIFStockSeq(const CIFStockSeq& src)
{
    if (this == &src)
    {
        return;
    }

    m_seq = src.m_seq;
}

//拷贝赋值函数
CIFStockSeq& CIFStockSeq::operator=(const CIFStockSeq& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_seq = src.m_seq;

    return *this;
}

CIPStockSeq CIFStockSeq::GetSeq()
{
    return m_seq;
}

void CIFStockSeq::SetSeq(const CIPStockSeq& seq)
{
    m_seq = seq;
}

int CIFStockSeq::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/stock_seq.ini";
    }

    return 1;
}

int CIFStockSeq::ReadData(QSettings& set)
{
    set.beginGroup("SEQUENCE");
    m_seq.SetMessage(set.value("seq_message").toInt());
    m_seq.SetPackage(set.value("seq_package").toInt());
    m_seq.SetBatch(set.value("seq_batch").toInt());
    set.endGroup();

    return 1;
}

int CIFStockSeq::WriteData(QSettings& set)
{
    set.beginGroup("SEQUENCE");
    set.setValue("seq_message",m_seq.GetMessage());
    set.setValue("seq_package",m_seq.GetPackage());
    set.setValue("seq_batch",m_seq.GetBatch());
    set.endGroup();

    return 1;
}


void CIFStockSeq::Clear()
{
    m_seq.Clear();
}
