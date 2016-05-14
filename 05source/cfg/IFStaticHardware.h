#ifndef INI_FILE_STATIC_HARDWARE_H
#define INI_FILE_STATIC_HARDWARE_H

#include "IFBase.h"
#include "IPStaticHardware.h"

class CIFStaticHardware : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStaticHardware(QObject *parent = 0);
    ~CIFStaticHardware();

    //拷贝构造函数
    CIFStaticHardware(const CIFStaticHardware& src);
    //拷贝赋值函数
    CIFStaticHardware& operator=(const CIFStaticHardware& src);

public:
    CIPStaticHardware GetHardware();
    void SetHardware(const CIPStaticHardware& Hardware);

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();
    
signals:
    
public slots:

public:
    CIPStaticHardware     m_Hardware;               //程序版本的信息
    
};

#endif // INI_FILE_STATIC_HARDWARE_H
