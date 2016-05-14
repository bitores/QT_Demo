#ifndef INI_PARAM_STOCK_NOTEIN_H
#define INI_PARAM_STOCK_NOTEIN_H

#include <QObject>

class CIPStockNotein : public QObject
{
    Q_OBJECT
public:
    explicit CIPStockNotein(QObject *parent = 0);
    ~CIPStockNotein();

    //拷贝构造函数
    CIPStockNotein(const CIPStockNotein& src);
    //拷贝赋值函数
    CIPStockNotein& operator=(const CIPStockNotein& src);

public:
    qint32 GetFaceNum() const;
    void SetFaceNum(qint32 i32FaceNum);

    qint32 GetAllNum() const;
    void SetAllNum(qint32 i32AllNum);

    qint32 GetAllSum() const;
    void SetAllSum(qint32 i32AllSum);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32FaceNum;           //面值数量
    qint32              m_i32AllNum;            //纸币进币器内的所有纸币数量
    qint32              m_i32AllSum;            //纸币进币器内的所有纸币总额
    
};

#endif // INI_PARAM_STOCK_NOTEIN_H
