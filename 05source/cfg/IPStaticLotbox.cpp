#include "IPStaticLotbox.h"

CIPStaticLotbox::CIPStaticLotbox(QObject *parent) :
    QObject(parent)
  ,m_i32MaxFace(0)
  ,m_i32MinFace(0)
  ,m_i32MaxNum(0)
  ,m_i32MinNum(0)
  ,m_i32MaxNote(0)
  ,m_i32MinNote(0)
  ,m_i32BoxNum(0)
  ,m_i32MaxNumOfOnce(50)
{
}

CIPStaticLotbox::~CIPStaticLotbox()
{

}

//拷贝构造函数
CIPStaticLotbox::CIPStaticLotbox(const CIPStaticLotbox& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32MaxFace = src.m_i32MaxFace;
    m_i32MinFace = src.m_i32MinFace;
    m_i32MaxNum = src.m_i32MaxNum;
    m_i32MinNum = src.m_i32MinNum;
    m_i32MaxNote = src.m_i32MaxNote;
    m_i32MinNote = src.m_i32MinNote;
    m_i32BoxNum = src.m_i32BoxNum;
    m_slLotTypeID =src.m_slLotTypeID;
    m_i32MaxNumOfOnce = src.m_i32MaxNumOfOnce;
    m_slDisable = src.m_slDisable;
    m_slLotTypeID = src.m_slLotTypeID;
}

//拷贝赋值函数
CIPStaticLotbox& CIPStaticLotbox::operator=(const CIPStaticLotbox& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32MaxFace = src.m_i32MaxFace;
    m_i32MinFace = src.m_i32MinFace;
    m_i32MaxNum = src.m_i32MaxNum;
    m_i32MinNum = src.m_i32MinNum;
    m_i32MaxNote = src.m_i32MaxNote;
    m_i32MinNote = src.m_i32MinNote;
    m_i32BoxNum = src.m_i32BoxNum;
    m_slLotTypeID =src.m_slLotTypeID;
    m_i32MaxNumOfOnce = src.m_i32MaxNumOfOnce;
    m_slDisable = src.m_slDisable;
    m_slLotTypeID = src.m_slLotTypeID;

    return *this;
}

qint32 CIPStaticLotbox::GetMaxFace() const
{
    return m_i32MaxFace;
}

void CIPStaticLotbox::SetMaxFace(qint32 i32MaxFace)
{
    m_i32MaxFace = i32MaxFace;
}

qint32 CIPStaticLotbox::GetMinFace() const
{
    return m_i32MinFace;
}

void CIPStaticLotbox::SetMinFace(qint32 i32MinFace)
{
    m_i32MinFace = i32MinFace;
}

qint32 CIPStaticLotbox::GetMaxNum() const
{
    return m_i32MaxNum;
}

void CIPStaticLotbox::SetMaxNum(qint32 i32MaxNum)
{
    m_i32MaxNum = i32MaxNum;
}

qint32 CIPStaticLotbox::GetMinNum() const
{
    return m_i32MinNum;
}

void CIPStaticLotbox::SetMinNum(qint32 i32MinNum)
{
    m_i32MinNum = i32MinNum;
}

qint32 CIPStaticLotbox::GetMaxNote() const
{
    return m_i32MaxNote;
}

void CIPStaticLotbox::SetMaxNote(qint32 i32MaxNote)
{
    m_i32MaxNote = i32MaxNote;
}

qint32 CIPStaticLotbox::GetMinNote() const
{
    return m_i32MinNote;
}

void CIPStaticLotbox::SetMinNote(qint32 i32MinNote)
{
    m_i32MinNote = i32MinNote;
}

qint32 CIPStaticLotbox::GetBoxNum() const
{
    return m_i32BoxNum;
}

void CIPStaticLotbox::SetBoxNum(qint32 i32BoxNum)
{
    m_i32BoxNum = i32BoxNum;
}

qint32 CIPStaticLotbox::GetMaxNumOfOnce() const
{
    return m_i32MaxNumOfOnce;
}

void CIPStaticLotbox::SetMaxNumOfOnce(qint32 i32MaxNumOfOnce)
{
    m_i32MaxNumOfOnce = i32MaxNumOfOnce;
}

QStringList CIPStaticLotbox::GetDisable()
{
    return m_slDisable;
}

void CIPStaticLotbox::SetDisable(const QStringList& slDisable)
{
    m_slDisable = slDisable;
}

QStringList CIPStaticLotbox::GetLotTypeID()
{
    return m_slLotTypeID;
}

void CIPStaticLotbox::SetLotTypeID(const QStringList& slLotTypeID)
{
    m_slLotTypeID = slLotTypeID;
}

void CIPStaticLotbox::Clear()
{
    m_i32MaxFace = 0;
    m_i32MinFace = 0;
    m_i32MaxNum = 0;
    m_i32MinNum = 0;
    m_i32MaxNote = 0;
    m_i32MinNote = 0;
    m_i32BoxNum = 0;
    m_i32MaxNumOfOnce = 0;
    m_slDisable.clear();
    m_slLotTypeID.clear();
}
