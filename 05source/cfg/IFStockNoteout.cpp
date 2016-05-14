#include "IFStockNoteout.h"

#include <QtCore/qcoreapplication.h>

CIFStockNoteout::CIFStockNoteout(QObject *parent) :
    CIFBase(parent)
{
}

CIFStockNoteout::~CIFStockNoteout()
{

}

//拷贝构造函数
CIFStockNoteout::CIFStockNoteout(const CIFStockNoteout& src)
{
    if (this == &src)
    {
        return;
    }

    m_Noteout = src.m_Noteout;
    m_lstBoxList = src.m_lstBoxList;
}

//拷贝赋值函数
CIFStockNoteout& CIFStockNoteout::operator=(const CIFStockNoteout& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_Noteout = src.m_Noteout;
    m_lstBoxList = src.m_lstBoxList;

    return *this;
}

CIPStockNoteout CIFStockNoteout::GetNoteout()
{
    return m_Noteout;
}

void CIFStockNoteout::SetNoteout(const CIPStockNoteout& noteout)
{
    m_Noteout = noteout;
}

QList<CIPStockNoteoutBox> CIFStockNoteout::GetBoxList()
{
    return m_lstBoxList;
}

void CIFStockNoteout::SetBoxList(const QList<CIPStockNoteoutBox>& lstBoxList)
{
    m_lstBoxList = lstBoxList;
}

/*
*@brief             获取纸币出币器库存信息
*@param     in|out  dest            要获取的纸币出币器库存信息
*@param     in      i32BoxIndex     钞箱序号
*@retval            true            获取成功
*@retval            false           获取失败
*/
bool CIFStockNoteout::GetBox(CIPStockNoteoutBox& dest, qint32 i32BoxIndex) const
{
    if (i32BoxIndex < 0 || i32BoxIndex >= m_lstBoxList.count())
    {
        return false;
    }

    dest = m_lstBoxList.at(i32BoxIndex);

    return true;
}

int CIFStockNoteout::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/stock_noteout.ini";
    }

    return 1;
}

int CIFStockNoteout::ReadData(QSettings& set)
{
    set.beginGroup("NOTEOUT");
    m_Noteout.SetMultiBoxFlag(1==set.value("multi_box_flag").toInt()?true:false);
    m_Noteout.SetBoxNum(set.value("box_num").toInt());
    m_Noteout.SetCurBoxIndex(set.value("cur_box_index").toInt());
    m_Noteout.SetAllNum( set.value("all_num").toInt());
    m_Noteout.SetAllSum(set.value("all_sum").toInt());
    set.endGroup();

    for (int i=0;i<m_Noteout.GetBoxNum();i++)
    {
        ReadBox(set, i);
    }

    return 1;
}

int CIFStockNoteout::WriteData(QSettings& set)
{    
    qint32 i32AllNum = 0;
    qint32 i32AllSum = 0;

    for (int i=0;i<m_Noteout.GetBoxNum();i++)
    {
        WriteBox(set, i);
        i32AllNum += m_lstBoxList.at(i).GetTotalNoteNum();
        i32AllSum += (m_lstBoxList.at(i).GetFace()*m_lstBoxList.at(i).GetTotalNoteNum());
    }
    m_Noteout.SetAllNum(i32AllNum);
    m_Noteout.SetAllSum(i32AllSum);

    set.beginGroup("NOTEOUT");
    set.setValue("multi_box_flag", m_Noteout.GetMultiBoxFlag()?1:0);
    set.setValue("box_num", m_Noteout.GetBoxNum());
    set.setValue("cur_box_index", m_Noteout.GetCurBoxIndex());
    set.setValue("all_num", m_Noteout.GetAllNum());
    set.setValue("all_sum", m_Noteout.GetAllSum());
    set.endGroup();

    return 1;
}

int CIFStockNoteout::ReadBox(QSettings& set, qint32 i32Index)
{
    CIPStockNoteoutBox box;

    set.beginGroup(QString("BOX_%1").arg(QString::number(i32Index).rightJustified(3, '0',true)));
    box.SetFace(set.value("face").toInt());
    box.SetTotalNoteNum(set.value("total_note_num").toInt());
    box.SetBoxNoteNum(set.value("box_note_num").toInt());
    box.SetRejectNoteNum(set.value("reject_note_num").toInt());
    box.SetRejectCount(set.value("reject_count").toInt());
    set.endGroup();

    m_lstBoxList.append(box);

    return 1;
}

int CIFStockNoteout::WriteBox(QSettings& set, qint32 i32Index)
{
    set.beginGroup(QString("BOX_%1").arg(QString::number(i32Index).rightJustified(3, '0',true)));
    set.setValue("face", m_lstBoxList.at(i32Index).GetFace());
    set.setValue("total_note_num", m_lstBoxList.at(i32Index).GetTotalNoteNum());
    set.setValue("box_note_num", m_lstBoxList.at(i32Index).GetBoxNoteNum());
    set.setValue("reject_note_num", m_lstBoxList.at(i32Index).GetRejectNoteNum());
    set.setValue("reject_count", m_lstBoxList.at(i32Index).GetRejectCount());
    set.endGroup();

    return 1;
}

void CIFStockNoteout::Clear()
{
    m_Noteout.Clear();
    m_lstBoxList.clear();
}
