#include "IPStaticLotInfo.h"

CIPStaticLotInfo::CIPStaticLotInfo(QObject *parent) :
    QObject(parent)
  ,m_i32AllNum(0)
  ,m_i32MaxFace(0)
  ,m_i32MinFace(0)
{

}

CIPStaticLotInfo::~CIPStaticLotInfo()
{

}

//拷贝构造函数
CIPStaticLotInfo::CIPStaticLotInfo(const CIPStaticLotInfo& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32AllNum = src.m_i32AllNum;
    m_i32MaxFace = src.m_i32MaxFace;
    m_i32MinFace = src.m_i32MinFace;
}

//拷贝赋值函数
CIPStaticLotInfo& CIPStaticLotInfo::operator=(const CIPStaticLotInfo& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32AllNum = src.m_i32AllNum;
    m_i32MaxFace = src.m_i32MaxFace;
    m_i32MinFace = src.m_i32MinFace;

    return *this;
}

qint32 CIPStaticLotInfo::GetAllNum() const
{
    return m_i32AllNum;
}

void CIPStaticLotInfo::SetAllNum(qint32 i32AllNum)
{
    m_i32AllNum = i32AllNum;
}

qint32 CIPStaticLotInfo::GetMaxFace() const
{
    return m_i32MaxFace;
}

void CIPStaticLotInfo::SetMaxFace(qint32 i32MaxFace)
{
    m_i32MaxFace = i32MaxFace;
}

qint32 CIPStaticLotInfo::GetMinFace() const
{
    return m_i32MinFace;
}

void CIPStaticLotInfo::SetMinFace(qint32 i32MinFace)
{
    m_i32MinFace = i32MinFace;
}

void CIPStaticLotInfo::Clear()
{
    m_i32AllNum = 0;
    m_i32MaxFace = 0;
    m_i32MinFace = 0;
}
