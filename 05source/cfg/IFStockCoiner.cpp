#include "IFStockCoiner.h"

#include <QtCore/qcoreapplication.h>

CIFStockCoiner::CIFStockCoiner(QObject *parent) :
    CIFBase(parent)
{
}

CIFStockCoiner::~CIFStockCoiner()
{

}

//拷贝构造函数
CIFStockCoiner::CIFStockCoiner(const CIFStockCoiner& src)
{
    if (this == &src)
    {
        return;
    }

    m_Coiner = src.m_Coiner;
}

//拷贝赋值函数
CIFStockCoiner& CIFStockCoiner::operator=(const CIFStockCoiner& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_Coiner = src.m_Coiner;

    return *this;
}

CIPStockCoiner CIFStockCoiner::GetCoiner()
{
    return m_Coiner;
}

void CIFStockCoiner::SetCoiner(const CIPStockCoiner& coiner)
{
    m_Coiner = coiner;
}

int CIFStockCoiner::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/stock_coiner.ini";
    }

    return 1;
}

int CIFStockCoiner::ReadData(QSettings& set)
{
    set.beginGroup("COINER");
    m_Coiner.SetFace(set.value("face").toInt());
    m_Coiner.SetCurNum( set.value("cur_num").toInt());
    set.endGroup();

    return 1;
}

int CIFStockCoiner::WriteData(QSettings& set)
{
    set.beginGroup("COINER");
    set.setValue("face", m_Coiner.GetFace());
    set.setValue("cur_num", m_Coiner.GetCurNum());
    set.endGroup();

    return 1;
}

void CIFStockCoiner::Clear()
{
    m_Coiner.Clear();
}
