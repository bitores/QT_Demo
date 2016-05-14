#include "XPCom.h"

CXPCom::CXPCom(QObject *parent) :
    QObject(parent)
  ,m_name("")
  ,m_rate(AbstractSerial::BaudRate9600)
  ,m_parity(AbstractSerial::ParityNone)
  ,m_databit(AbstractSerial::DataBits5)
  ,m_stopbit(AbstractSerial::StopBits1)
{
}

CXPCom::CXPCom(const QString& name
               , AbstractSerial::BaudRate rate
               , AbstractSerial::Parity parity
               , AbstractSerial::DataBits databit
               , AbstractSerial::StopBits stopbit)
    :m_name(name)
    ,m_rate(rate)
    ,m_parity(parity)
    ,m_databit(databit)
    ,m_stopbit(stopbit)
{

}

CXPCom::~CXPCom()
{

}

//拷贝构造函数
CXPCom::CXPCom(const CXPCom& src)
{
    if (this == &src)
    {
        return;
    }

    m_name = src.m_name;
    m_rate = src.m_rate;
    m_parity = src.m_parity;
    m_databit = src.m_databit;
    m_stopbit = src.m_stopbit;
}

//拷贝赋值函数
CXPCom& CXPCom::operator=(const CXPCom& src)
{
    if (this == &src)
    {
        return *this;
    }

    m_name = src.m_name;
    m_rate = src.m_rate;
    m_parity = src.m_parity;
    m_databit = src.m_databit;
    m_stopbit = src.m_stopbit;

    return *this;
}

//串口名称
void CXPCom::SetName(const QString& name)
{
    m_name = name;
}

QString CXPCom::GetName()
{
    return m_name;
}

//串口波特率
void CXPCom::SetRate(const QString& src)
{
    m_rate = AbstractSerial::BaudRateUndefined;

    quint32 ui32rate = src.toUInt();
    switch (ui32rate)
    {
    case 9600:
        m_rate = AbstractSerial::BaudRate9600;     /*!< \~english Speed 9600 bauds. */
        break;
    case 2400:
        m_rate = AbstractSerial::BaudRate2400;     /*!< \~english Speed 2400 bauds. */
        break;
    case 115200:
        m_rate = AbstractSerial::BaudRate115200;     /*!< \~english Speed 115200 bauds. */
        break;
        //以上波特率常用,提供switch匹配效率
    case 50:
        m_rate = AbstractSerial::BaudRate50;     /*!< \~english Speed 50 bauds. */
        break;
    case 75:
        m_rate = AbstractSerial::BaudRate75;     /*!< \~english Speed 75 bauds. */
        break;
    case 110:
        m_rate = AbstractSerial::BaudRate110;     /*!< \~english Speed 110 bauds. */
        break;
    case 134:
        m_rate = AbstractSerial::BaudRate134;     /*!< \~english Speed 134 bauds. */
        break;
    case 150:
        m_rate = AbstractSerial::BaudRate150;     /*!< \~english Speed 150 bauds. */
        break;
    case 200:
        m_rate = AbstractSerial::BaudRate200;     /*!< \~english Speed 200 bauds. */
        break;
    case 300:
        m_rate = AbstractSerial::BaudRate300;     /*!< \~english Speed 300 bauds. */
        break;
    case 600:
        m_rate = AbstractSerial::BaudRate600;     /*!< \~english Speed 600 bauds. */
        break;
    case 1200:
        m_rate = AbstractSerial::BaudRate1200;     /*!< \~english Speed 1200 bauds. */
        break;
    case 1800:
        m_rate = AbstractSerial::BaudRate1800;     /*!< \~english Speed 1800 bauds. */
        break;
        //2400
    case 4800:
        m_rate = AbstractSerial::BaudRate4800;     /*!< \~english Speed 4800 bauds. */
        break;
        //9600
    case 14400:
        m_rate = AbstractSerial::BaudRate14400;     /*!< \~english Speed 14400 bauds. */
        break;
    case 19200:
        m_rate = AbstractSerial::BaudRate19200;     /*!< \~english Speed 19200 bauds. */
        break;
    case 38400:
        m_rate = AbstractSerial::BaudRate38400;     /*!< \~english Speed 38400 bauds. */
        break;
    case 56000:
        m_rate = AbstractSerial::BaudRate56000;     /*!< \~english Speed 56000 bauds. */
        break;
    case 57600:
        m_rate = AbstractSerial::BaudRate57600;     /*!< \~english Speed 57600 bauds. */
        break;
    case 76800:
        m_rate = AbstractSerial::BaudRate76800;     /*!< \~english Speed 76800 bauds. */
        break;
        //115200
    case 128000:
        m_rate = AbstractSerial::BaudRate128000;     /*!< \~english Speed 128000 bauds. */
        break;
    case 230400:
        m_rate = AbstractSerial::BaudRate230400;     /*!< \~english Speed 230400 bauds. */     //enhanced speed (experimental)
        break;
    case 256000:
        m_rate = AbstractSerial::BaudRate256000;     /*!< \~english Speed 256000 bauds. */
        break;
    case 460800:
        m_rate = AbstractSerial::BaudRate460800;     /*!< \~english Speed 460800 bauds. */     //enhanced speed (experimental)
        break;
    case 500000:
        m_rate = AbstractSerial::BaudRate500000;     /*!< \~english Speed 500000 bauds. */     //enhanced speed (experimental)
        break;
    case 576000:
        m_rate = AbstractSerial::BaudRate576000;     /*!< \~english Speed 576000 bauds. */     //enhanced speed (experimental)
        break;
    case 921600:
        m_rate = AbstractSerial::BaudRate921600;     /*!< \~english Speed 921600 bauds. */     //enhanced speed (experimental)
        break;
    case 1000000:
        m_rate = AbstractSerial::BaudRate1000000;     /*!< \~english Speed 1000000 bauds. */    //enhanced speed (experimental)
        break;
    case 1152000:
        m_rate = AbstractSerial::BaudRate1152000;     /*!< \~english Speed 1152000 bauds. */    //enhanced speed (experimental)
        break;
    case 1500000:
        m_rate = AbstractSerial::BaudRate1500000;     /*!< \~english Speed 1500000 bauds. */    //enhanced speed (experimental)
        break;
    case 2000000:
        m_rate = AbstractSerial::BaudRate2000000;     /*!< \~english Speed 2000000 bauds. */    //enhanced speed (experimental)
        break;
    case 2500000:
        m_rate = AbstractSerial::BaudRate2500000;     /*!< \~english Speed 2500000 bauds. */    //enhanced speed (experimental)
        break;
    case 3000000:
        m_rate = AbstractSerial::BaudRate3000000;     /*!< \~english Speed 3000000 bauds. */    //enhanced speed (experimental)
        break;
    case 3500000:
        m_rate = AbstractSerial::BaudRate3500000;     /*!< \~english Speed 3500000 bauds. */    //enhanced speed (experimental)
        break;
    case 4000000:
        m_rate = AbstractSerial::BaudRate4000000;     /*!< \~english Speed 4000000 bauds. */    //enhanced speed (experimental)
        break;
    default:
        break;
    }
}

