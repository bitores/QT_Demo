#ifndef INI_PARAM_STATIC_FTP_H
#define INI_PARAM_STATIC_FTP_H

#include <QObject>

class CIPStaticFtp : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticFtp(QObject *parent = 0);
    ~CIPStaticFtp();

    //拷贝构造函数
    CIPStaticFtp(const CIPStaticFtp& src);
    //拷贝赋值函数
    CIPStaticFtp& operator=(const CIPStaticFtp& src);

public:
    QString GetIp() const;
    void SetIp(const QString& strIp);

    qint16 GetPort() const;
    void SetPort(qint16 i16Port);

    QString GetUser() const;
    void SetUser(const QString& strUser);

    QString GetPassword() const;
    void SetPassword(const QString& strPassword);

    void Clear();

    
signals:
    
public slots:

public:
    QString             m_strIp;
    qint16              m_i16Port;
    QString             m_strUser;
    QString             m_strPassword;
    
};

#endif // INI_PARAM_STATIC_FTP_H
