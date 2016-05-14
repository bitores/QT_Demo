#ifndef INI_PARAM_STATIC_LOT_H
#define INI_PARAM_STATIC_LOT_H

#include <QObject>

class CIPStaticLot : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticLot(QObject *parent = 0);
    ~CIPStaticLot();

    //拷贝构造函数
    CIPStaticLot(const CIPStaticLot& src);
    //拷贝赋值函数
    CIPStaticLot& operator=(const CIPStaticLot& src);

public:
    QString GetLotTypeID() const;
    void SetLotTypeID(const QString& strLotTypeID);

    QString GetName() const;
    void SetName(const QString& strName);

    qint32 GetFace() const;
    void SetFace(qint32 i32Face);

    QString GetFaceName() const;
    void SetFaceName(const QString& strFaceName);

    qint32 GetHighestBonus() const;
    void SetHighestBonus(qint32 i32HighestBonus);

    qint32 GetLotLen() const;
    void SetLotLen(qint32 i32LotLen);

    QString GetRate() const;
    void SetRate(const QString& strRate);

    QString GetLotPhoto() const;
    void SetLotPhoto(const QString& strLotPhoto);

    QString GetDescribeIco() const;
    void SetDescribeIco(const QString& strDescribeIco);

    QString GetDescribeText() const;
    void SetDescribeText(const QString& strDescribeText);

    void Clear();
    
signals:
    
public slots:

public:
    QString             m_strLotTypeID;         //彩票类型ID
    QString             m_strName;              //彩票名称
    qint32              m_i32Face;              //彩票面值
    QString             m_strFaceName;          //彩票面值名称
    qint32              m_i32HighestBonus;      //彩票最高奖金
    qint32              m_i32LotLen;            //彩票长度
    QString             m_strRate;              //彩票显示比例
    QString             m_strLotPhoto;          //彩票图片
    QString             m_strDescribeIco;       //描述小图标
    QString             m_strDescribeText;      //描述文本
    
};

#endif // INI_PARAM_STATIC_LOT_H
