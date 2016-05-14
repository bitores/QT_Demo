#ifndef XML_PARAM_COINER_STOCK_H
#define XML_PARAM_COINER_STOCK_H

#include <QObject>

class CXPCoinerStock : public QObject
{
    Q_OBJECT
public:
    explicit CXPCoinerStock(QObject *parent = 0);
    ~CXPCoinerStock();

    //拷贝构造函数
    CXPCoinerStock(const CXPCoinerStock& src);
    //拷贝赋值函数
    CXPCoinerStock& operator=(const CXPCoinerStock& src);

public:
    qint32 GetFace();
    void SetFace(qint32 i32Face);

    qint32 GetCurNum();
    void SetCurNum(qint32 i32CurNum);
    
signals:
    
public slots:

private:
    qint32              m_i32Face;              //面值
    qint32              m_i32CurNum;            //当前数量
    
};

#endif // XML_PARAM_COINER_STOCK_H
