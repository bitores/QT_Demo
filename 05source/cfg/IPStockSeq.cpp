#include "IPStockSeq.h"

CIPStockSeq::CIPStockSeq(QObject *parent) :
    QObject(parent)
  ,m_i32Message(0)
  ,m_i32Package(0)
  ,m_i32Batch(0)
{
}

CIPStockSeq::~CIPStockSeq()
{

}

//拷贝构造函数
CIPStockSeq::CIPStockSeq(const CIPStockSeq& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32Message = src.m_i32Message;
    m_i32Package = src.m_i32Package;
    m_i32Batch = src.m_i32Batch;
}

//拷贝赋值函数
CIPStockSeq& CIPStockSeq::operator=(const CIPStockSeq& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32Message = src.m_i32Message;
    m_i32Package = src.m_i32Package;
    m_i32Batch = src.m_i32Batch;

    return *this;
}

qint32 CIPStockSeq::GetMessage() const
{
    return m_i32Message;
}

void CIPStockSeq::SetMessage(qint32 i32Message)
{
    m_i32Message = i32Message;
}

qint32 CIPStockSeq::GetPackage() const
{
    return m_i32Package;
}

void CIPStockSeq::SetPackage(qint32 i32Package)
{
    m_i32Package = i32Package;
}

qint32 CIPStockSeq::GetBatch() const
{
    return m_i32Batch;
}

void CIPStockSeq::SetBatch(qint32 i32Batch)
{
    m_i32Batch = i32Batch;
}

void CIPStockSeq::Clear()
{
    m_i32Message = 0;
    m_i32Package = 0;
    m_i32Batch = 0;
}
