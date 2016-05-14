#include "IPStaticTimer.h"

CIPStaticTimer::CIPStaticTimer(QObject *parent) :
    QObject(parent)
  ,m_i32IntervalOfUpload(0)
{
}

CIPStaticTimer::~CIPStaticTimer()
{

}

//拷贝构造函数
CIPStaticTimer::CIPStaticTimer(const CIPStaticTimer& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32IntervalOfUpload = src.m_i32IntervalOfUpload;
}

//拷贝赋值函数
CIPStaticTimer& CIPStaticTimer::operator=(const CIPStaticTimer& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32IntervalOfUpload = src.m_i32IntervalOfUpload;

    return *this;
}

qint32 CIPStaticTimer::GetIntervalOfUpload() const
{
    return m_i32IntervalOfUpload;
}

void CIPStaticTimer::SetIntervalOfUpload(qint32 i32IntervalOfUpload)
{
    m_i32IntervalOfUpload = i32IntervalOfUpload;
}

void CIPStaticTimer::Clear()
{
    m_i32IntervalOfUpload = 0;
}
