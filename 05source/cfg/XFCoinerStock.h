#ifndef XML_FILE_COINER_STOCK_H
#define XML_FILE_COINER_STOCK_H

#include <QObject>

#include "XFBase.h"
#include "XPCoinerStock.h"

class CXFCoinerStock : public CXFBase
{
    Q_OBJECT
public:
    explicit CXFCoinerStock(QObject *parent = 0);
    ~CXFCoinerStock();

    //拷贝构造函数
    CXFCoinerStock(const CXFCoinerStock& src);
    //拷贝赋值函数
    CXFCoinerStock& operator=(const CXFCoinerStock& src);

public:
    CXPCoinerStock GetStock();
    void SetStock(CXPCoinerStock stock);

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ParseXml(const QDomDocument& qdoc, const QString& strFile);
    virtual int ParseNode(const QDomElement& deParent, QDomElement& deThis, const QString& strNodeName, const QString& strFile);

    virtual int SaveXml(QFile& file);
    
signals:
    
public slots:

private:
    CXPCoinerStock      m_stock;
    
};

#endif // XML_FILE_COINER_STOCK_H
