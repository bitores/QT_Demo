#include "IFStockRedeembox.h"

#include <QtCore/qcoreapplication.h>

CIFStockRedeembox::CIFStockRedeembox(QObject *parent) :
    CIFBase(parent)
{
}

CIFStockRedeembox::~CIFStockRedeembox()
{

}

//拷贝构造函数
CIFStockRedeembox::CIFStockRedeembox(const CIFStockRedeembox& src)
{
    if (this == &src)
    {
        return;
    }

    m_Redeembox = src.m_Redeembox;
}

//拷贝赋值函数
CIFStockRedeembox& CIFStockRedeembox::operator=(const CIFStockRedeembox& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_Redeembox = src.m_Redeembox;

    return *this;
}

CIPStockRedeembox CIFStockRedeembox::GetRedeembox()
{
    return m_Redeembox;
}

void CIFStockRedeembox::SetRedeembox(const CIPStockRedeembox& coiner)
{
    m_Redeembox = coiner;
}

int CIFStockRedeembox::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/stock_redeembox.ini";
    }

    return 1;
}

int CIFStockRedeembox::ReadData(QSettings& set)
{
    set.beginGroup("REDEEMBOX");
    m_Redeembox.SetCurNum( set.value("cur_num").toInt());
    set.endGroup();

    return 1;
}

int CIFStockRedeembox::WriteData(QSettings& set)
{
    set.beginGroup("REDEEMBOX");
    set.setValue("cur_num", m_Redeembox.GetCurNum());
    set.endGroup();

    return 1;
}

void CIFStockRedeembox::Clear()
{
    m_Redeembox.Clear();
}
