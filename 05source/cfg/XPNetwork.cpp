#include "XPNetwork.h"

CXPNetwork::CXPNetwork(QObject *parent) :
    QObject(parent)
  ,m_strMainIp("")
  ,m_i16MainPort(0)
  ,m_strSlaveIp("")
  ,m_i16SlavePort(0)
{
}

CXPNetwork::~CXPNetwork()
{

}

//拷贝构造函数
CXPNetwork::CXPNetwork(const CXPNetwork& src)
{
    if (this == &src)
    {
        return;
    }

    m_strMainIp = src.m_strMainIp;
    m_i16MainPort = src.m_i16MainPort;
    m_strSlaveIp = src.m_strSlaveIp;
    m_i16SlavePort = src.m_i16SlavePort;
}

//拷贝赋值函数
CXPNetwork& CXPNetwork::operator=(const CXPNetwork& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_strMainIp = src.m_strMainIp;
    m_i16MainPort = src.m_i16MainPort;
    m_strSlaveIp = src.m_strSlaveIp;
    m_i16SlavePort = src.m_i16SlavePort;

    return *this;
}

QString CXPNetwork::GetMainIp()
{
    return m_strMainIp;
}

void CXPNetwork::SetMainIp(const QString& strMainIp)
{
    m_strMainIp = strMainIp;
}

qint16 CXPNetwork::GetMainPort()
{
    return m_i16MainPort;
}

void CXPNetwork::SetMainPort(qint16 i16MainPort)
{
    m_i16MainPort = i16MainPort;
}

QString CXPNetwork::GetSlaveIp()
{
    return m_strSlaveIp;
}

void CXPNetwork::SetSlaveIp(const QString& strSlaveIp)
{
    m_strSlaveIp = strSlaveIp;
}

qint16 CXPNetwork::GetSlavePort()
{
    return m_i16SlavePort;
}

void CXPNetwork::SetSlavePort(qint16 i16SlavePort)
{
    m_i16SlavePort = i16SlavePort;
}
