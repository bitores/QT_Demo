#ifndef INI_FILE_STOCK_NOTEOUT_H
#define INI_FILE_STOCK_NOTEOUT_H

#include "IFBase.h"
#include <QtCore/qlist.h>
#include "IPStockNoteout.h"
#include "IPStockNoteoutBox.h"

class CIFStockNoteout : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStockNoteout(QObject *parent = 0);
    ~CIFStockNoteout();

    //拷贝构造函数
    CIFStockNoteout(const CIFStockNoteout& src);
    //拷贝赋值函数
    CIFStockNoteout& operator=(const CIFStockNoteout& src);

public:
    CIPStockNoteout GetNoteout();
    void SetNoteout(const CIPStockNoteout& noteout);

    QList<CIPStockNoteoutBox> GetBoxList();
    void SetBoxList(const QList<CIPStockNoteoutBox>& lstBoxList);

    /*
    *@brief             获取纸币出币器库存信息
    *@param     in|out  dest            要获取的纸币出币器库存信息
    *@param     in      i32BoxIndex     钞箱序号
    *@retval            true            获取成功
    *@retval            false           获取失败
    */
    bool GetBox(CIPStockNoteoutBox& dest, qint32 i32BoxIndex) const;

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
    CIPStockNoteout     m_Noteout;              //出钞模块的信息
    QList<CIPStockNoteoutBox>   m_lstBoxList;   //出钞模块的各个钞箱的信息列表
    
};

#endif // INI_FILE_STOCK_NOTEOUT_H
