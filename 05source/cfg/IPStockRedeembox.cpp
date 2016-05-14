#include "IPStockRedeembox.h"

CIPStockRedeembox::CIPStockRedeembox(QObject *parent) :
    QObject(parent)
  ,m_i32CurNum(0)
{
}

CIPStockRedeembox::~CIPStockRedeembox()
{

}

//拷贝构造函数
CIPStockRedeembox::CIPStockRedeembox(const CIPStockRedeembox& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32CurNum = src.m_i32CurNum;
}

//拷贝赋值函数
CIPStockRedeembox& CIPStockRedeembox::operator=(const CIPStockRedeembox& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32CurNum = src.m_i32CurNum;

    return *this;
}

qint32 CIPStockRedeembox::GetCurNum() const
{
    return m_i32CurNum;
}

void CIPStockRedeembox::SetCurNum(qint32 i32CurNum)
{
    m_i32CurNum = i32CurNum;
}

void CIPStockRedeembox::Clear()
{
    m_i32CurNum = 0;
}
