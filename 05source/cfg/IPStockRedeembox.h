#ifndef INI_PARAM_STOCK_REDEEM_BOX_H
#define INI_PARAM_STOCK_REDEEM_BOX_H

#include <QObject>

class CIPStockRedeembox : public QObject
{
    Q_OBJECT
public:
    explicit CIPStockRedeembox(QObject *parent = 0);
    ~CIPStockRedeembox();

    //拷贝构造函数
    CIPStockRedeembox(const CIPStockRedeembox& src);
    //拷贝赋值函数
    CIPStockRedeembox& operator=(const CIPStockRedeembox& src);

public:

    qint32 GetCurNum() const;
    void SetCurNum(qint32 i32CurNum);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32CurNum;            //当前数量
    
};

#endif // INI_PARAM_STOCK_REDEEM_BOX_H
