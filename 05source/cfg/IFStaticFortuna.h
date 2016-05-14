#ifndef INI_FILE_STATIC_FORTUNA_H
#define INI_FILE_STATIC_FORTUNA_H

#include "IFBase.h"
#include "IPStaticDev.h"
#include "IPStaticCompany.h"
#include "IPStaticOperator.h"
#include "IPStaticNetwork.h"
#include "IPStaticFtp.h"
#include "IPStaticLotbox.h"
#include "IPStaticPrize.h"
#include "IPStaticNotein.h"
#include "IPStaticNoteout.h"
#include "IPStaticCoiner.h"
#include "IPStaticTimer.h"
#include "IPStaticUps.h"
#include "IPStaticRedeembox.h"

class CIFStaticFortuna : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStaticFortuna(QObject *parent = 0);
    ~CIFStaticFortuna();

    //拷贝构造函数
    CIFStaticFortuna(const CIFStaticFortuna& src);
    //拷贝赋值函数
    CIFStaticFortuna& operator=(const CIFStaticFortuna& src);

public:
    CIPStaticDev GetDev();
    void SetDev(const CIPStaticDev& dev);

    CIPStaticCompany GetCompany();
    void SetCompany(const CIPStaticCompany& company);

    CIPStaticOperator GetOperator();
    void SetOperator(const CIPStaticOperator& src);

    CIPStaticNetwork GetNetwork();
    void SetNetwork(const CIPStaticNetwork& network);

    CIPStaticFtp GetFtp();
    void SetFtp(const CIPStaticFtp& ftp);

    CIPStaticLotbox GetLotbox();
    void SetLotbox(const CIPStaticLotbox& lotbox);

    CIPStaticPrize GetPrize();
    void SetPrize(const CIPStaticPrize& prize);

    CIPStaticNotein GetNotein();
    void SetNotein(const CIPStaticNotein& notein);

    CIPStaticNoteout GetNoteout();
    void SetNoteout(const CIPStaticNoteout& noteout);

    CIPStaticCoiner GetCoiner();
    void SetCoiner(const CIPStaticCoiner& coiner);

    CIPStaticTimer GetTimer();
    void SetTimer(const CIPStaticTimer& timer);

    CIPStaticUps GetUps();
    void SetUps(const CIPStaticUps& ups);

    CIPStaticRedeembox GetRedeembox();
    void SetRedeembox(const CIPStaticRedeembox& redeembox);

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();

private:
    int ReadDev(QSettings& set);
    int WriteDev(QSettings& set);

    int ReadCompany(QSettings& set);
    int WriteCompany(QSettings& set);

    int ReadOperator(QSettings& set);
    int WriteOperator(QSettings& set);

    int ReadNetwork(QSettings& set);
    int WriteNetwork(QSettings& set);

    int ReadFtp(QSettings& set);
    int WriteFtp(QSettings& set);

    int ReadLotbox(QSettings& set);
    int WriteLotbox(QSettings& set);

    int ReadPrize(QSettings& set);
    int WritePrize(QSettings& set);

    int ReadNotein(QSettings& set);
    int WriteNotein(QSettings& set);

    int ReadNoteout(QSettings& set);
    int WriteNoteout(QSettings& set);

    int ReadCoiner(QSettings& set);
    int WriteCoiner(QSettings& set);

    int ReadTimer(QSettings& set);
    int WriteTimer(QSettings& set);

    int ReadUps(QSettings& set);
    int WriteUps(QSettings& set);

    int ReadRedeembox(QSettings& set);
    int WriteRedeembox(QSettings& set);
    
signals:
    
public slots:

public:
    CIPStaticDev        m_Dev;                  //设备信息
    CIPStaticCompany    m_Company;              //公司信息
    CIPStaticOperator   m_Operator;             //维护员信息
    CIPStaticNetwork    m_Network;              //网络信息
    CIPStaticFtp        m_Ftp;                  //FTP信息
    CIPStaticLotbox     m_Lotbox;               //票箱信息
    CIPStaticPrize      m_Prize;                //兑奖信息
    CIPStaticNotein     m_Notein;               //纸币进币器信息
    CIPStaticNoteout    m_Noteout;              //纸币出币器信息
    CIPStaticCoiner     m_Coiner;               //硬币器信息
    CIPStaticTimer      m_Timer;                //定时器信息
    CIPStaticUps        m_Ups;                  //UPS信息
    CIPStaticRedeembox  m_Redeembox;            //中奖彩票回收箱

    
};

#endif // INI_FILE_STATIC_FORTUNA_H
