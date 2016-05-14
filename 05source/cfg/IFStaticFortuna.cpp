#include "IFStaticFortuna.h"

#include <QtCore/qcoreapplication.h>

CIFStaticFortuna::CIFStaticFortuna(QObject *parent) :
    CIFBase(parent)
{
}

CIFStaticFortuna::~CIFStaticFortuna()
{

}

//拷贝构造函数
CIFStaticFortuna::CIFStaticFortuna(const CIFStaticFortuna& src)
{
    if (this == &src)
    {
        return;
    }

    m_Dev = src.m_Dev;
    m_Company = src.m_Company;
    m_Operator = src.m_Operator;
    m_Network = src.m_Network;
    m_Ftp = src.m_Ftp;
    m_Lotbox = src.m_Lotbox;
    m_Prize = src.m_Prize;
    m_Notein = src.m_Notein;
    m_Noteout = src.m_Noteout;
    m_Coiner = src.m_Coiner;
    m_Timer = src.m_Timer;
    m_Ups = src.m_Ups;
    m_Redeembox = src.m_Redeembox;
}

//拷贝赋值函数
CIFStaticFortuna& CIFStaticFortuna::operator=(const CIFStaticFortuna& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_Dev = src.m_Dev;
    m_Company = src.m_Company;
    m_Operator = src.m_Operator;
    m_Network = src.m_Network;
    m_Ftp = src.m_Ftp;
    m_Lotbox = src.m_Lotbox;
    m_Prize = src.m_Prize;
    m_Notein = src.m_Notein;
    m_Noteout = src.m_Noteout;
    m_Coiner = src.m_Coiner;
    m_Timer = src.m_Timer;
    m_Ups = src.m_Ups;
    m_Redeembox = src.m_Redeembox;

    return *this;
}

CIPStaticDev CIFStaticFortuna::GetDev()
{
    return m_Dev;
}

void CIFStaticFortuna::SetDev(const CIPStaticDev& dev)
{
    m_Dev = dev;
}

CIPStaticCompany CIFStaticFortuna::GetCompany()
{
    return m_Company;
}

void CIFStaticFortuna::SetCompany(const CIPStaticCompany& company)
{
    m_Company = company;
}

CIPStaticOperator CIFStaticFortuna::GetOperator()
{
    return m_Operator;
}

void CIFStaticFortuna::SetOperator(const CIPStaticOperator& src)
{
    m_Operator = src;
}

CIPStaticNetwork CIFStaticFortuna::GetNetwork()
{
    return m_Network;
}

void CIFStaticFortuna::SetNetwork(const CIPStaticNetwork& network)
{
    m_Network = network;
}

CIPStaticFtp CIFStaticFortuna::GetFtp()
{
    return m_Ftp;
}

void CIFStaticFortuna::SetFtp(const CIPStaticFtp& ftp)
{
    m_Ftp = ftp;
}

CIPStaticLotbox CIFStaticFortuna::GetLotbox()
{
    return m_Lotbox;
}

void CIFStaticFortuna::SetLotbox(const CIPStaticLotbox& lotbox)
{
    m_Lotbox = lotbox;
}

CIPStaticPrize CIFStaticFortuna::GetPrize()
{
    return m_Prize;
}

void CIFStaticFortuna::SetPrize(const CIPStaticPrize& prize)
{
    m_Prize = prize;
}

CIPStaticNotein CIFStaticFortuna::GetNotein()
{
    return m_Notein;
}

void CIFStaticFortuna::SetNotein(const CIPStaticNotein& notein)
{
    m_Notein = notein;
}

CIPStaticNoteout CIFStaticFortuna::GetNoteout()
{
    return m_Noteout;
}

void CIFStaticFortuna::SetNoteout(const CIPStaticNoteout& noteout)
{
    m_Noteout = noteout;
}

CIPStaticCoiner CIFStaticFortuna::GetCoiner()
{
    return m_Coiner;
}

void CIFStaticFortuna::SetCoiner(const CIPStaticCoiner& coiner)
{
    m_Coiner = coiner;
}

CIPStaticTimer CIFStaticFortuna::GetTimer()
{
    return m_Timer;
}

void CIFStaticFortuna::SetTimer(const CIPStaticTimer& timer)
{
    m_Timer = timer;
}

CIPStaticUps CIFStaticFortuna::GetUps()
{
    return m_Ups;
}

void CIFStaticFortuna::SetUps(const CIPStaticUps& ups)
{
    m_Ups = ups;
}

CIPStaticRedeembox CIFStaticFortuna::GetRedeembox()
{
    return m_Redeembox;
}

void CIFStaticFortuna::SetRedeembox(const CIPStaticRedeembox& redeembox)
{
    m_Redeembox = redeembox;
}

