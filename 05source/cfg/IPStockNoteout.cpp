#include "IPStockNoteout.h"

CIPStockNoteout::CIPStockNoteout(QObject *parent) :
    QObject(parent)
  ,m_bMultiBoxFlag(false)
  ,m_i32BoxNum(0)
  ,m_i32CurBoxIndex(0)
  ,m_i32AllNum(0)
  ,m_i32AllSum(0)
{
}

CIPStockNoteout::~CIPStockNoteout()
{

}

//拷贝构造函数
CIPStockNoteout::CIPStockNoteout(const CIPStockNoteout& src)
{
    if (this == &src)
    {
        return;
    }

    m_bMultiBoxFlag = src.m_bMultiBoxFlag;
    m_i32BoxNum = src.m_i32BoxNum;
    m_i32CurBoxIndex = src.m_i32CurBoxIndex;
    m_i32AllNum = src.m_i32AllNum;
    m_i32AllSum = src.m_i32AllSum;
}

//拷贝赋值函数
CIPStockNoteout& CIPStockNoteout::operator=(const CIPStockNoteout& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_bMultiBoxFlag = src.m_bMultiBoxFlag;
    m_i32BoxNum = src.m_i32BoxNum;
    m_i32CurBoxIndex = src.m_i32CurBoxIndex;
    m_i32AllNum = src.m_i32AllNum;
    m_i32AllSum = src.m_i32AllSum;

    return *this;
}

bool CIPStockNoteout::GetMultiBoxFlag() const
{
    return m_bMultiBoxFlag;
}

void CIPStockNoteout::SetMultiBoxFlag(bool bMultiBoxFlag)
{
    m_bMultiBoxFlag = bMultiBoxFlag;
}

qint32 CIPStockNoteout::GetBoxNum() const
{
    return m_i32BoxNum;
}

void CIPStockNoteout::SetBoxNum(qint32 i32BoxNum)
{
    m_i32BoxNum = i32BoxNum;
}

qint32 CIPStockNoteout::GetCurBoxIndex() const
{
    return m_i32CurBoxIndex;
}

void CIPStockNoteout::SetCurBoxIndex(qint32 i32CurBoxIndex)
{
    m_i32CurBoxIndex = i32CurBoxIndex;
}

qint32 CIPStockNoteout::GetAllNum() const
{
    return m_i32AllNum;
}

void CIPStockNoteout::SetAllNum(qint32 i32AllNum)
{
    m_i32AllNum = i32AllNum;
}

qint32 CIPStockNoteout::GetAllSum() const
{
    return m_i32AllSum;
}

void CIPStockNoteout::SetAllSum(qint32 i32AllSum)
{
    m_i32AllSum = i32AllSum;
}

void CIPStockNoteout::Clear()
{
    m_bMultiBoxFlag = false;
    m_i32BoxNum = 0;
    m_i32CurBoxIndex = 0;
    m_i32AllNum = 0;
    m_i32AllSum = 0;
}
