#include "IPStockNoteinFace.h"

CIPStockNoteinFace::CIPStockNoteinFace(QObject *parent) :
    QObject(parent)
  ,m_i32Face(0)
  ,m_i32CurNum(0)
{
}

CIPStockNoteinFace::~CIPStockNoteinFace()
{

}

//拷贝构造函数
CIPStockNoteinFace::CIPStockNoteinFace(const CIPStockNoteinFace& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32Face = src.m_i32Face;
    m_i32CurNum = src.m_i32CurNum;
}

//拷贝赋值函数
CIPStockNoteinFace& CIPStockNoteinFace::operator=(const CIPStockNoteinFace& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32Face = src.m_i32Face;
    m_i32CurNum = src.m_i32CurNum;

    return *this;
}

qint32 CIPStockNoteinFace::GetFace() const
{
    return m_i32Face;
}

void CIPStockNoteinFace::SetFace(qint32 i32Face)
{
    m_i32Face = i32Face;
}

qint32 CIPStockNoteinFace::GetCurNum() const
{
    return m_i32CurNum;
}

void CIPStockNoteinFace::SetCurNum(qint32 i32CurNum)
{
    m_i32CurNum = i32CurNum;
}

void CIPStockNoteinFace::Clear()
{
    m_i32Face = 0;
    m_i32CurNum = 0;
}
