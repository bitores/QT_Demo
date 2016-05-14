#ifndef INI_PARAM_STATIC_TIMER_H
#define INI_PARAM_STATIC_TIMER_H

#include <QObject>

class CIPStaticTimer : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticTimer(QObject *parent = 0);
    ~CIPStaticTimer();

    //拷贝构造函数
    CIPStaticTimer(const CIPStaticTimer& src);
    //拷贝赋值函数
    CIPStaticTimer& operator=(const CIPStaticTimer& src);

public:
    qint32 GetIntervalOfUpload() const;
    void SetIntervalOfUpload(qint32 i32IntervalOfUpload);

    void Clear();
    
signals:
    
public slots:

private:
    qint32              m_i32IntervalOfUpload;  //上传数据的间隔时间,单位毫秒
    
};

#endif // INI_PARAM_STATIC_TIMER_H
