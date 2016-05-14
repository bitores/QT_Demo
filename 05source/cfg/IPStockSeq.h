#ifndef INI_PARAM_STOCK_SEQ_H
#define INI_PARAM_STOCK_SEQ_H

#include <QObject>

class CIPStockSeq : public QObject
{
    Q_OBJECT
public:
    explicit CIPStockSeq(QObject *parent = 0);
    ~CIPStockSeq();

    //拷贝构造函数
    CIPStockSeq(const CIPStockSeq& src);
    //拷贝赋值函数
    CIPStockSeq& operator=(const CIPStockSeq& src);

public:
    qint32 GetMessage() const;
    void SetMessage(qint32 i32Message);

    qint32 GetPackage() const;
    void SetPackage(qint32 i32Package);

    qint32 GetBatch() const;
    void SetBatch(qint32 i32Batch);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32Message;           //消息序号
    qint32              m_i32Package;           //报文序号
    qint32              m_i32Batch;             //批次序号
    
};

#endif // INI_PARAM_STOCK_SEQ_H
