#include "IPStaticAppVer.h"

CIPStaticAppVer::CIPStaticAppVer(QObject *parent) :
    QObject(parent)
  ,m_i32CurNum(0)
  ,m_strFortuna("")
  ,m_strNotein("")
  ,m_strNoteout("")
  ,m_strCoinin("")
  ,m_strCoinout("")
  ,m_strStamping("")
  ,m_strScanner("")
  ,m_strUps("")
  ,m_strLotbox("")
  ,m_strCamera("")
{
}

CIPStaticAppVer::~CIPStaticAppVer()
{

}

//拷贝构造函数
CIPStaticAppVer::CIPStaticAppVer(const CIPStaticAppVer& src)
{
    if (this == &src)
    {
        return;
    }

    m_i32CurNum = src.m_i32CurNum;
    m_strFortuna= src.m_strFortuna;
    m_strNotein= src.m_strNotein;
    m_strNoteout= src.m_strNoteout;
    m_strCoinin= src.m_strCoinin;
    m_strCoinout= src.m_strCoinout;
    m_strStamping= src.m_strStamping;
    m_strScanner= src.m_strScanner;
    m_strUps= src.m_strUps;
    m_strLotbox= src.m_strLotbox;
    m_strCamera= src.m_strCamera;
}

//拷贝赋值函数
CIPStaticAppVer& CIPStaticAppVer::operator=(const CIPStaticAppVer& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_i32CurNum = src.m_i32CurNum;
    m_strFortuna= src.m_strFortuna;
    m_strNotein= src.m_strNotein;
    m_strNoteout= src.m_strNoteout;
    m_strCoinin= src.m_strCoinin;
    m_strCoinout= src.m_strCoinout;
    m_strStamping= src.m_strStamping;
    m_strScanner= src.m_strScanner;
    m_strUps= src.m_strUps;
    m_strLotbox= src.m_strLotbox;
    m_strCamera= src.m_strCamera;

    return *this;
}

qint32 CIPStaticAppVer::GetCurNum() const
{
    return m_i32CurNum;
}

void CIPStaticAppVer::SetCurNum(qint32 i32CurNum)
{
    m_i32CurNum = i32CurNum;
}

QString CIPStaticAppVer::GetFortuna() const
{
    return m_strFortuna;
}

void CIPStaticAppVer::SetFortuna(const QString& strFortuna)
{
    m_strFortuna = strFortuna;
}

QString CIPStaticAppVer::GetNotein() const
{
    return m_strNotein;
}

void CIPStaticAppVer::SetNotein(const QString& strNotein)
{
    m_strNotein = strNotein;
}

QString CIPStaticAppVer::GetNoteout() const
{
    return m_strNoteout;
}

void CIPStaticAppVer::SetNoteout(const QString& strNoteout)
{
    m_strNoteout = strNoteout;
}

QString CIPStaticAppVer::GetCoinin() const
{
    return m_strCoinin;
}

void CIPStaticAppVer::SetCoinin(const QString& strCoinin)
{
    m_strCoinin = strCoinin;
}

QString CIPStaticAppVer::GetCoinout() const
{
    return m_strCoinout;
}

void CIPStaticAppVer::SetCoinout(const QString& strCoinout)
{
    m_strCoinout = strCoinout;
}

QString CIPStaticAppVer::GetStamping() const
{
    return m_strStamping;
}

void CIPStaticAppVer::SetStamping(const QString& strStamping)
{
    m_strStamping = strStamping;
}

QString CIPStaticAppVer::GetScanner() const
{
    return m_strScanner;
}

void CIPStaticAppVer::SetScanner(const QString& strScanner)
{
    m_strScanner = strScanner;
}

QString CIPStaticAppVer::GetUps() const
{
    return m_strUps;
}

void CIPStaticAppVer::SetUps(const QString& strUps)
{
    m_strUps = strUps;
}

QString CIPStaticAppVer::GetLotbox() const
{
    return m_strLotbox;
}

void CIPStaticAppVer::SetLotbox(const QString& strLotbox)
{
    m_strLotbox = strLotbox;
}

QString CIPStaticAppVer::GetCamera() const
{
    return m_strCamera;
}

void CIPStaticAppVer::SetCamera(const QString& strCamera)
{
    m_strCamera = strCamera;
}

void CIPStaticAppVer::Clear()
{
    m_i32CurNum = 0;
    m_strFortuna= "";
    m_strNotein= "";
    m_strNoteout= "";
    m_strCoinin= "";
    m_strCoinout= "";
    m_strStamping= "";
    m_strScanner= "";
    m_strUps= "";
    m_strLotbox= "";
    m_strCamera= "";
}
