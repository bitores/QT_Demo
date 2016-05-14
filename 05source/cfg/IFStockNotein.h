#ifndef INI_FILE_STOCK_NOTEIN_H
#define INI_FILE_STOCK_NOTEIN_H

#include "IFBase.h"
#include <QtCore/qlist.h>
#include "IPStockNotein.h"
#include "IPStockNoteinFace.h"

class CIFStockNotein : public CIFBase
{
    Q_OBJECT
public:
    explicit CIFStockNotein(QObject *parent = 0);
    ~CIFStockNotein();

    //拷贝构造函数
    CIFStockNotein(const CIFStockNotein& src);
    //拷贝赋值函数
    CIFStockNotein& operator=(const CIFStockNotein& src);

public:
    CIPStockNotein GetNotein();
    void SetNotein(const CIPStockNotein& notein);

    QList<CIPStockNoteinFace> GetFaceList();
    void SetFaceList(const QList<CIPStockNoteinFace>& lstFaceList);

    /*
    *@brief             获取纸币进币器库存信息
    *@param     in|out  dest            要获取的纸币进币器信息
    *@param     in      i32FaceIndex    面值序号
    *@retval            true            获取成功
    *@retval            false           获取失败
    */
    bool GetFace(CIPStockNoteinFace& dest, qint32 i32FaceIndex) const;

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();

private:
    int ReadFace(QSettings& set, qint32 i32Index);
    int WriteFace(QSettings& set, qint32 i32Index);
    
signals:
    
public slots:

public:
    CIPStockNotein      m_Notein;               //纸币进币器的模块信息
    QList<CIPStockNoteinFace> m_lstFaceList;    //纸币进币器的各个面值的信息列表
    
};

#endif // INI_FILE_STOCK_NOTEIN_H
