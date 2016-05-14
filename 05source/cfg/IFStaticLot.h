#ifndef INI_FILE_STATIC_LOT_H
#define INI_FILE_STATIC_LOT_H

#include "IFBase.h"
#include <QtCore/qlist.h>
#include "IPStaticLotInfo.h"
#include "IPStaticLot.h"

class CIFStaticLot : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStaticLot(QObject *parent = 0);
    ~CIFStaticLot();

    //拷贝构造函数
    CIFStaticLot(const CIFStaticLot& src);
    //拷贝赋值函数
    CIFStaticLot& operator=(const CIFStaticLot& src);

public:
    CIPStaticLotInfo GetLotInfo();
    void SetLotInfo(const CIPStaticLotInfo& lotInfo);

    QList<CIPStaticLot> GetLotList();
    void SetLotList(const QList<CIPStaticLot>& lstLotList);

    /*
    *@brief     通过彩票类型ID获取彩票信息
    *@param[in|out]     dest            要获取的彩票信息
    *@param[in]         strLotTypeID    彩票类型ID
    *@retval            true            获取成功
    *@retval            false           获取失败
    */
    bool GetLotById(CIPStaticLot& dest, const QString& strLotTypeID);


    /*
    *@brief     通过彩票名称获取彩票信息
    *@param[in|out]     dest            要获取的彩票信息
    *@param[in]         strLotTypeName  彩票类型名称
    *@retval            true            获取成功
    *@retval            false           获取失败
    */
    bool GetLotByName(CIPStaticLot& dest, const QString& strLotTypeName);

    /*
    *@brief             获取彩票信息
    *@param     in|out  dest            要获取的彩票信息
    *@param     in      strLotTypeID    彩票类型ID
    *@retval            true            获取成功
    *@retval            false           获取失败
    */
    bool GetLot(CIPStaticLot& dest, const QString& strLotTypeID);

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();

private:
    int ReadLot(QSettings& set, qint32 i32Index);
    int WriteLot(QSettings& set, qint32 i32Index);
    
signals:
    
public slots:

public:
    CIPStaticLotInfo    m_LotInfo;              //所有彩票的汇总和通用信息
    QList<CIPStaticLot> m_lstLotList;           //所有的彩票的信息的列表
    
};

#endif // INI_FILE_STATIC_LOT_H
