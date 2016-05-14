#ifndef INI_PARAM_STOCK_LOTBOX_BOX_H
#define INI_PARAM_STOCK_LOTBOX_BOX_H

#include <QObject>

class CIPStockLotboxBox: public QObject
{
    Q_OBJECT
public:
    explicit CIPStockLotboxBox(QObject *parent = 0);
    ~CIPStockLotboxBox();

    //拷贝构造函数
    CIPStockLotboxBox(const CIPStockLotboxBox& src);
    //拷贝赋值函数
    CIPStockLotboxBox& operator=(const CIPStockLotboxBox& src);

public:
    qint32 GetCurNum() const;
    void SetCurNum(qint32 i32CurNum);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32CurNum;            //票箱内的彩票的当前数量
    
};

#endif // INI_PARAM_STOCK_LOTBOX_BOX_H
