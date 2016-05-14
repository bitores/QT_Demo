#ifndef INI_PARAM_STATIC_NOTEOUT_H
#define INI_PARAM_STATIC_NOTEOUT_H

#include <QObject>

class CIPStaticNoteout : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticNoteout(QObject *parent = 0);
    ~CIPStaticNoteout();

    //拷贝构造函数
    CIPStaticNoteout(const CIPStaticNoteout& src);
    //拷贝赋值函数
    CIPStaticNoteout& operator=(const CIPStaticNoteout& src);

public:
    qint32 GetCurFace() const;
    void SetCurFace(qint32 i32CurFace);

    qint32 GetMaxNum() const;
    void SetMaxNum(qint32 i32MaxNum);

    qint32 GetMinNum() const;
    void SetMinNum(qint32 i32MinNum);

    bool GetPerFlag() const;
    void SetPerFlag(bool bPerFlag);

    qint32 GetMaxNumOfPer() const;
    void SetMaxNumOfPer(qint32 i32MaxNumOfPer);

    qint32 GetIntervalOfPer() const;
    void SetIntervalOfPer(qint32 i32IntervalOfPer);

    quint32 GetRejectMaxCount();
    void SetRejectMaxCount(quint32 i32RejectMaxCount);

    quint32 GetRejectTakeRange();
    void SetRejectTakeRange(quint32 i32RejectTakeRange);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32CurFace;           //当前面值
    qint32              m_i32MaxNum;            //最大数量
    qint32              m_i32MinNum;            //最小数量
    bool                m_bPerFlag;             //单次限制标记
    qint32              m_i32MaxNumOfPer;       //单次最大出钞数量
    qint32              m_i32IntervalOfPer;     //两次出钞间隔时间,单位毫秒
    quint32             m_i32RejectMaxCount;    //最大拒付次数
    quint32             m_i32RejectTakeRange;   //波动范围

    
};

#endif // INI_PARAM_STATIC_NOTEOUT_H
