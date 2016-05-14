#ifndef XML_PARAM_LOTBOX_LIMIT_H
#define XML_PARAM_LOTBOX_LIMIT_H

#include <QObject>

class CXPLotboxLimit : public QObject
{
    Q_OBJECT
public:
    explicit CXPLotboxLimit(QObject *parent = 0);
    ~CXPLotboxLimit();

    //拷贝构造函数
    CXPLotboxLimit(const CXPLotboxLimit& src);
    //拷贝赋值函数
    CXPLotboxLimit& operator=();
    
signals:
    
public slots:

private:
    qint32              m_i32MinFace;           //最小面值
    qint32              m_i32MaxFace;           //最大面值
    qint32              m_i32BoxNum;            //票箱数量
    qint32              m_i32MinNum;            //最小彩票数量
    qint32              m_i32MaxNum;            //最大彩票数量
    qint32              m_i32MinNote;           //最小彩票本数
    qint32              m_i32MaxNote;           //最大彩票本数

    
};

#endif // XML_PARAM_LOTBOX_LIMIT_H
