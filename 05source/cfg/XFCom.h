#ifndef XML_FILE_COM_H
#define XML_FILE_COM_H

#include <QObject>
#include <QtXml/qdom.h>
#include <QtCore/qxmlstream.h>
#include "XPCom.h"
#include "XFBase.h"



class CXFCom : public CXFBase
{
    Q_OBJECT
public:
    explicit CXFCom(QObject *parent = 0);
    ~CXFCom();

    //拷贝构造函数
    CXFCom(const CXFCom& src);
    //拷贝赋值函数
    CXFCom& operator=(const CXFCom& src);

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ParseXml(const QDomDocument& qdoc, const QString& strFile);
    virtual int ParseNode(const QDomElement& deParent, QDomElement& deThis, const QString& strNodeName, const QString& strFile);

    virtual int SaveXml(QFile& file);

private:
    void SetXFCom(CXPCom& dest, const QDomElement& de);
    void SaveElement(QXmlStreamWriter& xsw, const QString& strNodeName);
    void SaveXFCom(QXmlStreamWriter& xsw, CXPCom& src);

public:
    void SetNotein(const CXPCom& src);
    CXPCom GetNotein();
    void SetNoteout(const CXPCom& src);
    CXPCom GetNoteout();
    void SetCoinin(const CXPCom& src);
    CXPCom GetCoinin();
    void SetCoinout(const CXPCom& src);
    CXPCom GetCoinout();
    void SetStamping(const CXPCom& src);
    CXPCom GetStamping();

    void SetScanner(const CXPCom& src);
    CXPCom GetScanner();
    void SetUps(const CXPCom& src);
    CXPCom GetUps();

    void SetLotbox1(const CXPCom& src);
    CXPCom GetLotbox1();
    void SetLotbox2(const CXPCom& src);
    CXPCom GetLotbox2();
    void SetLotbox3(const CXPCom& src);
    CXPCom GetLotbox3();
    void SetLotbox4(const CXPCom& src);
    CXPCom GetLotbox4();
    void SetLotbox5(const CXPCom& src);
    CXPCom GetLotbox5();
    void SetLotbox6(const CXPCom& src);
    CXPCom GetLotbox6();
    void SetLotbox7(const CXPCom& src);
    CXPCom GetLotbox7();
    void SetLotbox8(const CXPCom& src);
    CXPCom GetLotbox8();
    
signals:
    
public slots:

private:
    //以下为串口参数
    //L500型号设备的串口分配如下：
    //1为纸币进，2为纸币出，3为硬币进，4为硬币出，5为兑奖模块
    //9为扫描仪，10为ups
    //11~18分别对应出票模块1~8
    CXPCom              m_notein;               //纸币进币器
    CXPCom              m_noteout;              //纸币出币器
    CXPCom              m_coinin;               //硬币进币器
    CXPCom              m_coinout;              //硬币出币器
    CXPCom              m_stamping;             //兑奖模块

    CXPCom              m_scanner;              //扫描仪
    CXPCom              m_ups;                  //ups

    CXPCom              m_lotbox1;              //出票模块1
    CXPCom              m_lotbox2;              //出票模块2
    CXPCom              m_lotbox3;              //出票模块3
    CXPCom              m_lotbox4;              //出票模块4
    CXPCom              m_lotbox5;              //出票模块5
    CXPCom              m_lotbox6;              //出票模块6
    CXPCom              m_lotbox7;              //出票模块7
    CXPCom              m_lotbox8;              //出票模块8

    
};

#endif // XML_FILE_COM_H
