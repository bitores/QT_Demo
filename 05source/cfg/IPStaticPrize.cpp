#include "IPStaticPrize.h"

CIPStaticPrize::CIPStaticPrize(QObject *parent) :
    QObject(parent)
  ,m_i32PrizeType(0)
  ,m_i32MaxSum(0)
  ,m_bFilterRedeem(false)
  ,m_i32FlashTime(15)
  ,m_i32ShowTime(20)
{
}

CIPStaticPrize::~CIPStaticPrize()
{

}

//拷贝构造函数
CIPStaticPrize::CIPStaticPrize(const CIPStaticPrize& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32PrizeType = src.m_i32PrizeType;
    m_i32MaxSum = src.m_i32MaxSum;
    m_bFilterRedeem = src.m_bFilterRedeem;
    m_i32FlashTime = src.m_i32FlashTime;
    m_i32ShowTime = src.m_i32ShowTime;
}

//拷贝赋值函数
CIPStaticPrize& CIPStaticPrize::operator=(const CIPStaticPrize& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32PrizeType = src.m_i32PrizeType;
    m_i32MaxSum = src.m_i32MaxSum;
    m_bFilterRedeem = src.m_bFilterRedeem;
    m_i32FlashTime = src.m_i32FlashTime;
    m_i32ShowTime = src.m_i32ShowTime;

    return *this;
}

qint32 CIPStaticPrize::GetPrizeType() const
{
    return m_i32PrizeType;
}

void CIPStaticPrize::SetPrizeType(qint32 i32PrizeType)
{
    m_i32PrizeType = i32PrizeType;
}

qint32 CIPStaticPrize::GetMaxSum() const
{
    return m_i32MaxSum;
}

void CIPStaticPrize::SetMaxSum(qint32 i32MaxSum)
{
    m_i32MaxSum = i32MaxSum;
}

bool CIPStaticPrize::GetFilterRedeem() const
{
    return m_bFilterRedeem;
}

void CIPStaticPrize::SetFilterRedeem(bool bFilterRedeem)
{
    m_bFilterRedeem = bFilterRedeem;
}

qint32 CIPStaticPrize::GetFlashTime() const
{
    return m_i32FlashTime;
}
void CIPStaticPrize::SetFlashTime(qint32 i32FlashTime)
{
    m_i32FlashTime = i32FlashTime;
}

qint32 CIPStaticPrize::GetShowTime() const
{
    return m_i32ShowTime;
}
void CIPStaticPrize::SetShowTime(qint32 i32ShowTime)
{
    m_i32ShowTime = i32ShowTime;
}

void CIPStaticPrize::Clear()
{
    m_i32PrizeType = 0;
    m_i32MaxSum = 0;
    m_bFilterRedeem = false;
    m_i32FlashTime = 0;
    m_i32ShowTime = 0;
}
