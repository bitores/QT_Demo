#include "IPStockLotbox.h"

CIPStockLotbox::CIPStockLotbox(QObject *parent) :
    QObject(parent)
  ,m_i32BoxNum(0)
  ,m_i32AllNum(0)
  ,m_i32AllSum(0)
  ,m_i32MinFace(100)
  ,m_i32MaxFace(0)
{
}

CIPStockLotbox::~CIPStockLotbox()
{

}

//拷贝构造函数
CIPStockLotbox::CIPStockLotbox(const CIPStockLotbox& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32BoxNum = src.m_i32BoxNum;
    m_i32AllNum = src.m_i32AllNum;
    m_i32AllSum = src.m_i32AllSum;
    m_i32MinFace = src.m_i32MinFace;
    m_i32MaxFace = src.m_i32MaxFace;
}

//拷贝赋值函数
CIPStockLotbox& CIPStockLotbox::operator=(const CIPStockLotbox& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32BoxNum = src.m_i32BoxNum;
    m_i32AllNum = src.m_i32AllNum;
    m_i32AllSum = src.m_i32AllSum;
    m_i32MinFace = src.m_i32MinFace;
    m_i32MaxFace = src.m_i32MaxFace;

    return *this;
}

qint32 CIPStockLotbox::GetBoxNum() const
{
    return m_i32BoxNum;
}

void CIPStockLotbox::SetBoxNum(qint32 i32BoxNum)
{
    m_i32BoxNum = i32BoxNum;
}

qint32 CIPStockLotbox::GetAllNum() const
{
    return m_i32AllNum;
}

void CIPStockLotbox::SetAllNum(qint32 i32AllNum)
{
    m_i32AllNum = i32AllNum;
}

qint32 CIPStockLotbox::GetAllSum() const
{
    return m_i32AllSum;
}

void CIPStockLotbox::SetAllSum(qint32 i32AllNum)
{
    m_i32AllSum = i32AllNum;
}

qint32  CIPStockLotbox::GetMinFace() const
{
    return m_i32MinFace;
}

void CIPStockLotbox::SetMinFace(qint32 i32MinFace)
{
    m_i32MinFace = i32MinFace;
}

qint32 CIPStockLotbox::GetMaxFace() const
{
    return m_i32MaxFace;
}

void CIPStockLotbox::SetMaxFace(qint32 i32MaxFace)
{
    m_i32MaxFace = i32MaxFace;
}

void CIPStockLotbox::Clear()
{
    m_i32BoxNum = 0;
    m_i32AllNum = 0;
    m_i32AllSum = 0;
    m_i32MinFace = 0;
    m_i32MaxFace = 0;
}
