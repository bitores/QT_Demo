#ifndef XML_PARAM_NETWORK_H
#define XML_PARAM_NETWORK_H

#include <QObject>

class CXPNetwork : public QObject
{
    Q_OBJECT
public:
    explicit CXPNetwork(QObject *parent = 0);
    ~CXPNetwork();

    //拷贝构造函数
    CXPNetwork(const CXPNetwork& src);
    //拷贝赋值函数
    CXPNetwork& operator=(const CXPNetwork& src);

public:
    QString GetMainIp();
    void SetMainIp(const QString& strMainIp);

    qint16 GetMainPort();
    void SetMainPort(qint16 i16MainPort);

    QString GetSlaveIp();
    void SetSlaveIp(const QString& strSlaveIp);

    qint16 GetSlavePort();
    void SetSlavePort(qint16 i16SlavePort);
    
signals:
    
public slots:

private:
    QString             m_strMainIp;
    qint16              m_i16MainPort;
    QString             m_strSlaveIp;
    qint16              m_i16SlavePort;
    
};

#endif // XML_PARAM_NETWORK_H
