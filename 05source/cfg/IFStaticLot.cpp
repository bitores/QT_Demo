#include "IFStaticLot.h"

#include <QtCore/qcoreapplication.h>

CIFStaticLot::CIFStaticLot(QObject *parent) :
    CIFBase(parent)
{
}

CIFStaticLot::~CIFStaticLot()
{

}

//拷贝构造函数
CIFStaticLot::CIFStaticLot(const CIFStaticLot& src)
{
    if (this == &src)
    {
        return;
    }

    m_LotInfo = src.m_LotInfo;
    m_lstLotList = src.m_lstLotList;
}

//拷贝赋值函数
CIFStaticLot& CIFStaticLot::operator=(const CIFStaticLot& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_LotInfo = src.m_LotInfo;
    m_lstLotList = src.m_lstLotList;

    return *this;
}

CIPStaticLotInfo CIFStaticLot::GetLotInfo()
{
    return m_LotInfo;
}

void CIFStaticLot::SetLotInfo(const CIPStaticLotInfo& lotInfo)
{
    m_LotInfo = lotInfo;
}

QList<CIPStaticLot> CIFStaticLot::GetLotList()
{
    return m_lstLotList;
}

void CIFStaticLot::SetLotList(const QList<CIPStaticLot>& lstLotList)
{
    m_lstLotList = lstLotList;
}

/*
*@brief     通过彩票类型ID获取彩票信息
*@param[in|out]     dest            要获取的彩票信息
*@param[in]     strLotTypeID        彩票类型ID
*@retval            true            获取成功
*@retval            false           获取失败
*/
bool CIFStaticLot::GetLotById(CIPStaticLot& dest, const QString& strLotTypeID)
{
    foreach (CIPStaticLot lot, m_lstLotList)
    {
        if (lot.GetLotTypeID() == strLotTypeID)
        {
            dest = lot;
            return true;
        }
    }

    return false;
}

/*
*@brief     通过彩票名称获取彩票信息
*@param[in|out]     dest            要获取的彩票信息
*@param[in]         strLotTypeName  彩票类型名称
*@retval            true            获取成功
*@retval            false           获取失败
*/
bool CIFStaticLot::GetLotByName(CIPStaticLot& dest, const QString& strLotTypeName)
{
    foreach (CIPStaticLot lot, m_lstLotList)
    {
        if (lot.GetName() == strLotTypeName)
        {
            dest = lot;
            return true;
        }
    }

    return false;
}

/*
*@brief             获取彩票信息
*@param     in|out  dest            要获取的彩票信息
*@param     in      strLotTypeID    彩票类型ID
*@retval            true            获取成功
*@retval            false           获取失败
*/
bool CIFStaticLot::GetLot(CIPStaticLot& dest, const QString& strLotTypeID)
{
    foreach (CIPStaticLot lot, m_lstLotList)
    {
        if (strLotTypeID == lot.GetLotTypeID())
        {
            dest = lot;
            return true;
        }
    }

    return false;
}

int CIFStaticLot::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/static_lot.ini";
    }

    return 1;
}

int CIFStaticLot::ReadData(QSettings& set)
{
    set.beginGroup("LOT_INFO");
    m_LotInfo.SetAllNum(set.value("all_num").toInt());
    m_LotInfo.SetMaxFace(set.value("max_face").toInt());
    m_LotInfo.SetMinFace(set.value("min_face").toInt());
    set.endGroup();

    for (int i=0;i<m_LotInfo.GetAllNum();i++)
    {
        ReadLot(set, i);
    }

    return 1;
}

int CIFStaticLot::WriteData(QSettings& set)
{
    set.beginGroup("LOT_INFO");
    set.setValue("all_num", m_LotInfo.GetAllNum());
    set.setValue("max_face", m_LotInfo.GetMaxFace());
    set.setValue("min_face", m_LotInfo.GetMinFace());
    set.endGroup();

    for (int i=0;i<m_LotInfo.GetAllNum();i++)
    {
        WriteLot(set, i);
    }

    return 1;
}

void CIFStaticLot::Clear()
{
    m_LotInfo.Clear();
    m_lstLotList.clear();
}

int CIFStaticLot::ReadLot(QSettings& set, qint32 i32Index)
{
    CIPStaticLot lot;

    set.beginGroup(QString("LOT_%1").arg(QString::number(i32Index).rightJustified(3, '0',true)));
    lot.SetLotTypeID(set.value("lot_type_id").toString());
    lot.SetName(set.value("name").toString());
    lot.SetFace(set.value("face").toInt());
    lot.SetFaceName(set.value("face_name").toString());
    lot.SetHighestBonus(set.value("highest_bonus").toInt());
    lot.SetLotLen(set.value("lot_len").toInt());
    lot.SetRate(set.value("rate").toString());
    lot.SetLotPhoto(set.value("lot_photo").toString());
    lot.SetDescribeIco(set.value("describe_ico").toString());
    lot.SetDescribeText(set.value("describe_text").toString());
    set.endGroup();

    m_lstLotList.append(lot);

    return 1;
}

int CIFStaticLot::WriteLot(QSettings& set, qint32 i32Index)
{
    set.beginGroup(QString("LOT_%1").arg(QString::number(i32Index).rightJustified(3, '0',true)));
    set.setValue("lot_type_id", m_lstLotList.at(i32Index).GetLotTypeID());
    set.setValue("name", m_lstLotList.at(i32Index).GetName());
    set.setValue("face", m_lstLotList.at(i32Index).GetFace());
    set.setValue("face_name", m_lstLotList.at(i32Index).GetFaceName());
    set.setValue("highest_bonus", m_lstLotList.at(i32Index).GetHighestBonus());
    set.setValue("lot_len", m_lstLotList.at(i32Index).GetLotLen());
    set.setValue("rate", m_lstLotList.at(i32Index).GetRate());
    set.setValue("lot_photo", m_lstLotList.at(i32Index).GetLotPhoto());
    set.setValue("describe_ico", m_lstLotList.at(i32Index).GetDescribeIco());
    set.setValue("describe_text", m_lstLotList.at(i32Index).GetDescribeText());
    set.endGroup();

    return 1;
}
