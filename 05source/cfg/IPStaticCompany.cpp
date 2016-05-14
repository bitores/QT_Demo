#include "IPStaticCompany.h"

CIPStaticCompany::CIPStaticCompany(QObject *parent) :
    QObject(parent)
  ,m_strName("")
  ,m_strHotLine("")
{

}

CIPStaticCompany::~CIPStaticCompany()
{

}

//拷贝构造函数
CIPStaticCompany::CIPStaticCompany(const CIPStaticCompany& src)
{
    if (this == &src)
    {
        return;
    }

    m_strName = src.m_strName;
    m_strHotLine = src.m_strHotLine;
}

//拷贝赋值函数
CIPStaticCompany& CIPStaticCompany::operator=(const CIPStaticCompany& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_strName = src.m_strName;
    m_strHotLine = src.m_strHotLine;

    return *this;
}

QString CIPStaticCompany::GetName() const
{
    return m_strName;
}

void CIPStaticCompany::SetName(const QString& strName)
{
    m_strName = strName;
}

QString CIPStaticCompany::GetHotline() const
{
    return m_strHotLine;
}

void CIPStaticCompany::SetHotline(const QString& strHotline)
{
    m_strHotLine = strHotline;
}

void CIPStaticCompany::Clear()
{
    m_strName = "";
    m_strHotLine = "";
}
