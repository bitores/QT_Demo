#include "IFStockNotein.h"

#include <QtCore/qcoreapplication.h>

CIFStockNotein::CIFStockNotein(QObject *parent) :
    CIFBase(parent)
{
}

CIFStockNotein::~CIFStockNotein()
{

}

//拷贝构造函数
CIFStockNotein::CIFStockNotein(const CIFStockNotein& src)
{
    if (this == &src)
    {
        return;
    }

    m_Notein = src.m_Notein;
    m_lstFaceList = src.m_lstFaceList;
}

//拷贝赋值函数
CIFStockNotein& CIFStockNotein::operator=(const CIFStockNotein& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_Notein = src.m_Notein;
    m_lstFaceList = src.m_lstFaceList;

    return *this;
}

CIPStockNotein CIFStockNotein::GetNotein()
{
    return m_Notein;
}

void CIFStockNotein::SetNotein(const CIPStockNotein& notein)
{
    m_Notein = notein;
}

QList<CIPStockNoteinFace> CIFStockNotein::GetFaceList()
{
    return m_lstFaceList;
}

void CIFStockNotein::SetFaceList(const QList<CIPStockNoteinFace>& lstFaceList)
{
    m_lstFaceList = lstFaceList;
}

/*
*@brief             获取纸币进币器库存信息
*@param     in|out  dest            要获取的纸币进币器信息
*@param     in      i32FaceIndex    面值序号
*@retval            true            获取成功
*@retval            false           获取失败
*/
bool CIFStockNotein::GetFace(CIPStockNoteinFace& dest, qint32 i32FaceIndex) const
{
    if (i32FaceIndex < 0 || i32FaceIndex >= m_lstFaceList.count())
    {
        return false;
    }

    dest = m_lstFaceList.at(i32FaceIndex);

    return true;
}

int CIFStockNotein::CheckFile(QString& strFile)
{
    if (0 >= strFile.size())
    {
        QString strpath = QCoreApplication::applicationDirPath();
        //程序位于bin目录,动态库位于lib目录，配置文件位于cfg目录
        strFile = strpath.left(strpath.size()-4) + "/cfg/stock_notein.ini";
    }

    return 1;
}

int CIFStockNotein::ReadData(QSettings& set)
{
    set.beginGroup("NOTEIN");
    m_Notein.SetFaceNum(set.value("face_num").toInt());
    m_Notein.SetAllNum( set.value("all_num").toInt());
    m_Notein.SetAllSum(set.value("all_sum").toInt());
    set.endGroup();

    for (int i=0;i<m_Notein.GetFaceNum();i++)
    {
        ReadFace(set, i);
    }



    return 1;
}

int CIFStockNotein::WriteData(QSettings& set)
{
    qint32 i32AllNum = 0;
    qint32 i32AllSum = 0;
    for (int i=0;i<m_Notein.GetFaceNum();i++)
    {
        WriteFace(set, i);
        i32AllNum += m_lstFaceList.at(i).GetCurNum();
        i32AllSum += (m_lstFaceList.at(i).GetCurNum()*m_lstFaceList.at(i).GetFace());
    }
    m_Notein.SetAllNum(i32AllNum);
    m_Notein.SetAllSum(i32AllSum);

    set.beginGroup("NOTEIN");
    set.setValue("face_num", m_Notein.GetFaceNum());
    set.setValue("all_num", m_Notein.GetAllNum());
    set.setValue("all_sum", m_Notein.GetAllSum());
    set.endGroup();

    return 1;
}

int CIFStockNotein::ReadFace(QSettings& set, qint32 i32Index)
{
    CIPStockNoteinFace face;

    set.beginGroup(QString("FACE_%1").arg(QString::number(i32Index).rightJustified(3, '0',true)));
    face.SetFace(set.value("face").toInt());
    face.SetCurNum(set.value("cur_num").toInt());
    set.endGroup();

    m_lstFaceList.append(face);

    return 1;
}

int CIFStockNotein::WriteFace(QSettings& set, qint32 i32Index)
{
    set.beginGroup(QString("FACE_%1").arg(QString::number(i32Index).rightJustified(3, '0',true)));
    set.setValue("face", m_lstFaceList.at(i32Index).GetFace());
    set.setValue("cur_num", m_lstFaceList.at(i32Index).GetCurNum());
    set.endGroup();

    return 1;
}

void CIFStockNotein::Clear()
{
    m_Notein.Clear();
    m_lstFaceList.clear();
}
