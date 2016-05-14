#ifndef INI_PARAM_STATIC_COMPANY_H
#define INI_PARAM_STATIC_COMPANY_H

#include <QObject>

class CIPStaticCompany : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticCompany(QObject *parent = 0);
    ~CIPStaticCompany();

    //拷贝构造函数
    CIPStaticCompany(const CIPStaticCompany& src);
    //拷贝赋值函数
    CIPStaticCompany& operator=(const CIPStaticCompany& src);

public:
    QString GetName() const;
    void SetName(const QString& strName);

    QString GetHotline() const;
    void SetHotline(const QString& strHotline);

    void Clear();
    
signals:
    
public slots:

public:
    QString             m_strName;              //公司名称
    QString             m_strHotLine;           //公司热线
    
};

#endif // INI_PARAM_STATIC_COMPANY_H
