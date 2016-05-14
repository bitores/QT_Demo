#ifndef CFG_H
#define CFG_H

#include <QObject>

#include "IFStaticAppVer.h"
#include "IFStaticCom.h"
#include "IFStaticFortuna.h"
#include "IFStaticLot.h"
#include "IFStaticHardware.h"
#include "IFStockCoiner.h"
#include "IFStockLotbox.h"
#include "IFStockNotein.h"
#include "IFStockNoteout.h"
#include "IFStockSeq.h"
#include "IFStockRedeembox.h"

class CCfg : public QObject
{
    Q_OBJECT
public:
    static CCfg* Instance();
    static void Release();

private:
    static CCfg* sm_pInstance;

private:
    explicit CCfg(QObject *parent = 0);
    ~CCfg();

public:
    //拷贝构造函数
    CCfg(const CCfg& src);
    //拷贝赋值函数
    CCfg& operator=(const CCfg& src);

public:
    int Read();
    int Write();

public:
    CIFStaticAppVer GetAppVer() const;
    void SetAppVer(const CIFStaticAppVer& AppVer);

    CIFStaticCom GetCom() const;
    void SetCom(CIFStaticCom& Com);

    CIFStaticFortuna GetFortuna() const;
    void SetFortuna(const CIFStaticFortuna& Fortuna);

    CIFStaticLot GetLot() const;
    void SetLot(CIFStaticLot& Lot);

    CIFStaticHardware GetHardware() const;
    void SetHardware(const CIFStaticHardware& Hardware);

    CIFStockCoiner GetCoiner() const;
    void SetCoiner(const CIFStockCoiner& Coiner);

    CIFStockLotbox GetLotbox() const;
    void SetLotbox(const CIFStockLotbox& Lotbox);

    CIFStockNotein GetNotein() const;
    void SetNotein(const CIFStockNotein& Notein);

    CIFStockNoteout GetNoteout() const;
    void SetNoteout(const CIFStockNoteout& Noteout);

    CIFStockSeq GetSeq() const;
    void SetSeq(const CIFStockSeq& Seq);

    CIFStockRedeembox GetRedeembox() const;
    void SetRedeembox(const CIFStockRedeembox& redeembox);
    
signals:
    
public slots:

public:
    CIFStaticAppVer     m_AppVer;               //程序版本文件
    CIFStaticCom        m_Com;                  //串口文件
    CIFStaticFortuna    m_Fortuna;              //终端文件
    CIFStaticLot        m_Lot;                  //彩票文件
    CIFStaticHardware   m_Hardware;             //硬件文件
    CIFStockCoiner      m_Coiner;               //硬币库存文件
    CIFStockLotbox      m_Lotbox;               //票箱库存文件
    CIFStockNotein      m_Notein;               //纸币进币器库存文件
    CIFStockNoteout     m_Noteout;              //纸币出币器库存文件
    CIFStockSeq         m_Seq;                  //序号库存文件
    CIFStockRedeembox   m_Redeembox;            //中奖彩票回收箱文件
    
};

#endif // CFG_H
