#include "IPStaticNetwork.h"

CIPStaticNetwork::CIPStaticNetwork(QObject *parent) :
    QObject(parent)
  ,m_strMainIp("")
  ,m_i16MainPort(0)
  ,m_strSlaveIp("")
  ,m_i16SlavePort(0)
{
}

CIPStaticNetwork::~CIPStaticNetwork()
{

}

//拷贝构造函数
CIPStaticNetwork::CIPStaticNetwork(const CIPStaticNetwork& src)
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
CIPStaticNetwork& CIPStaticNetwork::operator=(const CIPStaticNetwork& src)
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

QString CIPStaticNetwork::GetMainIp() const
{
    return m_strMainIp;
}

void CIPStaticNetwork::SetMainIp(const QString& strMainIp)
{
    m_strMainIp = strMainIp;
}

qint16 CIPStaticNetwork::GetMainPort() const
{
    return m_i16MainPort;
}

void CIPStaticNetwork::SetMainPort(qint16 i16MainPort)
{
    m_i16MainPort = i16MainPort;
}

QString CIPStaticNetwork::GetSlaveIp() const
{
    return m_strSlaveIp;
}

void CIPStaticNetwork::SetSlaveIp(const QString& strSlaveIp)
{
    m_strSlaveIp = strSlaveIp;
}

qint16 CIPStaticNetwork::GetSlavePort() const
{
    return m_i16SlavePort;
}

void CIPStaticNetwork::SetSlavePort(qint16 i16SlavePort)
{
    m_i16SlavePort = i16SlavePort;
}

void CIPStaticNetwork::Clear()
{
    m_strMainIp = "";
    m_i16MainPort = 0;
    m_strSlaveIp = "";
    m_i16SlavePort = 0;
}
