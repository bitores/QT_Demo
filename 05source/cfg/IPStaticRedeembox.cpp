#include "IPStaticRedeembox.h"

CIPStaticRedeembox::CIPStaticRedeembox(QObject *parent) :
    QObject(parent)
  ,m_i32MaxNum(0)
{

}

CIPStaticRedeembox::~CIPStaticRedeembox()
{

}

//拷贝构造函数
CIPStaticRedeembox::CIPStaticRedeembox(const CIPStaticRedeembox& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32MaxNum = src.m_i32MaxNum;
}

//拷贝赋值函数
CIPStaticRedeembox& CIPStaticRedeembox::operator=(const CIPStaticRedeembox& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32MaxNum = src.m_i32MaxNum;

    return *this;
}

qint32 CIPStaticRedeembox::GetMaxNum()
{
    return m_i32MaxNum;
}

void CIPStaticRedeembox::SetMaxNum(qint32 i32MaxNum)
{
    m_i32MaxNum = i32MaxNum;
}

void CIPStaticRedeembox::Clear()
{
    m_i32MaxNum = 0;
}
