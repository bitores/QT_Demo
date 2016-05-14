#include "IPStockLotboxBox.h"

CIPStockLotboxBox::CIPStockLotboxBox(QObject *parent) :
    QObject(parent)
  ,m_i32CurNum(0)
{
}

CIPStockLotboxBox::~CIPStockLotboxBox()
{

}

//拷贝构造函数
CIPStockLotboxBox::CIPStockLotboxBox(const CIPStockLotboxBox& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32CurNum = src.m_i32CurNum;
}

//拷贝赋值函数
CIPStockLotboxBox& CIPStockLotboxBox::operator=(const CIPStockLotboxBox& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32CurNum = src.m_i32CurNum;

    return *this;
}

qint32 CIPStockLotboxBox::GetCurNum() const
{
    return m_i32CurNum;
}

void CIPStockLotboxBox::SetCurNum(qint32 i32CurNum)
{
    m_i32CurNum = i32CurNum;
}

void CIPStockLotboxBox::Clear()
{
    m_i32CurNum = 0;
}
