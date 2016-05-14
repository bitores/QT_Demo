#ifndef INI_PARAM_STATIC_REDEEM_BOX_H
#define INI_PARAM_STATIC_REDEEM_BOX_H

#include <QObject>

class CIPStaticRedeembox : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticRedeembox(QObject *parent = 0);
    ~CIPStaticRedeembox();

    //拷贝构造函数
    CIPStaticRedeembox(const CIPStaticRedeembox& src);
    //拷贝赋值函数
    CIPStaticRedeembox& operator=(const CIPStaticRedeembox& src);

public:
    qint32 GetMaxNum();
    void SetMaxNum(qint32 i32MaxNum);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32MaxNum;            //最大可回收的彩票张数,最小为100,最大为500,默认值为300,兑奖模式为直接扫描时为0
    
};

#endif // INI_PARAM_STATIC_REDEEM_BOX_H
