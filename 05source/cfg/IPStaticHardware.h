#ifndef INI_PARAM_STATIC_HARDWARE_H
#define INI_PARAM_STATIC_HARDWARE_H

#include <QObject>

class CIPStaticHardware : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticHardware(QObject *parent = 0);
    ~CIPStaticHardware();

    //拷贝构造函数
    CIPStaticHardware(const CIPStaticHardware& src);
    //拷贝赋值函数
    CIPStaticHardware& operator=(const CIPStaticHardware& src);

public:
    QString GetDiskNo() const;
    void SetDiskNo(const QString& strDiskNo);

    QString GetMac() const;
    void SetMac(const QString& strMac);

//    QString GetDevID() const;
//    void SetDevID(const QString& strDevID);

    void Clear();
    
signals:
    
public slots:

public:
    QString             m_strDiskNo;            //硬币序列号
    QString             m_strMac;               //网卡MAC地址
//    QString             m_strDevID;             //设备编号
    
};

#endif // INI_PARAM_STATIC_HARDWARE_H
