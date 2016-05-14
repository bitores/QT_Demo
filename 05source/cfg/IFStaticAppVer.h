#ifndef INI_FILE_STATIC_APP_VER_H
#define INI_FILE_STATIC_APP_VER_H

#include "IFBase.h"
#include "IPStaticAppVer.h"

class CIFStaticAppVer : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStaticAppVer(QObject *parent = 0);
    ~CIFStaticAppVer();

    //拷贝构造函数
    CIFStaticAppVer(const CIFStaticAppVer& src);
    //拷贝赋值函数
    CIFStaticAppVer& operator=(const CIFStaticAppVer& src);

public:
    CIPStaticAppVer GetAppVer();
    void SetAppVer(const CIPStaticAppVer& AppVer);

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();
    
signals:
    
public slots:

public:
    CIPStaticAppVer     m_AppVer;               //程序版本的信息
    
};

#endif // INI_FILE_STATIC_APP_VER_H
