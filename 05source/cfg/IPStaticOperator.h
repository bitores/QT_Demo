#ifndef INI_PARAM_STATIC_OPERATOR_H
#define INI_PARAM_STATIC_OPERATOR_H

#include <QObject>

class CIPStaticOperator : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticOperator(QObject *parent = 0);
    ~CIPStaticOperator();

    //拷贝构造函数
    CIPStaticOperator(const CIPStaticOperator& src);
    //拷贝赋值函数
    CIPStaticOperator& operator=(const CIPStaticOperator& src);

public:
    QString GetID() const;
    void SetID(const QString& strID);

    QString GetName() const;
    void SetName(const QString& strName);

    QString GetMobile() const;
    void SetMobile(const QString& strMobile);

    QString GetTel() const;
    void SetTel(const QString& strTel);

    void Clear();
    
signals:
    
public slots:

public:
    QString             m_strID;                //维护员ID
    QString             m_strName;              //维护员名称
    QString             m_strMobile;            //维护员手机
    QString             m_strTel;               //维护员电话
    
};

#endif // INI_PARAM_STATIC_OPERATOR_H
