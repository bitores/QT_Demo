#include "IPStaticFtp.h"

CIPStaticFtp::CIPStaticFtp(QObject *parent) :
    QObject(parent)
  ,m_strIp("")
  ,m_i16Port(0)
  ,m_strUser("")
  ,m_strPassword("")
{
}

CIPStaticFtp::~CIPStaticFtp()
{

}

//拷贝构造函数
CIPStaticFtp::CIPStaticFtp(const CIPStaticFtp& src)
{
    if (this == &src)
    {
        return;
    }

    m_strIp = src.m_strIp;
    m_i16Port = src.m_i16Port;
    m_strUser = src.m_strUser;
    m_strPassword = src.m_strPassword;
}

//拷贝赋值函数
CIPStaticFtp& CIPStaticFtp::operator=(const CIPStaticFtp& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_strIp = src.m_strIp;
    m_i16Port = src.m_i16Port;
    m_strUser = src.m_strUser;
    m_strPassword = src.m_strPassword;

    return *this;
}

QString CIPStaticFtp::GetIp() const
{
    return m_strIp;
}

void CIPStaticFtp::SetIp(const QString& strIp)
{
    m_strIp = strIp;
}

qint16 CIPStaticFtp::GetPort() const
{
    return m_i16Port;
}

void CIPStaticFtp::SetPort(qint16 i16Port)
{
    m_i16Port = i16Port;
}

QString CIPStaticFtp::GetUser() const
{
    return m_strUser;
}

void CIPStaticFtp::SetUser(const QString& strUser)
{
    m_strUser = strUser;
}

QString CIPStaticFtp::GetPassword() const
{
    return m_strPassword;
}

void CIPStaticFtp::SetPassword(const QString& strPassword)
{
    m_strPassword = strPassword;
}

void CIPStaticFtp::Clear()
{
    m_strIp = "";
    m_i16Port = 0;
    m_strUser = "";
    m_strPassword = "";
}
