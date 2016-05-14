#include "Cfg.h"
#include "trace.h"
#include "DefineFortuna.h"
#include <QtCore/qcoreapplication.h>

CCfg* CCfg::Instance()
{
    if (NULL == sm_pInstance)
    {
        sm_pInstance = new CCfg();
    }

    return sm_pInstance;
}

void CCfg::Release()
{
    if (NULL != sm_pInstance)
    {
        delete sm_pInstance;
        sm_pInstance = NULL;
    }
}

CCfg* CCfg::sm_pInstance = NULL;


CCfg::CCfg(QObject *parent) :
    QObject(parent)
{
}

CCfg::~CCfg()
{

}

//拷贝构造函数
CCfg::CCfg(const CCfg& src)
{
    if (this == &src)
    {
        return;
    }

    m_AppVer = src.m_AppVer;
    m_Com = src.m_Com;
    m_Fortuna = src.m_Fortuna;
    m_Lot = src.m_Lot;
    m_Hardware = src.m_Hardware;
    m_Coiner = src.m_Coiner;
    m_Lotbox = src.m_Lotbox;
    m_Notein = src.m_Notein;
    m_Noteout = src.m_Noteout;
    m_Seq = src.m_Seq;
    m_Redeembox = src.m_Redeembox;
}

//拷贝赋值函数
CCfg& CCfg::operator=(const CCfg& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_AppVer = src.m_AppVer;
    m_Com = src.m_Com;
    m_Fortuna = src.m_Fortuna;
    m_Lot = src.m_Lot;
    m_Hardware = src.m_Hardware;
    m_Coiner = src.m_Coiner;
    m_Lotbox = src.m_Lotbox;
    m_Notein = src.m_Notein;
    m_Noteout = src.m_Noteout;
    m_Seq = src.m_Seq;
    m_Redeembox = src.m_Redeembox;

    return *this;
}

int CCfg::Read()
{
    QString strPath = QCoreApplication::applicationDirPath();
    //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
    strPath = strPath.left(strPath.size()-4);
    QString strFile = "";

    strFile = strPath + "/cfg/static_fortuna.ini";
    if(1 != m_Fortuna.Read(strFile))
    {
        return -1;
    }
    trcSetDevID(CCfg::Instance()->GetFortuna().GetDev().GetDevID());
    trcSetLogType(LOG_TYPE_FORTUNA);

    strFile = strPath + "/cfg/static_app_ver.ini";
    if(1 != m_AppVer.Read(strFile))
    {
        return -1;
    }

    strFile = strPath + "/cfg/static_com.ini";
    if(1 != m_Com.Read(strFile))
    {
        return -1;
    }

    strFile = strPath + "/cfg/static_lot.ini";
    if(1 != m_Lot.Read(strFile))
    {
        return -1;
    }

    strFile = strPath + "/cfg/static_hardware.ini";
    if(1 != m_Hardware.Read(strFile))
    {
        return -1;
    }

    strFile = strPath + "/cfg/stock_coiner.ini";
    if(1 != m_Coiner.Read(strFile))
    {
        return -1;
    }

    strFile = strPath + "/cfg/stock_notein.ini";
    if(1 != m_Notein.Read(strFile))
    {
        return -1;
    }

    strFile = strPath + "/cfg/stock_noteout.ini";
    if(1 != m_Noteout.Read(strFile))
    {
        return -1;
    }

    strFile = strPath + "/cfg/stock_seq.ini";
    if(1 != m_Seq.Read(strFile))
    {
        return -1;
    }

    strFile = strPath + "/cfg/stock_lotbox.ini";
    if(1 != m_Lotbox.Read(strFile))
    {
        return -1;
    }

    strFile = strPath + "/cfg/stock_redeembox.ini";
    if(1 != m_Redeembox.Read(strFile))
    {
        return -1;
    }

    return 1;
}

int CCfg::Write()
{
    m_AppVer.Write();
    m_Com.Write();
    m_Fortuna.Write();
    m_Lot.Write();
    m_Hardware.Write();
    m_Coiner.Write();
    m_Notein.Write();
    m_Noteout.Write();
    m_Seq.Write();
    m_Redeembox.Write();

    return 1;
}

CIFStaticAppVer CCfg::GetAppVer() const
{
    return m_AppVer;
}

void CCfg::SetAppVer(const CIFStaticAppVer& AppVer)
{
    m_AppVer = AppVer;
}

CIFStaticCom CCfg::GetCom() const
{
    return m_Com;
}
void CCfg::SetCom(CIFStaticCom& Com)
{
    m_Com = Com;
}

CIFStaticFortuna CCfg::GetFortuna() const
{
    return m_Fortuna;
}
void CCfg::SetFortuna(const CIFStaticFortuna& Fortuna)
{
    m_Fortuna = Fortuna;
}

CIFStaticLot CCfg::GetLot() const
{
    return m_Lot;
}
void CCfg::SetLot(CIFStaticLot& Lot)
{
    m_Lot = Lot;
}

CIFStaticHardware CCfg::GetHardware() const
{
    return m_Hardware;
}

void CCfg::SetHardware(const CIFStaticHardware& Hardware)
{
    m_Hardware = Hardware;
}

CIFStockCoiner CCfg::GetCoiner() const
{
    return m_Coiner;
}
void CCfg::SetCoiner(const CIFStockCoiner& Coiner)
{
    m_Coiner = Coiner;
}

CIFStockLotbox CCfg::GetLotbox() const
{
    return m_Lotbox;
}
void CCfg::SetLotbox(const CIFStockLotbox& Lotbox)
{
    m_Lotbox = Lotbox;
}

CIFStockNotein CCfg::GetNotein() const
{
    return m_Notein;
}
void CCfg::SetNotein(const CIFStockNotein& Notein)
{
    m_Notein = Notein;
}

CIFStockNoteout CCfg::GetNoteout() const
{
    return m_Noteout;
}
void CCfg::SetNoteout(const CIFStockNoteout& Noteout)
{
    m_Noteout = Noteout;
}

CIFStockSeq CCfg::GetSeq() const
{
    return m_Seq;
}
void CCfg::SetSeq(const CIFStockSeq& Seq)
{
    m_Seq = Seq;
}

CIFStockRedeembox CCfg::GetRedeembox() const
{
    return m_Redeembox;
}

void CCfg::SetRedeembox(const CIFStockRedeembox& redeembox)
{
    m_Redeembox = redeembox;
}
