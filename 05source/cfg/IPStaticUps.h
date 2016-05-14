#ifndef INI_PARAM_STATIC_UPS_H
#define INI_PARAM_STATIC_UPS_H

#include <QObject>

class CIPStaticUps : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticUps(QObject *parent = 0);
    ~CIPStaticUps();

    //拷贝构造函数
    CIPStaticUps(const CIPStaticUps& src);
    //拷贝赋值函数
    CIPStaticUps& operator=(const CIPStaticUps& src);

public:
    bool GetAutoBootFlag() const;
    void SetAutoBootFlag(bool bAutoBootFlag);

    QString GetAutoBootTime() const;
    void SetAutoBootTime(const QString& strAutoBootTime);

    bool GetAutoShutdownFlag() const;
    void SetAutoShutdownFlag(bool bAutoShutdownFlag);

    QString GetAutoShutdownTime() const;
    void SetAutoShutdownTime(const QString& strAutoShutdownTime);

    qint32 GetResponseTime() const;
    void SetResponseTime(qint32 i32ResponseTime);

    qint32 GetQueryStatusInterval() const;
    void SetQueryStatusInterval(qint32 i32QueryStatusInterval);

    void Clear();
    
signals:
    
public slots:

public:
    bool                m_bAutoBootFlag;        //自动开机标记
    QString             m_strAutoBootTime;      //自动开机时间,格式hh:mm
    bool                m_bAutoShutdownFlag;    //自动关机标记
    QString             m_strAutoShutdownTime;  //自动关机时间,格式hh:mm
    qint32              m_i32ResponseTime;      //ups响应时间,单位为分钟,最小5分钟,最大10分钟
    qint32              m_i32QueryStatusInterval;//ups定时查询状态的间隔时间,单位为秒,最小为5秒,最大为60秒,推荐30秒
    
};

#endif // INI_PARAM_STATIC_UPS_H
