#ifndef INI_PARAM_STATIC_PRIZE_H
#define INI_PARAM_STATIC_PRIZE_H

#include <QObject>

class CIPStaticPrize : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticPrize(QObject *parent = 0);
    ~CIPStaticPrize();

    //拷贝构造函数
    CIPStaticPrize(const CIPStaticPrize& src);
    //拷贝赋值函数
    CIPStaticPrize& operator=(const CIPStaticPrize& src);

public:
    qint32 GetPrizeType() const;
    void SetPrizeType(qint32 i32PrizeType);

    qint32 GetMaxSum() const;
    void SetMaxSum(qint32 i32MaxSum);

    bool GetFilterRedeem() const;
    void SetFilterRedeem(bool bFilterRedeem);

    qint32 GetFlashTime() const;
    void SetFlashTime(qint32 i32FlashTime);

    qint32 GetShowTime() const;
    void SetShowTime(qint32 i32ShowTime);


    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32PrizeType;         //兑奖类型
    qint32              m_i32MaxSum;            //最大兑奖额度
    bool                m_bFilterRedeem;        //是否终端过滤重复兑奖，true为终端过滤，false为终端不过滤，默认为false
    qint32              m_i32FlashTime;         //中奖跑马灯闪烁时间，单位为秒，最小5秒，最大30秒，默认15秒
    qint32              m_i32ShowTime;          //中奖结果显示时间，单位为秒，最小5秒，最大30秒，默认20秒
    
};

#endif // INI_PARAM_STATIC_PRIZE_H
