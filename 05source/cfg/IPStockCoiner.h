#ifndef INI_PARAM_STOCK_COINER_H
#define INI_PARAM_STOCK_COINER_H

#include <QObject>

class CIPStockCoiner : public QObject
{
    Q_OBJECT
public:
    explicit CIPStockCoiner(QObject *parent = 0);
    ~CIPStockCoiner();

    //拷贝构造函数
    CIPStockCoiner(const CIPStockCoiner& src);
    //拷贝赋值函数
    CIPStockCoiner& operator=(const CIPStockCoiner& src);

public:
    qint32 GetFace() const;
    void SetFace(qint32 i32Face);

    qint32 GetCurNum() const;
    void SetCurNum(qint32 i32CurNum);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32Face;              //面值
    qint32              m_i32CurNum;            //当前数量
    
};

#endif // INI_PARAM_STOCK_COINER_H
