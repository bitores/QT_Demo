#include "IPStaticNoteout.h"

CIPStaticNoteout::CIPStaticNoteout(QObject *parent) :
    QObject(parent)
  ,m_i32CurFace(0)
  ,m_i32MaxNum(0)
  ,m_i32MinNum(0)
  ,m_bPerFlag(false)
  ,m_i32MaxNumOfPer(0)
  ,m_i32IntervalOfPer(0)
  ,m_i32RejectMaxCount(0)
  ,m_i32RejectTakeRange(0)
{
}

CIPStaticNoteout::~CIPStaticNoteout()
{

}

//拷贝构造函数
CIPStaticNoteout::CIPStaticNoteout(const CIPStaticNoteout& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32CurFace = src.m_i32CurFace;
    m_i32MaxNum = src.m_i32MaxNum;
    m_i32MinNum = src.m_i32MinNum;
    m_bPerFlag = src.m_bPerFlag;
    m_i32MaxNumOfPer = src.m_i32MaxNumOfPer;
    m_i32IntervalOfPer = src.m_i32IntervalOfPer;
    m_i32RejectMaxCount = src.m_i32RejectMaxCount;
    m_i32RejectTakeRange = src.m_i32RejectTakeRange;
}

//拷贝赋值函数
CIPStaticNoteout& CIPStaticNoteout::operator=(const CIPStaticNoteout& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32CurFace = src.m_i32CurFace;
    m_i32MaxNum = src.m_i32MaxNum;
    m_i32MinNum = src.m_i32MinNum;
    m_bPerFlag = src.m_bPerFlag;
    m_i32MaxNumOfPer = src.m_i32MaxNumOfPer;
    m_i32IntervalOfPer = src.m_i32IntervalOfPer;
    m_i32RejectMaxCount = src.m_i32RejectMaxCount;
    m_i32RejectTakeRange = src.m_i32RejectTakeRange;

    return *this;
}

qint32 CIPStaticNoteout::GetCurFace() const
{
    return m_i32CurFace;
}

void CIPStaticNoteout::SetCurFace(qint32 i32CurFace)
{
    m_i32CurFace = i32CurFace;
}

qint32 CIPStaticNoteout::GetMaxNum() const
{
    return m_i32MaxNum;
}

void CIPStaticNoteout::SetMaxNum(qint32 i32MaxNum)
{
    m_i32MaxNum = i32MaxNum;
}

qint32 CIPStaticNoteout::GetMinNum() const
{
    return m_i32MinNum;
}

void CIPStaticNoteout::SetMinNum(qint32 i32MinNum)
{
    m_i32MinNum = i32MinNum;
}

bool CIPStaticNoteout::GetPerFlag() const
{
    return m_bPerFlag;
}

void CIPStaticNoteout::SetPerFlag(bool bPerFlag)
{
    m_bPerFlag = bPerFlag;
}

qint32 CIPStaticNoteout::GetMaxNumOfPer() const
{
    return m_i32MaxNumOfPer;
}

void CIPStaticNoteout::SetMaxNumOfPer(qint32 i32MaxNumOfPer)
{
    m_i32MaxNumOfPer = i32MaxNumOfPer;
}

qint32 CIPStaticNoteout::GetIntervalOfPer() const
{
    return m_i32IntervalOfPer;
}

void CIPStaticNoteout::SetIntervalOfPer(qint32 i32IntervalOfPer)
{
    m_i32IntervalOfPer = i32IntervalOfPer;
}

quint32 CIPStaticNoteout::GetRejectMaxCount()
{
    return m_i32RejectMaxCount;
}

void CIPStaticNoteout::SetRejectMaxCount(quint32 i32RejectMaxCount)
{
    m_i32RejectMaxCount = i32RejectMaxCount;
}

quint32 CIPStaticNoteout::GetRejectTakeRange()
{
    return m_i32RejectTakeRange;
}

void CIPStaticNoteout::SetRejectTakeRange(quint32 i32RejectTakeRange)
{
    m_i32RejectTakeRange = i32RejectTakeRange;
}

void CIPStaticNoteout::Clear()
{
    m_i32CurFace = 0;
    m_i32MaxNum = 0;
    m_i32MinNum = 0;
    m_bPerFlag = false;
    m_i32MaxNumOfPer = 0;
    m_i32IntervalOfPer = 0;
    m_i32RejectTakeRange = 0;
}
