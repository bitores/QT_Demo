#ifndef XML_PARAM_DEV_H
#define XML_PARAM_DEV_H

#include <QObject>

class CXPDev : public QObject
{
    Q_OBJECT
public:
    explicit CXPDev(QObject *parent = 0);
    ~CXPDev();

    //拷贝构造函数
    CXPDev(const CXPDev& src);
    //拷贝赋值函数
    CXPDev& operator=(const CXPDev& src);

public:
    QString GetDevID();
    void SetDevID(const QString& strDevID);

    qint32 GetLinkMode();
    void SetLinkMode(qint32 i32LinkMode);
    
signals:
    
public slots:

private:
    QString             m_strDevID;             //设备id
    qint32              m_i32LinkMode;          //联网模式
    
};

#endif // XML_PARAM_DEV_H
