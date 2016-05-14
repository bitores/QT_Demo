#include "XPCoinerStock.h"

CXPCoinerStock::CXPCoinerStock(QObject *parent) :
    QObject(parent)
  ,m_i32Face(0)
  ,m_i32CurNum(0)
{
}

CXPCoinerStock::~CXPCoinerStock()
{

}

//拷贝构造函数
CXPCoinerStock::CXPCoinerStock(const CXPCoinerStock& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32Face = src.m_i32Face;
    m_i32CurNum = src.m_i32CurNum;
}

//拷贝赋值函数
CXPCoinerStock& CXPCoinerStock::operator=(const CXPCoinerStock& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32Face = src.m_i32Face;
    m_i32CurNum = src.m_i32CurNum;

    return *this;
}

qint32 CXPCoinerStock::GetFace()
{
    return m_i32Face;
}

void CXPCoinerStock::SetFace(qint32 i32Face)
{
    m_i32Face = i32Face;
}

qint32 CXPCoinerStock::GetCurNum()
{
    return m_i32CurNum;
}

void CXPCoinerStock::SetCurNum(qint32 i32CurNum)
{
   m_i32CurNum = i32CurNum;
}
