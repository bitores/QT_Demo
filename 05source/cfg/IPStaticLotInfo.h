#ifndef INI_PARAM_STATIC_LOT_INFO_H
#define INI_PARAM_STATIC_LOT_INFO_H

#include <QObject>

class CIPStaticLotInfo : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticLotInfo(QObject *parent = 0);
    ~CIPStaticLotInfo();

    //拷贝构造函数
    CIPStaticLotInfo(const CIPStaticLotInfo& src);
    //拷贝赋值函数
    CIPStaticLotInfo& operator=(const CIPStaticLotInfo& src);

public:
    qint32 GetAllNum() const;
    void SetAllNum(qint32 i32AllNum);

    qint32 GetMaxFace() const;
    void SetMaxFace(qint32 i32MaxFace);

    qint32 GetMinFace() const;
    void SetMinFace(qint32 i32MinFace);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32AllNum;            //所有彩票的数量
    qint32              m_i32MaxFace;           //最大面值
    qint32              m_i32MinFace;           //最小面值
    
};

#endif // INI_PARAM_STATIC_LOT_INFO_H
