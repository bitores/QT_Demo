#include "IPStaticCoiner.h"

CIPStaticCoiner::CIPStaticCoiner(QObject *parent) :
    QObject(parent)
  ,m_i32CurFace(0)
  ,m_i32MaxNum(0)
  ,m_i32MinNum(0)
  ,m_bPerFlag(false)
  ,m_i32MaxInNumOfPer(0)
  ,m_i32MaxOutNumOfPer(0)
{
}

CIPStaticCoiner::~CIPStaticCoiner()
{

}

//拷贝构造函数
CIPStaticCoiner::CIPStaticCoiner(const CIPStaticCoiner& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32CurFace = src.m_i32CurFace;
    m_i32MaxNum = src.m_i32MaxNum;
    m_i32MinNum = src.m_i32MinNum;
    m_bPerFlag = src.m_bPerFlag;
    m_i32MaxInNumOfPer = src.m_i32MaxInNumOfPer;
    m_i32MaxOutNumOfPer = src.m_i32MaxOutNumOfPer;
}

//拷贝赋值函数
CIPStaticCoiner& CIPStaticCoiner::operator=(const CIPStaticCoiner& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32CurFace = src.m_i32CurFace;
    m_i32MaxNum = src.m_i32MaxNum;
    m_i32MinNum = src.m_i32MinNum;
    m_bPerFlag = src.m_bPerFlag;
    m_i32MaxInNumOfPer = src.m_i32MaxInNumOfPer;
    m_i32MaxOutNumOfPer = src.m_i32MaxOutNumOfPer;

    return *this;
}

qint32 CIPStaticCoiner::GetCurFace() const
{
    return m_i32CurFace;
}

void CIPStaticCoiner::SetCurFace(qint32 i32CurFace)
{
    m_i32CurFace = i32CurFace;
}

qint32 CIPStaticCoiner::GetMaxNum() const
{
    return m_i32MaxNum;
}

void CIPStaticCoiner::SetMaxNum(qint32 i32MaxNum)
{
    m_i32MaxNum = i32MaxNum;
}

qint32 CIPStaticCoiner::GetMinNum() const
{
    return m_i32MinNum;
}

void CIPStaticCoiner::SetMinNum(qint32 i32MinNum)
{
    m_i32MinNum = i32MinNum;
}

bool CIPStaticCoiner::GetPerFlag() const
{
    return m_bPerFlag;
}

void CIPStaticCoiner::SetPerFlag(bool bPerFlag)
{
    m_bPerFlag = bPerFlag;
}

qint32 CIPStaticCoiner::GetMaxInNumOfPer() const
{
    return m_i32MaxInNumOfPer;
}

void CIPStaticCoiner::SetMaxInNumOfPer(qint32 i32MaxInNumOfPer)
{
    m_i32MaxInNumOfPer = i32MaxInNumOfPer;
}

qint32 CIPStaticCoiner::GetMaxOutNumOfPer() const
{
    return m_i32MaxOutNumOfPer;
}

void CIPStaticCoiner::SetMaxOutNumOfPer(qint32 i32MaxOutNumOfPer)
{
    m_i32MaxOutNumOfPer = i32MaxOutNumOfPer;
}

void CIPStaticCoiner::Clear()
{
    m_i32CurFace = 0;
    m_i32MaxNum = 0;
    m_i32MinNum = 0;
    m_bPerFlag = false;
    m_i32MaxInNumOfPer = 0;
    m_i32MaxOutNumOfPer = 0;
}
