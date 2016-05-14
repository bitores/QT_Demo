#ifndef INI_FILE_STOCK_REDEEM_BOX_H
#define INI_FILE_STOCK_REDEEM_BOX_H

#include "IFBase.h"
#include "IPStockRedeembox.h"

class CIFStockRedeembox : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStockRedeembox(QObject *parent = 0);
    ~CIFStockRedeembox();

    //拷贝构造函数
    CIFStockRedeembox(const CIFStockRedeembox& src);
    //拷贝赋值函数
    CIFStockRedeembox& operator=(const CIFStockRedeembox& src);

public:
    CIPStockRedeembox GetRedeembox();
    void SetRedeembox(const CIPStockRedeembox& coiner);

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();
    
signals:
    
public slots:

public:
    CIPStockRedeembox   m_Redeembox;            //中奖彩票回收箱的库存信息
    
};

#endif // INI_FILE_STOCK_REDEEM_BOX_H
