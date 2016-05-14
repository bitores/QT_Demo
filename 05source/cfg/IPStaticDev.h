#ifndef INI_PARAM_STATIC_DEV_H
#define INI_PARAM_STATIC_DEV_H

#include <QObject>

class CIPStaticDev : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticDev(QObject *parent = 0);
    ~CIPStaticDev();

    //拷贝构造函数
    CIPStaticDev(const CIPStaticDev& src);
    //拷贝赋值函数
    CIPStaticDev& operator=(const CIPStaticDev& src);

public:
    QString GetDevType() const;
    void SetDevType(const QString& strDevType);

    QString GetDevID() const;
    void SetDevID(const QString& strDevID);

    QString GetStationID() const;
    void SetStationID(const QString& strStationID);

    quint32 GetInitMsleep();
    void SetInitMsleep(quint32 ui32Msleep);

    void Clear();
    
signals:
    
public slots:

public:
    QString             m_strDevType;           //设备类型:4位字符串,目前为L500/L501之一.默认为L500.
    QString             m_strDevID;             //设备id
    QString             m_strStationID;         //站点ID,只用于终端重复兑奖过滤时显示用
    quint32             m_ui32InitMsleep;       //设备模块初始化时间隔时间,单位为毫秒，最下为0毫秒，最大为60000毫秒（10分钟）
    
};

#endif // INI_PARAM_STATIC_DEV_H
