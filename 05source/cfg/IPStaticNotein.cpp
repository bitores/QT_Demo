#include "IPStaticNotein.h"

CIPStaticNotein::CIPStaticNotein(QObject *parent) :
    QObject(parent)
  ,m_i32MaxNum(0)
  ,m_i32MinNum(0)
  ,m_i32MaxSum(0)
  ,m_i32MinSum(0)
  ,m_bPerFlag(false)
  ,m_i32MaxNumOfPer(0)
  ,m_i32MaxSumOfPer(0)
{
}

CIPStaticNotein::~CIPStaticNotein()
{

}

//拷贝构造函数
CIPStaticNotein::CIPStaticNotein(const CIPStaticNotein& src)
{
    if (this == &src)
    {
        return;
    }

    m_slFaceList = src.m_slFaceList;
    m_i32MaxNum = src.m_i32MaxNum;
    m_i32MinNum = src.m_i32MinNum;
    m_i32MaxSum = src.m_i32MaxSum;
    m_i32MinSum = src.m_i32MinSum;
    m_bPerFlag = src.m_bPerFlag;
    m_i32MaxNumOfPer = src.m_i32MaxNumOfPer;
    m_i32MaxSumOfPer = src.m_i32MaxSumOfPer;
}

//拷贝赋值函数
CIPStaticNotein& CIPStaticNotein::operator=(const CIPStaticNotein& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_slFaceList = src.m_slFaceList;
    m_i32MaxNum = src.m_i32MaxNum;
    m_i32MinNum = src.m_i32MinNum;
    m_i32MaxSum = src.m_i32MaxSum;
    m_i32MinSum = src.m_i32MinSum;
    m_bPerFlag = src.m_bPerFlag;
    m_i32MaxNumOfPer = src.m_i32MaxNumOfPer;
    m_i32MaxSumOfPer = src.m_i32MaxSumOfPer;

    return *this;
}


QStringList CIPStaticNotein::GetFaceList()
{
    return m_slFaceList;
}

void CIPStaticNotein::SetFaceList(const QStringList& slFaceList)
{
    m_slFaceList = slFaceList;
}

qint32 CIPStaticNotein::GetMaxNum() const
{
    return m_i32MaxNum;
}

void CIPStaticNotein::SetMaxNum(qint32 i32MaxNum)
{
    m_i32MaxNum = i32MaxNum;
}

qint32 CIPStaticNotein::GetMinNum() const
{
    return m_i32MinNum;
}

void CIPStaticNotein::SetMinNum(qint32 i32MinNum)
{
    m_i32MinNum = i32MinNum;
}

qint32 CIPStaticNotein::GetMaxSum() const
{
    return m_i32MaxSum;
}

void CIPStaticNotein::SetMaxSum(qint32 i32MaxSum)
{
    m_i32MaxSum = i32MaxSum;
}

qint32 CIPStaticNotein::GetMinSum() const
{
    return m_i32MinSum;
}

void CIPStaticNotein::SetMinSum(qint32 i32MinSum)
{
    m_i32MinSum = i32MinSum;
}

bool CIPStaticNotein::GetPerFlag() const
{
    return m_bPerFlag;
}

void CIPStaticNotein::SetPerFlag(bool bPerFlag)
{
    m_bPerFlag = bPerFlag;
}

qint32 CIPStaticNotein::GetMaxNumOfPer() const
{
    return m_i32MaxNumOfPer;
}

void CIPStaticNotein::SetMaxNumOfPer(qint32 i32MaxNumOfPer)
{
    m_i32MaxNumOfPer = i32MaxNumOfPer;
}

qint32 CIPStaticNotein::GetMaxSumOfPer() const
{
    return m_i32MaxSumOfPer;
}

void CIPStaticNotein::SetMaxSumOfPer(qint32 i32MaxSumOfPer)
{
    m_i32MaxSumOfPer = i32MaxSumOfPer;
}

void CIPStaticNotein::Clear()
{
    m_slFaceList.clear();
    m_i32MaxNum = 0;
    m_i32MinNum = 0;
    m_i32MaxSum = 0;
    m_i32MinSum = 0;
    m_bPerFlag = false;
    m_i32MaxNumOfPer = 0;
    m_i32MaxSumOfPer = 0;
}
