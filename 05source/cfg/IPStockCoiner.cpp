#include "IPStockCoiner.h"

CIPStockCoiner::CIPStockCoiner(QObject *parent) :
    QObject(parent)
  ,m_i32Face(0)
  ,m_i32CurNum(0)
{
}

CIPStockCoiner::~CIPStockCoiner()
{

}

//拷贝构造函数
CIPStockCoiner::CIPStockCoiner(const CIPStockCoiner& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32Face = src.m_i32Face;
    m_i32CurNum = src.m_i32CurNum;
}

//拷贝赋值函数
CIPStockCoiner& CIPStockCoiner::operator=(const CIPStockCoiner& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32Face = src.m_i32Face;
    m_i32CurNum = src.m_i32CurNum;

    return *this;
}

qint32 CIPStockCoiner::GetFace() const
{
    return m_i32Face;
}

void CIPStockCoiner::SetFace(qint32 i32Face)
{
    m_i32Face = i32Face;
}

qint32 CIPStockCoiner::GetCurNum() const
{
    return m_i32CurNum;
}

void CIPStockCoiner::SetCurNum(qint32 i32CurNum)
{
    m_i32CurNum = i32CurNum;
}

void CIPStockCoiner::Clear()
{
    m_i32Face = 0;
    m_i32CurNum = 0;
}
