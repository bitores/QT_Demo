#ifndef INI_PARAM_STATIC_NETWORK_H
#define INI_PARAM_STATIC_NETWORK_H

#include <QObject>

class CIPStaticNetwork : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticNetwork(QObject *parent = 0);
    ~CIPStaticNetwork();

    //拷贝构造函数
    CIPStaticNetwork(const CIPStaticNetwork& src);
    //拷贝赋值函数
    CIPStaticNetwork& operator=(const CIPStaticNetwork& src);

public:
    QString GetMainIp() const;
    void SetMainIp(const QString& strMainIp);

    qint16 GetMainPort() const;
    void SetMainPort(qint16 i16MainPort);

    QString GetSlaveIp() const;
    void SetSlaveIp(const QString& strSlaveIp);

    qint16 GetSlavePort() const;
    void SetSlavePort(qint16 i16SlavePort);

    void Clear();
    
signals:
    
public slots:

public:
    QString             m_strMainIp;
    qint16              m_i16MainPort;
    QString             m_strSlaveIp;
    qint16              m_i16SlavePort;
    
};

#endif // INI_PARAM_STATIC_NETWORK_H
