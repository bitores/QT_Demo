#include "IPStaticHardware.h"

CIPStaticHardware::CIPStaticHardware(QObject *parent) :
    QObject(parent)
  ,m_strDiskNo("")
  ,m_strMac("")
//  ,m_strDevID("")
{
}

CIPStaticHardware::~CIPStaticHardware()
{

}

//拷贝构造函数
CIPStaticHardware::CIPStaticHardware(const CIPStaticHardware& src)
{
    if (this == &src)
    {
        return;
    }

    m_strDiskNo= src.m_strDiskNo;
    m_strMac= src.m_strMac;
//    m_strDevID= src.m_strDevID;
}

//拷贝赋值函数
CIPStaticHardware& CIPStaticHardware::operator=(const CIPStaticHardware& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_strDiskNo= src.m_strDiskNo;
    m_strMac= src.m_strMac;
//    m_strDevID= src.m_strDevID;

    return *this;
}

QString CIPStaticHardware::GetDiskNo() const
{
    return m_strDiskNo;
}

void CIPStaticHardware::SetDiskNo(const QString& strDiskNo)
{
    m_strDiskNo = strDiskNo;
}

QString CIPStaticHardware::GetMac() const
{
    return m_strMac;
}

void CIPStaticHardware::SetMac(const QString& strMac)
{
    m_strMac = strMac;
}

//QString CIPStaticHardware::GetDevID() const
//{
//    return m_strDevID;
//}

//void CIPStaticHardware::SetDevID(const QString& strDevID)
//{
//    m_strDevID = strDevID;
//}

void CIPStaticHardware::Clear()
{
    m_strDiskNo= "";
    m_strMac= "";
//    m_strDevID= "";
}
