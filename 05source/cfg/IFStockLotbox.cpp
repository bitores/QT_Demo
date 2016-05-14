#include "IFStockLotbox.h"

#include <QtCore/qcoreapplication.h>

CIFStockLotbox::CIFStockLotbox(QObject *parent) :
    CIFBase(parent)
{
}

CIFStockLotbox::~CIFStockLotbox()
{

}

//拷贝构造函数
CIFStockLotbox::CIFStockLotbox(const CIFStockLotbox& src)
{
    if (this == &src)
    {
        return;
    }

    m_Lotbox = src.m_Lotbox;
    m_lstBoxList = src.m_lstBoxList;
}

//拷贝赋值函数
CIFStockLotbox& CIFStockLotbox::operator=(const CIFStockLotbox& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_Lotbox = src.m_Lotbox;
    m_lstBoxList = src.m_lstBoxList;

    return *this;
}

CIPStockLotbox CIFStockLotbox::GetLotbox()
{
    return m_Lotbox;
}

void CIFStockLotbox::SetLotbox(const CIPStockLotbox& lotbox)
{
    m_Lotbox = lotbox;
}

QList<CIPStockLotboxBox> CIFStockLotbox::GetBoxList()
{
    return m_lstBoxList;
}

void CIFStockLotbox::SetBoxList(const QList<CIPStockLotboxBox>& lstBoxList)
{
    m_lstBoxList = lstBoxList;
}

/*
*@brief             获取票箱库存信息
*@param     in|out  dest            要获取的票箱库存信息
*@param     in      i32BoxIndex     票箱序号
*@retval            true            获取成功
*@retval            false           获取失败
*/
bool CIFStockLotbox::GetBox(CIPStockLotboxBox& dest, qint32 i32BoxIndex) const
{
    if (i32BoxIndex < 0 || i32BoxIndex >= m_lstBoxList.count())
    {
        return false;
    }

    dest = m_lstBoxList.at(i32BoxIndex);

    return true;
}

int CIFStockLotbox::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/stock_lotbox.ini";
    }

    return 1;
}

int CIFStockLotbox::ReadData(QSettings& set)
{
    set.beginGroup("LOTBOX");
    m_Lotbox.SetBoxNum(set.value("box_num").toInt());
    m_Lotbox.SetAllNum( set.value("all_num").toInt());
    m_Lotbox.SetAllSum(set.value("all_sum").toInt());
    m_Lotbox.SetMinFace(set.value("min_face").toInt());
    m_Lotbox.SetMaxFace(set.value("max_face").toInt());
    set.endGroup();

    for (int i=0;i<m_Lotbox.GetBoxNum();i++)
    {
        ReadBox(set, i);
    }

    return 1;
}

int CIFStockLotbox::WriteData(QSettings& set)
{
    qint32 i32AllNum = 0;
    for (int i=0;i<m_Lotbox.GetBoxNum();i++)
    {
        WriteBox(set, i);
        i32AllNum += m_lstBoxList.at(i).GetCurNum();
    }
    m_Lotbox.SetAllNum(i32AllNum);

    set.beginGroup("LOTBOX");
    set.setValue("box_num", m_Lotbox.GetBoxNum());
    set.setValue("all_num", m_Lotbox.GetAllNum());
    set.setValue("all_sum", m_Lotbox.GetAllSum());
    set.setValue("min_face", m_Lotbox.GetMinFace());
    set.setValue("max_face", m_Lotbox.GetMaxFace());
    set.endGroup();

    return 1;
}

int CIFStockLotbox::ReadBox(QSettings& set, qint32 i32Index)
{
    CIPStockLotboxBox box;

    set.beginGroup(QString("BOX_%1").arg(QString::number(i32Index).rightJustified(3, '0',true)));
    box.SetCurNum(set.value("cur_num").toInt());
    set.endGroup();

    m_lstBoxList.append(box);

    return 1;
}

int CIFStockLotbox::WriteBox(QSettings& set, qint32 i32Index)
{
    set.beginGroup(QString("BOX_%1").arg(QString::number(i32Index).rightJustified(3, '0',true)));
    set.setValue("cur_num", m_lstBoxList.at(i32Index).GetCurNum());
    set.endGroup();

    return 1;
}

void CIFStockLotbox::Clear()
{
    m_Lotbox.Clear();
    m_lstBoxList.clear();
}
