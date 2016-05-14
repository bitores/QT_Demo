#ifndef INI_FILE_STOCK_LOTBOX_H
#define INI_FILE_STOCK_LOTBOX_H

#include "IFBase.h"
#include <QtCore/qlist.h>
#include "IPStockLotbox.h"
#include "IPStockLotboxBox.h"

class CIFStockLotbox : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStockLotbox(QObject *parent = 0);
    ~CIFStockLotbox();

    //拷贝构造函数
    CIFStockLotbox(const CIFStockLotbox& src);
    //拷贝赋值函数
    CIFStockLotbox& operator=(const CIFStockLotbox& src);

public:
    CIPStockLotbox GetLotbox();
    void SetLotbox(const CIPStockLotbox& lotbox);

    QList<CIPStockLotboxBox> GetBoxList();
    void SetBoxList(const QList<CIPStockLotboxBox>& lstBoxList);

    /*
    *@brief             获取票箱库存信息
    *@param     in|out  dest            要获取的票箱库存信息
    *@param     in      i32BoxIndex     票箱序号
    *@retval            true            获取成功
    *@retval            false           获取失败
    */
    bool GetBox(CIPStockLotboxBox& dest, qint32 i32BoxIndex) const;

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();

private:
    int ReadBox(QSettings& set, qint32 i32Index);
    int WriteBox(QSettings& set, qint32 i32Index);
    
signals:
    
public slots:

public:
    CIPStockLotbox      m_Lotbox;               //设备内的出票模块的信息
    QList<CIPStockLotboxBox> m_lstBoxList;      //出票模块内的每个票箱的信息列表
    
};

#endif // INI_FILE_STOCK_LOTBOX_H
