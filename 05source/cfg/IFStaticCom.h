#ifndef INI_FILE_STATIC_COM_H
#define INI_FILE_STATIC_COM_H

#include "IFBase.h"
#include <QtCore/qlist.h>
#include "IPStaticCom.h"

class CIFStaticCom : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStaticCom(QObject *parent = 0);
    ~CIFStaticCom();

    //拷贝构造函数
    CIFStaticCom(const CIFStaticCom& src);
    //拷贝赋值函数
    CIFStaticCom& operator=(const CIFStaticCom& src);

public:
    CIPStaticCom GetNotein();
    void SetNotein(const CIPStaticCom& notein);

    CIPStaticCom GetNoteout();
    void SetNoteout(const CIPStaticCom& noteout);

    CIPStaticCom GetCoinin();
    void SetCoinin(const CIPStaticCom& coinin);

    CIPStaticCom GetCoinout();
    void SetCoinout(const CIPStaticCom& coinout);

    CIPStaticCom GetStamping();
    void SetStamping(const CIPStaticCom& stamping);

    CIPStaticCom GetScanner();
    void SetScanner(const CIPStaticCom& scanner);

    CIPStaticCom GetUps();
    void SetUps(const CIPStaticCom& ups);

    qint32 GetBoxNum() const;
    void SetBoxNum(qint32 i32BoxNum);

    QList<CIPStaticCom> GetBoxList();
    void SetBoxList(const QList<CIPStaticCom>& lstBoxList);

    /*
    *@brief             获取票箱串口信息
    *@param     in|out  dest            要获取的票箱串口信息
    *@param     in      i32BoxIndex     票箱序号
    *@retval            true            获取成功
    *@retval            false           获取失败
    */
    bool GetBox(CIPStaticCom& dest, qint32 i32BoxIndex) const;

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();

private:
    int ReadCom(QSettings& set, const QString& strGroup, CIPStaticCom& com);
    int WriteCom(QSettings& set, const QString& strGroup, CIPStaticCom& com);
    int ReadBox(QSettings& set, qint32 i32Index);
    int WriteBox(QSettings& set, qint32 i32Index);

    
signals:
    
public slots:

public:
    CIPStaticCom        m_Notein;               //纸币进币器串口参数
    CIPStaticCom        m_Noteout;              //纸币出币器串口参数
    CIPStaticCom        m_Coinin;               //硬币进币器串口参数
    CIPStaticCom        m_Coinout;              //硬币出币器串口参数
    CIPStaticCom        m_Stamping;             //兑奖模块串口参数
    CIPStaticCom        m_Scanner;              //扫描仪串口参数
    CIPStaticCom        m_Ups;                  //UPS串口参数
    qint32              m_i32BoxNum;            //出票模块的票箱数量
    QList<CIPStaticCom> m_lstBoxList;           //出票模块的票箱的串口参数的列表


    
};

#endif // INI_FILE_STATIC_COM_H
