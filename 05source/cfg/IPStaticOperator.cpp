#include "IPStaticOperator.h"

CIPStaticOperator::CIPStaticOperator(QObject *parent) :
    QObject(parent)
  ,m_strID("")
  ,m_strName("")
  ,m_strMobile("")
  ,m_strTel("")
{

}

CIPStaticOperator::~CIPStaticOperator()
{

}

//拷贝构造函数
CIPStaticOperator::CIPStaticOperator(const CIPStaticOperator& src)
{
    if (this == &src)
    {
        return;
    }

    m_strID = src.m_strID;
    m_strName = src.m_strName;
    m_strMobile = src.m_strMobile;
    m_strTel = src.m_strTel;
}

//拷贝赋值函数
CIPStaticOperator& CIPStaticOperator::operator=(const CIPStaticOperator& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_strID = src.m_strID;
    m_strName = src.m_strName;
    m_strMobile = src.m_strMobile;
    m_strTel = src.m_strTel;

    return *this;
}

QString CIPStaticOperator::GetID() const
{
    return m_strID;
}

void CIPStaticOperator::SetID(const QString& strID)
{
    m_strID = strID;
}

QString CIPStaticOperator::GetName() const
{
    return m_strName;
}

void CIPStaticOperator::SetName(const QString& strName)
{
    m_strName = strName;
}

QString CIPStaticOperator::GetMobile() const
{
    return m_strMobile;
}

void CIPStaticOperator::SetMobile(const QString& strMobile)
{
    m_strMobile = strMobile;
}

QString CIPStaticOperator::GetTel() const
{
    return m_strTel;
}

void CIPStaticOperator::SetTel(const QString& strTel)
{
    m_strTel = strTel;
}

void CIPStaticOperator::Clear()
{
    m_strID = "";
    m_strName = "";
    m_strMobile = "";
    m_strTel = "";
}
