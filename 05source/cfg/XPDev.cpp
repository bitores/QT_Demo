#include "XPDev.h"

CXPDev::CXPDev(QObject *parent) :
    QObject(parent)
  ,m_strDevID("")
  ,m_i32LinkMode(0)
{
}

CXPDev::~CXPDev()
{

}

//拷贝构造函数
CXPDev::CXPDev(const CXPDev& src)
{
    if (this == &src)
    {
        return;
    }

    m_strDevID = src.m_strDevID;
    m_i32LinkMode = src.m_i32LinkMode;
}

//拷贝赋值函数
CXPDev& CXPDev::operator=(const CXPDev& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_strDevID = src.m_strDevID;
    m_i32LinkMode = src.m_i32LinkMode;

    return *this;
}

QString CXPDev::GetDevID()
{
    return m_strDevID;
}

void CXPDev::SetDevID(const QString& strDevID)
{
    m_strDevID = strDevID;
}

qint32 CXPDev::GetLinkMode()
{
    return m_i32LinkMode;
}

void CXPDev::SetLinkMode(qint32 i32LinkMode)
{
    m_i32LinkMode = i32LinkMode;
}
