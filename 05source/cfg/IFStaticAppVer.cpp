#include "IFStaticAppVer.h"

#include <QtCore/qcoreapplication.h>

CIFStaticAppVer::CIFStaticAppVer(QObject *parent) :
    CIFBase(parent)
{
}

CIFStaticAppVer::~CIFStaticAppVer()
{

}

//拷贝构造函数
CIFStaticAppVer::CIFStaticAppVer(const CIFStaticAppVer& src)
{
    if (this == &src)
    {
        return;
    }

    m_AppVer = src.m_AppVer;
}

//拷贝赋值函数
CIFStaticAppVer& CIFStaticAppVer::operator=(const CIFStaticAppVer& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_AppVer = src.m_AppVer;

    return *this;
}

CIPStaticAppVer CIFStaticAppVer::GetAppVer()
{
    return m_AppVer;
}

void CIFStaticAppVer::SetAppVer(const CIPStaticAppVer& AppVer)
{
    m_AppVer = AppVer;
}

int CIFStaticAppVer::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/static_app_ver.ini";
    }

    return 1;
}

int CIFStaticAppVer::ReadData(QSettings& set)
{
    set.beginGroup("APP_VER");
    m_AppVer.SetCurNum(set.value("cur_num").toInt());
    m_AppVer.SetFortuna(set.value("fortuna").toString());
    m_AppVer.SetNotein(set.value("notein").toString());
    m_AppVer.SetNoteout(set.value("noteout").toString());
    m_AppVer.SetCoinin(set.value("coinin").toString());
    m_AppVer.SetCoinout(set.value("coinout").toString());
    m_AppVer.SetStamping(set.value("stamping").toString());
    m_AppVer.SetScanner(set.value("scanner").toString());
    m_AppVer.SetUps(set.value("ups").toString());
    m_AppVer.SetLotbox(set.value("lotbox").toString());
    m_AppVer.SetCamera(set.value("camera").toString());
    set.endGroup();

    return 1;
}

int CIFStaticAppVer::WriteData(QSettings& set)
{
    set.beginGroup("APP_VER");
    set.setValue("cur_num", m_AppVer.GetCurNum());
    set.setValue("fortuna", m_AppVer.GetFortuna());
    set.setValue("notein", m_AppVer.GetNotein());
    set.setValue("noteout", m_AppVer.GetNoteout());
    set.setValue("coinin", m_AppVer.GetCoinin());
    set.setValue("coinout", m_AppVer.GetCoinout());
    set.setValue("stamping", m_AppVer.GetStamping());
    set.setValue("scanner", m_AppVer.GetScanner());
    set.setValue("ups", m_AppVer.GetUps());
    set.setValue("lotbox", m_AppVer.GetLotbox());
    set.setValue("camera", m_AppVer.GetCamera());
    set.endGroup();

    return 1;
}

void CIFStaticAppVer::Clear()
{
    m_AppVer.Clear();
}
