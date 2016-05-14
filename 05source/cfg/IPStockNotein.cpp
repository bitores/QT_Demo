#include "IPStockNotein.h"

CIPStockNotein::CIPStockNotein(QObject *parent) :
    QObject(parent)
  ,m_i32FaceNum(0)
  ,m_i32AllNum(0)
  ,m_i32AllSum(0)
{
}

CIPStockNotein::~CIPStockNotein()
{

}

//拷贝构造函数
CIPStockNotein::CIPStockNotein(const CIPStockNotein& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32FaceNum = src.m_i32FaceNum;
    m_i32AllNum = src.m_i32AllNum;
    m_i32AllSum = src.m_i32AllSum;
}

//拷贝赋值函数
CIPStockNotein& CIPStockNotein::operator=(const CIPStockNotein& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32FaceNum = src.m_i32FaceNum;
    m_i32AllNum = src.m_i32AllNum;
    m_i32AllSum = src.m_i32AllSum;

    return *this;
}

qint32 CIPStockNotein::GetFaceNum() const
{
    return m_i32FaceNum;
}

void CIPStockNotein::SetFaceNum(qint32 i32FaceNum)
{
    m_i32FaceNum = i32FaceNum;
}

qint32 CIPStockNotein::GetAllNum() const
{
    return m_i32AllNum;
}

void CIPStockNotein::SetAllNum(qint32 i32AllNum)
{
    m_i32AllNum = i32AllNum;
}

qint32 CIPStockNotein::GetAllSum() const
{
    return m_i32AllSum;
}

void CIPStockNotein::SetAllSum(qint32 i32AllSum)
{
    m_i32AllSum = i32AllSum;
}

void CIPStockNotein::Clear()
{
    m_i32FaceNum = 0;
    m_i32AllNum = 0;
    m_i32AllSum = 0;
}
