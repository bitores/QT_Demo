#include "XPFtp.h"

CXPFtp::CXPFtp(QObject *parent) :
    QObject(parent)
  ,m_strIp("")
  ,m_i16Port(0)
  ,m_strUser("")
  ,m_strPassword("")
{
}

CXPFtp::~CXPFtp()
{

}

//拷贝构造函数
CXPFtp::CXPFtp(const CXPFtp& src)
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
CXPFtp& CXPFtp::operator=(const CXPFtp& src)
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

QString CXPFtp::GetIp()
{
    return m_strIp;
}

void CXPFtp::SetIp(const QString& strIp)
{
    m_strIp = strIp;
}

qint16 CXPFtp::GetPort()
{
    return m_i16Port;
}

void CXPFtp::SetPort(qint16 i16Port)
{
    m_i16Port = i16Port;
}

QString CXPFtp::GetUser()
{
    return m_strUser;
}

void CXPFtp::SetUser(const QString& strUser)
{
    m_strUser = strUser;
}

QString CXPFtp::GetPassword()
{
    return m_strPassword;
}

void CXPFtp::SetPassword(const QString& strPassword)
{
    m_strPassword = strPassword;
}
