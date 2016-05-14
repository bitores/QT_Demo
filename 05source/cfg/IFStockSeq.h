#ifndef INI_FILE_STOCK_SEQ_H
#define INI_FILE_STOCK_SEQ_H

#include "IFBase.h"
#include "IPStockSeq.h"

class CIFStockSeq : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStockSeq(QObject *parent = 0);
    ~CIFStockSeq();

    //拷贝构造函数
    CIFStockSeq(const CIFStockSeq& src);
    //拷贝赋值函数
    CIFStockSeq& operator=(const CIFStockSeq& src);

public:
    CIPStockSeq GetSeq();
    void SetSeq(const CIPStockSeq& seq);

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();
    
signals:
    
public slots:

public:
    CIPStockSeq         m_seq;
    
};

#endif // INI_FILE_STOCK_SEQ_H
