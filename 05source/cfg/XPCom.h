#ifndef XML_PARAM_COM_H
#define XML_PARAM_COM_H

#include <QObject>
#include <QtCore/qstring.h>

#include "abstractserial.h"

/**
  *@class   串口参数类
  */
class CXPCom : public QObject
{
    Q_OBJECT
public:
    explicit CXPCom(QObject *parent = 0);
    CXPCom(const QString& name
           , AbstractSerial::BaudRate rate
           , AbstractSerial::Parity parity
           , AbstractSerial::DataBits databit
           , AbstractSerial::StopBits stopbit);
    ~CXPCom();

    //拷贝构造函数
    CXPCom(const CXPCom& src);
    //拷贝赋值函数
    CXPCom& operator=(const CXPCom& src);
    
signals:
    
public slots:

public:
    //串口名称
    void SetName(const QString& name);
    QString GetName();
    //串口波特率
    void SetRate(const QString& src);
    void SetRate(AbstractSerial::BaudRate rate = AbstractSerial::BaudRate9600);
    AbstractSerial::BaudRate GetRate();
    //串口校验位
    void SetParity(const QString& src);
    void SetParity(AbstractSerial::Parity parity = AbstractSerial::ParityNone);
    AbstractSerial::Parity GetParity();
    QString GetParityValue();
    //串口数据位
    void SetDataBit(const QString& src);
    void SetDataBit(AbstractSerial::DataBits databit = AbstractSerial::DataBits5);
    AbstractSerial::DataBits GetDataBit();
    QString GetDataBitValue();
    //串口停止位
    void SetStopBit(const QString& src);
    void SetStopBit(AbstractSerial::StopBits stopbit = AbstractSerial::StopBits1);
    AbstractSerial::StopBits GetStopBit();
    QString GetStopBitValue();

private:
    QString             m_name;                 //串口名称
    AbstractSerial::BaudRate m_rate;            //串口波特率
    AbstractSerial::Parity m_parity;            //串口检验位
    AbstractSerial::DataBits m_databit;         //串口数据位
    AbstractSerial::StopBits m_stopbit;         //串口停止位
    
};

#endif // XML_PARAM_COM_H