int CIFStaticFortuna::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/static_fortuna.ini";
    }

    return 1;
}

int CIFStaticFortuna::ReadData(QSettings& set)
{
    ReadDev(set);
    ReadCompany(set);
    ReadOperator(set);
    ReadNetwork(set);
    ReadFtp(set);
    ReadLotbox(set);
    ReadPrize(set);
    ReadNotein(set);
    ReadNoteout(set);
    ReadCoiner(set);
    ReadTimer(set);
    ReadUps(set);
    ReadRedeembox(set);

    return 1;
}

int CIFStaticFortuna::WriteData(QSettings& set)
{
    WriteDev(set);
    WriteCompany(set);
    WriteOperator(set);
    WriteNetwork(set);
    WriteFtp(set);
    WriteLotbox(set);
    WritePrize(set);
    WriteNotein(set);
    WriteNoteout(set);
    WriteCoiner(set);
    WriteTimer(set);
    WriteUps(set);
    WriteRedeembox(set);

    return 1;
}

void CIFStaticFortuna::Clear()
{
    m_Dev.Clear();
    m_Company.Clear();
    m_Operator.Clear();
    m_Network.Clear();
    m_Ftp.Clear();
    m_Lotbox.Clear();
    m_Prize.Clear();
    m_Notein.Clear();
    m_Noteout.Clear();
    m_Coiner.Clear();
    m_Timer.Clear();
    m_Ups.Clear();
    m_Redeembox.Clear();
}

