#ifndef INI_PARAM_STATIC_COM_H
#define INI_PARAM_STATIC_COM_H

#include <QObject>
#include <QtCore/qstring.h>

#include "abstractserial.h"


/**
  *@class   串口参数类
  */
class CIPStaticCom : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticCom(QObject *parent = 0);
    CIPStaticCom(const QString& name
           , AbstractSerial::BaudRate rate
           , AbstractSerial::Parity parity
           , AbstractSerial::DataBits databit
           , AbstractSerial::StopBits stopbit);
    CIPStaticCom(const QString& name, const QString& rate, const QString& parity
           , const QString& databit, const QString& stopbit);
    ~CIPStaticCom();

    //拷贝构造函数
    CIPStaticCom(const CIPStaticCom& src);
    //拷贝赋值函数
    CIPStaticCom& operator=(const CIPStaticCom& src);
    
signals:
    
public slots:

public:
    //串口名称
    void SetName(const QString& name);
    QString GetName() const;
    //串口波特率
    void SetRate(const QString& src);
    void SetRate(AbstractSerial::BaudRate rate = AbstractSerial::BaudRate9600);
    AbstractSerial::BaudRate GetRate() const;
    QString GetRateValue() const;
    //串口校验位
    void SetParity(const QString& src);
    void SetParity(AbstractSerial::Parity parity = AbstractSerial::ParityNone);
    AbstractSerial::Parity GetParity() const;
    QString GetParityValue() const;
    //串口数据位
    void SetDataBit(const QString& src);
    void SetDataBit(AbstractSerial::DataBits databit = AbstractSerial::DataBits5);
    AbstractSerial::DataBits GetDataBit() const;
    QString GetDataBitValue() const;
    //串口停止位
    void SetStopBit(const QString& src);
    void SetStopBit(AbstractSerial::StopBits stopbit = AbstractSerial::StopBits1);
    AbstractSerial::StopBits GetStopBit() const;
    QString GetStopBitValue() const;

    void Clear();

public:
    QString             m_name;                 //串口名称
    AbstractSerial::BaudRate m_rate;            //串口波特率
    AbstractSerial::Parity m_parity;            //串口检验位
    AbstractSerial::DataBits m_databit;         //串口数据位
    AbstractSerial::StopBits m_stopbit;         //串口停止位
    
};

#endif // INI_PARAM_STATIC_COM_H
