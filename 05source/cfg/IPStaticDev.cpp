#include "IPStaticDev.h"

CIPStaticDev::CIPStaticDev(QObject *parent) :
    QObject(parent)
  ,m_strDevType("L500")
  ,m_strDevID("")
  ,m_strStationID("")
  ,m_ui32InitMsleep(0)
{
}

CIPStaticDev::~CIPStaticDev()
{

}

//拷贝构造函数
CIPStaticDev::CIPStaticDev(const CIPStaticDev& src)
{
    if (this == &src)
    {
        return;
    }

    m_strDevType = src.m_strDevType;
    m_strDevID = src.m_strDevID;
    m_strStationID = src.m_strStationID;
    m_ui32InitMsleep = src.m_ui32InitMsleep;
}

//拷贝赋值函数
CIPStaticDev& CIPStaticDev::operator=(const CIPStaticDev& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_strDevType = src.m_strDevType;
    m_strDevID = src.m_strDevID;
    m_strStationID = src.m_strStationID;
    m_ui32InitMsleep = src.m_ui32InitMsleep;

    return *this;
}

QString CIPStaticDev::GetDevType() const
{
    return m_strDevType;
}

void CIPStaticDev::SetDevType(const QString& strDevType)
{
    m_strDevType = strDevType;
}

QString CIPStaticDev::GetDevID() const
{
    return m_strDevID;
}

void CIPStaticDev::SetDevID(const QString& strDevID)
{
    m_strDevID = strDevID;
}

QString CIPStaticDev::GetStationID() const
{
    return m_strStationID;
}

void CIPStaticDev::SetStationID(const QString& strStationID)
{
    m_strStationID = strStationID;
}

quint32 CIPStaticDev::GetInitMsleep()
{
    return m_ui32InitMsleep;
}

void CIPStaticDev::SetInitMsleep(quint32 ui32Msleep)
{
    if (ui32Msleep > 60000)
    {
        ui32Msleep = 60000;
    }
    m_ui32InitMsleep = ui32Msleep;
}

void CIPStaticDev::Clear()
{
    m_strDevType = "";
    m_strDevID = "";
    m_strStationID = "";
    m_ui32InitMsleep = 0;
}