int CIFStaticFortuna::ReadDev(QSettings& set)
{
    set.beginGroup("DEV");
    m_Dev.SetDevType(set.value("dev_type").toString());
    m_Dev.SetDevID(set.value("dev_id").toString());
    m_Dev.SetStationID(set.value("station_id").toString());
    m_Dev.SetInitMsleep(set.value("init_msleep").toUInt());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteDev(QSettings& set)
{
    set.beginGroup("DEV");
    set.setValue("dev_type", m_Dev.GetDevType());
    set.setValue("dev_id", m_Dev.GetDevID());
    set.setValue("station_id", m_Dev.GetStationID());
    set.setValue("init_msleep", m_Dev.GetInitMsleep());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadCompany(QSettings& set)
{
    set.beginGroup("COMPANY");
    m_Company.SetName(set.value("name").toString());
    m_Company.SetHotline(set.value("hot_line").toString());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteCompany(QSettings& set)
{
    set.beginGroup("COMPANY");
    set.setValue("name", m_Company.GetName());
    set.setValue("hot_line", m_Company.GetHotline());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadOperator(QSettings& set)
{
    set.beginGroup("OPERATOR");
    m_Operator.SetID(set.value("id").toString());
    m_Operator.SetName(set.value("name").toString());
    m_Operator.SetMobile(set.value("mobile").toString());
    m_Operator.SetTel(set.value("tel").toString());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteOperator(QSettings& set)
{
    set.beginGroup("OPERATOR");
    set.setValue("id", m_Operator.GetID());
    set.setValue("name", m_Operator.GetName());
    set.setValue("mobile", m_Operator.GetMobile());
    set.setValue("tel", m_Operator.GetTel());
    set.endGroup();

    return 1;

}

int CIFStaticFortuna::ReadNetwork(QSettings& set)
{
    set.beginGroup("NETWORK");
    m_Network.SetMainIp(set.value("main_ip").toString());
    m_Network.SetMainPort((qint16)set.value("main_port").toInt());
    m_Network.SetSlaveIp(set.value("slave_ip").toString());
    m_Network.SetSlavePort((qint16)set.value("slave_port").toInt());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteNetwork(QSettings& set)
{
    set.beginGroup("NETWORK");
    set.setValue("main_ip", m_Network.GetMainIp());
    set.setValue("main_port", m_Network.GetMainPort());
    set.setValue("slave_ip", m_Network.GetSlaveIp());
    set.setValue("slave_port", m_Network.GetSlavePort());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadFtp(QSettings& set)
{
    set.beginGroup("FTP");
    m_Ftp.SetIp(set.value("ip").toString());
    m_Ftp.SetPort((qint16)set.value("port").toInt());
    m_Ftp.SetUser(set.value("user").toString());
    m_Ftp.SetPassword(set.value("password").toString());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteFtp(QSettings& set)
{
    set.beginGroup("FTP");
    set.setValue("ip", m_Ftp.GetIp());
    set.setValue("port", m_Ftp.GetPort());
    set.setValue("user", m_Ftp.GetUser());
    set.setValue("password", m_Ftp.GetPassword());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadLotbox(QSettings& set)
{
    set.beginGroup("LOTBOX");
    m_Lotbox.SetMaxFace(set.value("max_face").toInt());
    m_Lotbox.SetMinFace(set.value("min_face").toInt());
    m_Lotbox.SetMaxNum(set.value("max_num").toInt());
    m_Lotbox.SetMinNum(set.value("min_num").toInt());
    m_Lotbox.SetMaxNote(set.value("max_note").toInt());
    m_Lotbox.SetMinNote(set.value("min_note").toInt());
    m_Lotbox.SetBoxNum(set.value("box_num").toInt());
    m_Lotbox.SetMaxNumOfOnce(set.value("max_num_of_once").toInt());
    m_Lotbox.SetDisable(set.value("disable_list").toString().split(",,"));
    QString strLotTypeID = "";
    QStringList slLotTypeID = m_Lotbox.GetLotTypeID();
    for(int i=0;i<m_Lotbox.GetBoxNum();i++)
    {
        strLotTypeID = set.value(QString("lot_type_id_%1").arg(QString::number(i).rightJustified(3, '0',true))).toString();
        slLotTypeID.append(strLotTypeID);
    }
    m_Lotbox.SetLotTypeID(slLotTypeID);
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteLotbox(QSettings& set)
{
    set.beginGroup("LOTBOX");
    set.setValue("max_face", m_Lotbox.GetMaxFace());
    set.setValue("min_face", m_Lotbox.GetMinFace());
    set.setValue("max_num", m_Lotbox.GetMaxNum());
    set.setValue("min_num", m_Lotbox.GetMinNum());
    set.setValue("max_note", m_Lotbox.GetMaxNote());
    set.setValue("min_note", m_Lotbox.GetMinNote());
    set.setValue("box_num", m_Lotbox.GetLotTypeID().count());
    set.setValue("max_num_of_once", m_Lotbox.GetMaxNumOfOnce());

    QString strDisable = "";
    if (2 == m_Lotbox.GetDisable().size())
    {
        strDisable = m_Lotbox.GetDisable().at(0) + ",," + m_Lotbox.GetDisable().at(1);
    }
    else if (1 == m_Lotbox.GetDisable().size())
    {
        strDisable = m_Lotbox.GetDisable().at(0);
    }
    set.setValue("disable_list", strDisable);

    for(int i=0;i<m_Lotbox.GetLotTypeID().count();i++)
    {
        set.setValue(QString("lot_type_id_%1").arg(QString::number(i).rightJustified(3, '0',true)), m_Lotbox.GetLotTypeID().at(i));
    }
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadPrize(QSettings& set)
{
    set.beginGroup("PRIZE");
    m_Prize.SetPrizeType(set.value("prize_type").toInt());
    m_Prize.SetMaxSum(set.value("max_sum").toInt());
    m_Prize.SetFilterRedeem(1 == set.value("filter_redeem").toBool());
    m_Prize.SetFlashTime(set.value("flash_time").toInt());
    m_Prize.SetShowTime(set.value("show_time").toInt());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WritePrize(QSettings& set)
{
    set.beginGroup("PRIZE");
    set.setValue("prize_type", m_Prize.GetPrizeType());
    set.setValue("max_sum", m_Prize.GetMaxSum());
    set.setValue("filter_redeem", m_Prize.GetFilterRedeem()?1:0);
    set.setValue("flash_time", m_Prize.GetFlashTime());
    set.setValue("show_time", m_Prize.GetShowTime());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadNotein(QSettings& set)
{
    set.beginGroup("NOTEIN");
    m_Notein.SetFaceList(set.value("face_list").toString().split("_"));
    m_Notein.SetMaxNum(set.value("max_num").toInt());
    m_Notein.SetMinNum(set.value("min_num").toInt());
    m_Notein.SetMaxSum(set.value("max_sum").toInt());
    m_Notein.SetMinSum(set.value("min_sum").toInt());
    m_Notein.SetPerFlag(set.value("per_flag").toBool());
    m_Notein.SetMaxNumOfPer(set.value("max_num_of_per").toInt());
    m_Notein.SetMaxSumOfPer(set.value("max_sum_of_per").toInt());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteNotein(QSettings& set)
{
    set.beginGroup("NOTEIN");
    QString strFaceList = "";
    for(int i=0;i<m_Notein.GetFaceList().count();i++)
    {
        strFaceList += "_" + m_Notein.GetFaceList().at(i);
    }
    //剔除首个"_"
    strFaceList = strFaceList.mid(1);
    set.setValue("face_list", strFaceList);
    set.setValue("max_num", m_Notein.GetMaxNum());
    set.setValue("min_num", m_Notein.GetMinNum());
    set.setValue("max_sum", m_Notein.GetMaxSum());
    set.setValue("min_sum", m_Notein.GetMinSum());
    set.setValue("per_flag", m_Notein.GetPerFlag()?1:0);
    set.setValue("max_num_of_per", m_Notein.GetMaxNumOfPer());
    set.setValue("max_sum_of_per", m_Notein.GetMaxSumOfPer());

    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadNoteout(QSettings& set)
{
    set.beginGroup("NOTEOUT");
    m_Noteout.SetCurFace(set.value("cur_face").toInt());
    m_Noteout.SetMaxNum(set.value("max_num").toInt());
    m_Noteout.SetMinNum(set.value("min_num").toInt());
    m_Noteout.SetPerFlag(set.value("per_flag").toBool());
    m_Noteout.SetMaxNumOfPer(set.value("max_num_of_per").toInt());
    m_Noteout.SetIntervalOfPer(set.value("interval_of_per").toInt());
    m_Noteout.SetRejectMaxCount(set.value("reject_max_count").toInt());
    m_Noteout.SetRejectTakeRange(set.value("reject_take_range").toInt());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteNoteout(QSettings& set)
{
    set.beginGroup("NOTEOUT");
    set.setValue("cur_face", m_Noteout.GetCurFace());
    set.setValue("max_num", m_Noteout.GetMaxNum());
    set.setValue("min_num", m_Noteout.GetMinNum());
    set.setValue("per_flag", m_Noteout.GetPerFlag()?1:0);
    set.setValue("max_num_of_per", m_Noteout.GetMaxNumOfPer());
    set.setValue("interval_of_per", m_Noteout.GetIntervalOfPer());
    set.setValue("reject_max_count", m_Noteout.GetRejectMaxCount());
    set.setValue("reject_take_range", m_Noteout.GetRejectTakeRange());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadCoiner(QSettings& set)
{
    set.beginGroup("COINER");
    m_Coiner.SetCurFace(set.value("cur_face").toInt());
    m_Coiner.SetMaxNum(set.value("max_num").toInt());
    m_Coiner.SetMinNum(set.value("min_num").toInt());
    m_Coiner.SetPerFlag(set.value("per_flag").toBool());
    m_Coiner.SetMaxInNumOfPer(set.value("max_in_num_of_per").toInt());
    m_Coiner.SetMaxOutNumOfPer(set.value("max_out_num_of_per").toInt());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteCoiner(QSettings& set)
{
    set.beginGroup("COINER");
    set.setValue("cur_face", m_Coiner.GetCurFace());
    set.setValue("max_num", m_Coiner.GetMaxNum());
    set.setValue("min_num", m_Coiner.GetMinNum());
    set.setValue("per_flag", m_Coiner.GetPerFlag()?1:0);
    set.setValue("max_in_num_of_per", m_Coiner.GetMaxInNumOfPer());
    set.setValue("max_out_num_of_per", m_Coiner.GetMaxOutNumOfPer());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadTimer(QSettings& set)
{
    set.beginGroup("TIMER");
    m_Timer.SetIntervalOfUpload(set.value("interval_of_upload").toInt());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteTimer(QSettings& set)
{
    set.beginGroup("TIMER");
    set.setValue("interval_of_upload", m_Timer.GetIntervalOfUpload());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadUps(QSettings& set)
{
    set.beginGroup("UPS");
    m_Ups.SetAutoBootFlag(set.value("auto_boot_flag").toBool());
    m_Ups.SetAutoBootTime(set.value("auto_boot_time").toString());
    m_Ups.SetAutoShutdownFlag(set.value("auto_shutdown_flag").toBool());
    m_Ups.SetAutoShutdownTime(set.value("auto_shutdown_time").toString());
    m_Ups.SetResponseTime(set.value("response_time").toInt());
    m_Ups.SetQueryStatusInterval(set.value("query_status_interval").toInt());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteUps(QSettings& set)
{
    set.beginGroup("UPS");
    set.setValue("auto_boot_flag", m_Ups.GetAutoBootFlag()?1:0);
    set.setValue("auto_boot_time", m_Ups.GetAutoBootTime());
    set.setValue("auto_shutdown_flag", m_Ups.GetAutoShutdownFlag()?1:0);
    set.setValue("auto_shutdown_time", m_Ups.GetAutoShutdownTime());
    set.setValue("response_time", m_Ups.GetResponseTime());
    set.setValue("query_status_interval", m_Ups.GetQueryStatusInterval());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::ReadRedeembox(QSettings& set)
{
    set.beginGroup("REDEEMBOX");
    m_Redeembox.SetMaxNum(set.value("max_num").toInt());
    set.endGroup();

    return 1;
}

int CIFStaticFortuna::WriteRedeembox(QSettings& set)
{
    set.beginGroup("REDEEMBOX");
    set.setValue("max_num", m_Redeembox.GetMaxNum());
    set.endGroup();

    return 1;
}
