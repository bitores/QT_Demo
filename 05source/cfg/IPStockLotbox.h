#ifndef INI_PARAM_STOCK_LOTBOX_H
#define INI_PARAM_STOCK_LOTBOX_H

#include <QObject>

class CIPStockLotbox : public QObject
{
    Q_OBJECT
public:
    explicit CIPStockLotbox(QObject *parent = 0);
    ~CIPStockLotbox();

    //拷贝构造函数
    CIPStockLotbox(const CIPStockLotbox& src);
    //拷贝赋值函数
    CIPStockLotbox& operator=(const CIPStockLotbox& src);

public:
    qint32 GetBoxNum() const;
    void SetBoxNum(qint32 i32BoxNum);

    qint32 GetAllNum() const;
    void SetAllNum(qint32 i32AllNum);

    qint32 GetAllSum() const;
    void SetAllSum(qint32 i32AllNum);

    qint32  GetMinFace() const;
    void SetMinFace(qint32 i32MinFace);

    qint32 GetMaxFace() const;
    void SetMaxFace(qint32 i32MaxFace);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32BoxNum;            //票箱数量
    qint32              m_i32AllNum;            //设备内的所有票箱内的所有彩票的数量
    qint32              m_i32AllSum;            //设备内的所有票箱内的所有彩票的总额
    qint32              m_i32MinFace;           //设备内的所有票箱内的当前可卖彩票的最小面值
    qint32              m_i32MaxFace;           //设备内的所有票箱内的当前可卖彩票的最大面值
    
};

#endif // INI_PARAM_STOCK_LOTBOX_H
