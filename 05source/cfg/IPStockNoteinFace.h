#ifndef INI_PARAM_STOCK_NOTEIN_FACE_H
#define INI_PARAM_STOCK_NOTEIN_FACE_H

#include <QObject>

class CIPStockNoteinFace : public QObject
{
    Q_OBJECT
public:
    explicit CIPStockNoteinFace(QObject *parent = 0);
    ~CIPStockNoteinFace();

    //拷贝构造函数
    CIPStockNoteinFace(const CIPStockNoteinFace& src);
    //拷贝赋值函数
    CIPStockNoteinFace& operator=(const CIPStockNoteinFace& src);

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

#endif // INI_PARAM_STOCK_NOTEIN_FACE_H
