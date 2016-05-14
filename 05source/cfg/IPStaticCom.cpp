#include "IPStaticCom.h"

CIPStaticCom::CIPStaticCom(QObject *parent) :
    QObject(parent)
  ,m_name("")
  ,m_rate(AbstractSerial::BaudRate9600)
  ,m_parity(AbstractSerial::ParityNone)
  ,m_databit(AbstractSerial::DataBits5)
  ,m_stopbit(AbstractSerial::StopBits1)
{
}

CIPStaticCom::CIPStaticCom(const QString& name
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

CIPStaticCom::CIPStaticCom(const QString& name, const QString& rate, const QString& parity
                           , const QString& databit, const QString& stopbit)
    :m_name(name)
{
    SetRate(rate);
    SetParity(parity);
    SetDataBit(databit);
    SetStopBit(stopbit);
}

CIPStaticCom::~CIPStaticCom()
{

}

//拷贝构造函数
CIPStaticCom::CIPStaticCom(const CIPStaticCom& src)
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
CIPStaticCom& CIPStaticCom::operator=(const CIPStaticCom& src)
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
void CIPStaticCom::SetName(const QString& name)
{
    m_name = name;
}

QString CIPStaticCom::GetName() const
{
    return m_name;
}

//串口波特率
void CIPStaticCom::SetRate(const QString& src)
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

void CIPStaticCom::SetRate(AbstractSerial::BaudRate rate /*= AbstractSerial::BaudRate9600*/)
{
    m_rate = rate;
}

AbstractSerial::BaudRate CIPStaticCom::GetRate() const
{
    return m_rate;
}

QString CIPStaticCom::GetRateValue() const
{
    switch (m_rate)
    {
    case AbstractSerial::BaudRate9600:
        return "9600";     /*!< \~english Speed 9600 bauds. */
        break;
    case AbstractSerial::BaudRate2400:
        return "2400";     /*!< \~english Speed 2400 bauds. */
        break;
    case AbstractSerial::BaudRate115200:
        return "115200";     /*!< \~english Speed 115200 bauds. */
        break;
        //以上波特率常用,提供switch匹配效率
    case AbstractSerial::BaudRate50:
        return "50";     /*!< \~english Speed 50 bauds. */
        break;
    case AbstractSerial::BaudRate75:
        return "75";     /*!< \~english Speed 75 bauds. */
        break;
    case AbstractSerial::BaudRate110:
        return "110";     /*!< \~english Speed 110 bauds. */
        break;
    case AbstractSerial::BaudRate134:
        return "134";     /*!< \~english Speed 134 bauds. */
        break;
    case AbstractSerial::BaudRate150:
        return "150";     /*!< \~english Speed 150 bauds. */
        break;
    case AbstractSerial::BaudRate200:
        return "200";     /*!< \~english Speed 200 bauds. */
        break;
    case AbstractSerial::BaudRate300:
        return "300";     /*!< \~english Speed 300 bauds. */
        break;
    case AbstractSerial::BaudRate600:
        return "600";     /*!< \~english Speed 600 bauds. */
        break;
    case AbstractSerial::BaudRate1200:
        return "1200";     /*!< \~english Speed 1200 bauds. */
        break;
    case AbstractSerial::BaudRate1800:
        return "1800";     /*!< \~english Speed 1800 bauds. */
        break;
        //2400
    case AbstractSerial::BaudRate4800:
        return "4800";     /*!< \~english Speed 4800 bauds. */
        break;
        //9600
    case AbstractSerial::BaudRate14400:
        return "14400";     /*!< \~english Speed 14400 bauds. */
        break;
    case AbstractSerial::BaudRate19200:
        return "19200";     /*!< \~english Speed 19200 bauds. */
        break;
    case AbstractSerial::BaudRate38400:
        return "38400";     /*!< \~english Speed 38400 bauds. */
        break;
    case AbstractSerial::BaudRate56000:
        return "56000";     /*!< \~english Speed 56000 bauds. */
        break;
    case AbstractSerial::BaudRate57600:
        return "57600";     /*!< \~english Speed 57600 bauds. */
        break;
    case AbstractSerial::BaudRate76800:
        return "76800";     /*!< \~english Speed 76800 bauds. */
        break;
        //115200
    case AbstractSerial::BaudRate128000:
        return "128000";     /*!< \~english Speed 128000 bauds. */
        break;
    case AbstractSerial::BaudRate230400:
        return "230400";     /*!< \~english Speed 230400 bauds. */     //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate256000:
        return "256000";     /*!< \~english Speed 256000 bauds. */
        break;
    case AbstractSerial::BaudRate460800:
        return "460800";     /*!< \~english Speed 460800 bauds. */     //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate500000:
        return "500000";     /*!< \~english Speed 500000 bauds. */     //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate576000:
        return "576000";     /*!< \~english Speed 576000 bauds. */     //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate921600:
        return "921600";     /*!< \~english Speed 921600 bauds. */     //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate1000000:
        return "1000000";     /*!< \~english Speed 1000000 bauds. */    //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate1152000:
        return "1152000";     /*!< \~english Speed 1152000 bauds. */    //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate1500000:
        return "1500000";     /*!< \~english Speed 1500000 bauds. */    //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate2000000:
        return "2000000";     /*!< \~english Speed 2000000 bauds. */    //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate2500000:
        return "2500000";     /*!< \~english Speed 2500000 bauds. */    //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate3000000:
        return "3000000";     /*!< \~english Speed 3000000 bauds. */    //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate3500000:
        return "3500000";     /*!< \~english Speed 3500000 bauds. */    //enhanced speed (experimental)
        break;
    case AbstractSerial::BaudRate4000000:
        return "4000000";     /*!< \~english Speed 4000000 bauds. */    //enhanced speed (experimental)
        break;
    default:
        return "";
        break;
    }
}

//串口校验位
void CIPStaticCom::SetParity(const QString& src)
{
    m_parity = AbstractSerial::ParityUndefined;

    if (0 == src.compare("None", Qt::CaseInsensitive))
    {
        m_parity = AbstractSerial::ParityNone;
    }
    else if (0 == src.compare("Odd", Qt::CaseInsensitive))
    {
        m_parity = AbstractSerial::ParityOdd;
    }
    else if (0 == src.compare("Even", Qt::CaseInsensitive))
    {
        m_parity = AbstractSerial::ParityEven;
    }
    else if (0 == src.compare("Mark", Qt::CaseInsensitive))
    {
        m_parity = AbstractSerial::ParityMark;
    }
    else if (0 == src.compare("Space", Qt::CaseInsensitive))
    {
        m_parity = AbstractSerial::ParitySpace;
    }
}

void CIPStaticCom::SetParity(AbstractSerial::Parity parity /*= AbstractSerial::ParityNone*/)
{
    m_parity = parity;
}

AbstractSerial::Parity CIPStaticCom::GetParity() const
{
    return m_parity;
}

QString CIPStaticCom::GetParityValue() const
{
    QString strret = "";

    switch (m_parity)
    {
    case AbstractSerial::ParityNone:
        strret = "None";
        break;
    case AbstractSerial::ParityOdd:
        strret = "Odd";
        break;
    case AbstractSerial::ParityEven:
        strret = "Even";
        break;
    case AbstractSerial::ParityMark:
        strret = "Mark";
        break;
    case AbstractSerial::ParitySpace:
        strret = "Space";
        break;
    default:
        strret = "None";
        break;
    }

    return strret;
}

//串口数据位
void CIPStaticCom::SetDataBit(const QString& src)
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

void CIPStaticCom::SetDataBit(AbstractSerial::DataBits databit /*= AbstractSerial::DataBits5*/)
{
    m_databit = databit;
}

AbstractSerial::DataBits CIPStaticCom::GetDataBit() const
{
    return m_databit;
}

QString CIPStaticCom::GetDataBitValue() const
{
    QString strret = "";

    switch (m_databit)
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
void CIPStaticCom::SetStopBit(const QString& src)
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

void CIPStaticCom::SetStopBit(AbstractSerial::StopBits stopbit /*= AbstractSerial::StopBits1*/)
{
    m_stopbit = stopbit;
}

AbstractSerial::StopBits CIPStaticCom::GetStopBit() const
{
    return m_stopbit;
}

QString CIPStaticCom::GetStopBitValue() const
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


void CIPStaticCom::Clear()
{
    m_name = "";
    m_rate = AbstractSerial::BaudRateUndefined;
    m_parity = AbstractSerial::ParityUndefined;
    m_databit = AbstractSerial::DataBitsUndefined;
    m_stopbit = AbstractSerial::StopBitsUndefined;
}
