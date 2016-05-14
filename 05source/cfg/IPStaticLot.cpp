#include "IPStaticLot.h"

CIPStaticLot::CIPStaticLot(QObject *parent) :
    QObject(parent)
  ,m_strLotTypeID("")
  ,m_strName("")
  ,m_i32Face(0)
  ,m_strFaceName("")
  ,m_i32HighestBonus(0)
  ,m_i32LotLen(0)
  ,m_strRate("")
  ,m_strLotPhoto("")
  ,m_strDescribeIco("")
  ,m_strDescribeText("")
{
}

CIPStaticLot::~CIPStaticLot()
{

}

//拷贝构造函数
CIPStaticLot::CIPStaticLot(const CIPStaticLot& src)
{
    if (this == &src)
    {
        return;
    }

    m_strLotTypeID = src.m_strLotTypeID;
    m_strName = src.m_strName;
    m_i32Face = src.m_i32Face;
    m_strFaceName = src.m_strFaceName;
    m_i32HighestBonus = src.m_i32HighestBonus;
    m_i32LotLen = src.m_i32LotLen;
    m_strRate = src.m_strRate;
    m_strLotPhoto = src.m_strLotPhoto;
    m_strDescribeIco = src.m_strDescribeIco;
    m_strDescribeText = src.m_strDescribeText;
}

//拷贝赋值函数
CIPStaticLot& CIPStaticLot::operator=(const CIPStaticLot& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_strLotTypeID = src.m_strLotTypeID;
    m_strName = src.m_strName;
    m_i32Face = src.m_i32Face;
    m_strFaceName = src.m_strFaceName;
    m_i32HighestBonus = src.m_i32HighestBonus;
    m_i32LotLen = src.m_i32LotLen;
    m_strRate = src.m_strRate;
    m_strLotPhoto = src.m_strLotPhoto;
    m_strDescribeIco = src.m_strDescribeIco;
    m_strDescribeText = src.m_strDescribeText;

    return *this;
}

QString CIPStaticLot::GetLotTypeID() const
{
    return m_strLotTypeID;
}

void CIPStaticLot::SetLotTypeID(const QString& strLotTypeID)
{
    m_strLotTypeID = strLotTypeID;
}

QString CIPStaticLot::GetName() const
{
    return m_strName;
}

void CIPStaticLot::SetName(const QString& strName)
{
    m_strName = strName;
}

qint32 CIPStaticLot::GetFace() const
{
    return m_i32Face;
}

void CIPStaticLot::SetFace(qint32 i32Face)
{
    m_i32Face = i32Face;
}

QString CIPStaticLot::GetFaceName() const
{
    return m_strFaceName;
}

void CIPStaticLot::SetFaceName(const QString& strFaceName)
{
    m_strFaceName = strFaceName;
}

qint32 CIPStaticLot::GetHighestBonus() const
{
    return m_i32HighestBonus;
}

void CIPStaticLot::SetHighestBonus(qint32 i32HighestBonus)
{
    m_i32HighestBonus = i32HighestBonus;
}

qint32 CIPStaticLot::GetLotLen() const
{
    return m_i32LotLen;
}

void CIPStaticLot::SetLotLen(qint32 i32LotLen)
{
    m_i32LotLen = i32LotLen;
}

QString CIPStaticLot::GetRate() const
{
    return m_strRate;
}

void CIPStaticLot::SetRate(const QString& strRate)
{
    m_strRate = strRate;
}

QString CIPStaticLot::GetLotPhoto() const
{
    return m_strLotPhoto;
}

void CIPStaticLot::SetLotPhoto(const QString& strLotPhoto)
{
    m_strLotPhoto = strLotPhoto;
}

QString CIPStaticLot::GetDescribeIco() const
{
    return m_strDescribeIco;
}

void CIPStaticLot::SetDescribeIco(const QString& strDescribeIco)
{
    m_strDescribeIco = strDescribeIco;
}

QString CIPStaticLot::GetDescribeText() const
{
    return m_strDescribeText;
}

void CIPStaticLot::SetDescribeText(const QString& strDescribeText)
{
    m_strDescribeText = strDescribeText;
}

void CIPStaticLot::Clear()
{
    m_strLotTypeID = "";
    m_strName = "";
    m_i32Face = 0;
    m_strFaceName = "";
    m_i32HighestBonus = 0;
    m_i32LotLen = 0;
    m_strRate = "";
    m_strLotPhoto = "";
    m_strDescribeIco = "";
    m_strDescribeText = "";
}