void CXPCom::SetRate(AbstractSerial::BaudRate rate /*= AbstractSerial::BaudRate9600*/)
{
    m_rate = rate;
}

AbstractSerial::BaudRate CXPCom::GetRate()
{
    return m_rate;
}

//串口校验位
void CXPCom::SetParity(const QString& src)
{
    m_parity = AbstractSerial::ParityUndefined;

    if (src.compare("none", Qt::CaseInsensitive))
    {
        m_parity = AbstractSerial::ParityNone;
    }
    else if (src.compare("odd", Qt::CaseInsensitive))
    {
        m_parity = AbstractSerial::ParityOdd;
    }
    else if (src.compare("even", Qt::CaseInsensitive))
    {
        m_parity = AbstractSerial::ParityEven;
    }
    else if (src.compare("mark", Qt::CaseInsensitive))
    {
        m_parity = AbstractSerial::ParityMark;
    }
    else if (src.compare("space", Qt::CaseInsensitive))
    {
        m_parity = AbstractSerial::ParitySpace;
    }
}

void CXPCom::SetParity(AbstractSerial::Parity parity /*= AbstractSerial::ParityNone*/)
{
    m_parity = parity;
}

AbstractSerial::Parity CXPCom::GetParity()
{
    return m_parity;
}

QString CXPCom::GetParityValue()
{
    QString strret = "";

    switch (m_parity)
    {
    case AbstractSerial::ParityNone:
        strret = "none";
        break;
    case AbstractSerial::ParityOdd:
        strret = "odd";
        break;
    case AbstractSerial::ParityEven:
        strret = "even";
        break;
    case AbstractSerial::ParityMark:
        strret = "mark";
        break;
    case AbstractSerial::ParitySpace:
        strret = "space";
        break;
    default:
        strret = "none";
        break;
    }

    return strret;
}

//串口数据位
void CXPCom::SetDataBit(const QString& src)
{
    m_databit = AbstractSerial::DataBitsUndefined;

    quint16 ui16databit = src.toUShort();

    switch (ui16databit)
    {
    case 5:
        m_databit = AbstractSerial::DataBits5;
        break;
    case 6:
        m_databit = AbstractSerial::DataBits6;
        break;
    case 7:
        m_databit = AbstractSerial::DataBits7;
        break;
    case 8:
        m_databit = AbstractSerial::DataBits8;
        break;
    default:
        break;
    }
}

void CXPCom::SetDataBit(AbstractSerial::DataBits databit /*= AbstractSerial::DataBits5*/)
{
    m_databit = databit;
}

AbstractSerial::DataBits CXPCom::GetDataBit()
{
    return m_databit;
}

QString CXPCom::GetDataBitValue()
{
    QString strret = "";

    switch (m_parity)
    {
    case AbstractSerial::DataBits5:
        strret = "5";
        break;
    case AbstractSerial::DataBits6:
        strret = "6";
        break;
    case AbstractSerial::DataBits7:
        strret = "7";
        break;
    case AbstractSerial::DataBits8:
        strret = "8";
        break;
    default:
        strret = "5";
        break;
    }

    return strret;
}

//串口停止位
void CXPCom::SetStopBit(const QString& src)
{
    m_stopbit = AbstractSerial::StopBitsUndefined;

    if ("1" == src)
    {
        m_stopbit =  AbstractSerial::StopBits1;
    }
    else if ("1.5" == src)
    {
        m_stopbit =  AbstractSerial::StopBits1_5;
    }
    else if ("2" == src)
    {
        m_stopbit =  AbstractSerial::StopBits2;
    }
}

void CXPCom::SetStopBit(AbstractSerial::StopBits stopbit /*= AbstractSerial::StopBits1*/)
{
    m_stopbit = stopbit;
}

AbstractSerial::StopBits CXPCom::GetStopBit()
{
    return m_stopbit;
}

QString CXPCom::GetStopBitValue()
{
    QString strret = "";

    switch (m_stopbit)
    {
    case AbstractSerial::StopBits1:
        strret = "1";
        break;
    case AbstractSerial::StopBits1_5:
        strret = "1.5";
        break;
    case AbstractSerial::StopBits2:
        strret = "2";
        break;
    default:
        strret = "1";
        break;
    }

    return strret;
}
