#ifndef INI_FILE_STOCK_COINER_H
#define INI_FILE_STOCK_COINER_H

#include "IFBase.h"
#include "IPStockCoiner.h"

class CIFStockCoiner : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStockCoiner(QObject *parent = 0);
    ~CIFStockCoiner();

    //拷贝构造函数
    CIFStockCoiner(const CIFStockCoiner& src);
    //拷贝赋值函数
    CIFStockCoiner& operator=(const CIFStockCoiner& src);

public:
    CIPStockCoiner GetCoiner();
    void SetCoiner(const CIPStockCoiner& coiner);

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();
    
signals:
    
public slots:

public:
    CIPStockCoiner      m_Coiner;               //硬币器的库存信息
    
};

#endif // INI_FILE_STOCK_COINER_H
