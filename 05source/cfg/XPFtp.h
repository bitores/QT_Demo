#ifndef XML_PARAM_FTP_H
#define XML_PARAM_FTP_H

#include <QObject>

class CXPFtp : public QObject
{
    Q_OBJECT
public:
    explicit CXPFtp(QObject *parent = 0);
    ~CXPFtp();

    //拷贝构造函数
    CXPFtp(const CXPFtp& src);
    //拷贝赋值函数
    CXPFtp& operator=(const CXPFtp& src);

public:
    QString GetIp();
    void SetIp(const QString& strIp);

    qint16 GetPort();
    void SetPort(qint16 i16Port);

    QString GetUser();
    void SetUser(const QString& strUser);

    QString GetPassword();
    void SetPassword(const QString& strPassword);

    
signals:
    
public slots:

private:
    QString             m_strIp;
    qint16              m_i16Port;
    QString             m_strUser;
    QString             m_strPassword;
    
};

#endif // XML_PARAM_FTP_H
