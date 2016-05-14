#include "IPStockNoteoutBox.h"

CIPStockNoteoutBox::CIPStockNoteoutBox(QObject *parent) :
    QObject(parent)
  ,m_i32Face(0)
  ,m_i32TotalNoteNum(0)
  ,m_i32BoxNoteNum(0)
  ,m_i32RejectNoteNum(0)
  ,m_i32RejectCount(0)
{
}

CIPStockNoteoutBox::~CIPStockNoteoutBox()
{

}

//拷贝构造函数
CIPStockNoteoutBox::CIPStockNoteoutBox(const CIPStockNoteoutBox& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32Face = src.m_i32Face;
    m_i32TotalNoteNum = src.m_i32TotalNoteNum;
    m_i32BoxNoteNum = src.m_i32BoxNoteNum;
    m_i32RejectNoteNum = src.m_i32RejectNoteNum;
    m_i32RejectCount = src.m_i32RejectCount;
}

//拷贝赋值函数
CIPStockNoteoutBox& CIPStockNoteoutBox::operator=(const CIPStockNoteoutBox& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32Face = src.m_i32Face;
    m_i32TotalNoteNum = src.m_i32TotalNoteNum;
    m_i32BoxNoteNum = src.m_i32BoxNoteNum;
    m_i32RejectNoteNum = src.m_i32RejectNoteNum;
    m_i32RejectCount = src.m_i32RejectCount;

    return *this;
}

qint32 CIPStockNoteoutBox::GetFace() const
{
    return m_i32Face;
}

void CIPStockNoteoutBox::SetFace(qint32 i32Face)
{
    m_i32Face = i32Face;
}

qint32 CIPStockNoteoutBox::GetTotalNoteNum() const
{
    return m_i32TotalNoteNum;
}

void CIPStockNoteoutBox::SetTotalNoteNum(qint32 i32TotalNoteNum)
{
    m_i32TotalNoteNum = i32TotalNoteNum;
}

qint32 CIPStockNoteoutBox::GetBoxNoteNum() const
{
    return m_i32BoxNoteNum;
}

void CIPStockNoteoutBox::SetBoxNoteNum(qint32 i32BoxNoteNum)
{
    m_i32BoxNoteNum = i32BoxNoteNum;
}

qint32 CIPStockNoteoutBox::GetRejectNoteNum() const
{
    return m_i32RejectNoteNum;
}

void CIPStockNoteoutBox::SetRejectNoteNum(qint32 i32RejectNoteNum)
{
    m_i32RejectNoteNum = i32RejectNoteNum;
}

qint32 CIPStockNoteoutBox::GetRejectCount() const
{
    return m_i32RejectCount;
}

void CIPStockNoteoutBox::SetRejectCount(qint32 i32RejectCount)
{
    m_i32RejectCount = i32RejectCount;
}

void CIPStockNoteoutBox::Clear()
{
    m_i32Face = 0;
    m_i32TotalNoteNum = 0;
    m_i32BoxNoteNum = 0;
    m_i32RejectNoteNum = 0;
    m_i32RejectCount = 0;
}
