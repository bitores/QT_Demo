#include "IPStaticUps.h"

CIPStaticUps::CIPStaticUps(QObject *parent) :
    QObject(parent)
  ,m_bAutoBootFlag(false)
  ,m_strAutoBootTime("")
  ,m_bAutoShutdownFlag(false)
  ,m_strAutoShutdownTime("")
  ,m_i32ResponseTime(0)
  ,m_i32QueryStatusInterval(30)
{
}

CIPStaticUps::~CIPStaticUps()
{

}

//拷贝构造函数
CIPStaticUps::CIPStaticUps(const CIPStaticUps& src)
{
    if (this == &src)
    {
        return;
    }

    m_bAutoBootFlag = src.m_bAutoBootFlag;
    m_strAutoBootTime = src.m_strAutoBootTime;
    m_bAutoShutdownFlag = src.m_bAutoShutdownFlag;
    m_strAutoShutdownTime = src.m_strAutoShutdownTime;
    m_i32ResponseTime = src.m_i32ResponseTime;
    m_i32QueryStatusInterval = src.m_i32QueryStatusInterval;
}

//拷贝赋值函数
CIPStaticUps& CIPStaticUps::operator=(const CIPStaticUps& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_bAutoBootFlag = src.m_bAutoBootFlag;
    m_strAutoBootTime = src.m_strAutoBootTime;
    m_bAutoShutdownFlag = src.m_bAutoShutdownFlag;
    m_strAutoShutdownTime = src.m_strAutoShutdownTime;
    m_i32ResponseTime = src.m_i32ResponseTime;
    m_i32QueryStatusInterval = src.m_i32QueryStatusInterval;

    return *this;
}

bool CIPStaticUps::GetAutoBootFlag() const
{
    return m_bAutoBootFlag;
}

void CIPStaticUps::SetAutoBootFlag(bool bAutoBootFlag)
{
    m_bAutoBootFlag = bAutoBootFlag;
}

QString CIPStaticUps::GetAutoBootTime() const
{
    return m_strAutoBootTime;
}

void CIPStaticUps::SetAutoBootTime(const QString& strAutoBootTime)
{
    m_strAutoBootTime = strAutoBootTime;
}

bool CIPStaticUps::GetAutoShutdownFlag() const
{
    return m_bAutoShutdownFlag;
}

void CIPStaticUps::SetAutoShutdownFlag(bool bAutoShutdownFlag)
{
    m_bAutoShutdownFlag = bAutoShutdownFlag;
}

QString CIPStaticUps::GetAutoShutdownTime() const
{
    return m_strAutoShutdownTime;
}

void CIPStaticUps::SetAutoShutdownTime(const QString& strAutoShutdownTime)
{
    m_strAutoShutdownTime = strAutoShutdownTime;
}

qint32 CIPStaticUps::GetResponseTime() const
{
    return m_i32ResponseTime;
}

void CIPStaticUps::SetResponseTime(qint32 i32ResponseTime)
{
    m_i32ResponseTime = i32ResponseTime;
}

qint32 CIPStaticUps::GetQueryStatusInterval() const
{
    return m_i32QueryStatusInterval;
}

void CIPStaticUps::SetQueryStatusInterval(qint32 i32QueryStatusInterval)
{
    m_i32QueryStatusInterval = i32QueryStatusInterval;
}

void CIPStaticUps::Clear()
{
    m_bAutoBootFlag = false;
    m_strAutoBootTime = "";
    m_bAutoShutdownFlag = false;
    m_strAutoShutdownTime = "";
    m_i32ResponseTime = 0;
    m_i32QueryStatusInterval = 0;
}
