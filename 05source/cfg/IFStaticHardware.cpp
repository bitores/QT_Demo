#include "IFStaticHardware.h"

#include <QtCore/qcoreapplication.h>

CIFStaticHardware::CIFStaticHardware(QObject *parent) :
    CIFBase(parent)
{
}

CIFStaticHardware::~CIFStaticHardware()
{

}

//拷贝构造函数
CIFStaticHardware::CIFStaticHardware(const CIFStaticHardware& src)
{
    if (this == &src)
    {
        return;
    }

    m_Hardware = src.m_Hardware;
}

//拷贝赋值函数
CIFStaticHardware& CIFStaticHardware::operator=(const CIFStaticHardware& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_Hardware = src.m_Hardware;

    return *this;
}

CIPStaticHardware CIFStaticHardware::GetHardware()
{
    return m_Hardware;
}

void CIFStaticHardware::SetHardware(const CIPStaticHardware& Hardware)
{
    m_Hardware = Hardware;
}

int CIFStaticHardware::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/static_hardware.ini";
    }

    return 1;
}

int CIFStaticHardware::ReadData(QSettings& set)
{
    set.beginGroup("HARDWARE");
    m_Hardware.SetDiskNo(set.value("disk_no").toString());
    m_Hardware.SetMac(set.value("mac").toString());
//    m_Hardware.SetDevID(set.value("dev_id").toString());
    set.endGroup();

    return 1;
}

int CIFStaticHardware::WriteData(QSettings& set)
{
    set.beginGroup("HARDWARE");
    set.setValue("disk_no", m_Hardware.GetDiskNo());
    set.setValue("mac", m_Hardware.GetMac());
//    set.setValue("dev_id", m_Hardware.GetDevID());
    set.endGroup();

    return 1;
}

void CIFStaticHardware::Clear()
{
    m_Hardware.Clear();
}
