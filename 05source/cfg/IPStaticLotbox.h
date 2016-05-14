#ifndef INI_PARAM_STATIC_LOTBOX_H
#define INI_PARAM_STATIC_LOTBOX_H

#include <QObject>
#include <QtCore/qstringlist.h>

class CIPStaticLotbox : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticLotbox(QObject *parent = 0);
    ~CIPStaticLotbox();

    //拷贝构造函数
    CIPStaticLotbox(const CIPStaticLotbox& src);
    //拷贝赋值函数
    CIPStaticLotbox& operator=(const CIPStaticLotbox& src);

public:
    qint32 GetMaxFace() const;
    void SetMaxFace(qint32 i32MaxFace);

    qint32 GetMinFace() const;
    void SetMinFace(qint32 i32MinFace);

    qint32 GetMaxNum() const;
    void SetMaxNum(qint32 i32MaxNum);

    qint32 GetMinNum() const;
    void SetMinNum(qint32 i32MinNum);

    qint32 GetMaxNote() const;
    void SetMaxNote(qint32 i32MaxNote);

    qint32 GetMinNote() const;
    void SetMinNote(qint32 i32MinNote);

    qint32 GetBoxNum() const;
    void SetBoxNum(qint32 i32BoxNum);

    qint32 GetMaxNumOfOnce() const;
    void SetMaxNumOfOnce(qint32 i32MaxNumOfOnce);

    QStringList GetDisable();
    void SetDisable(const QStringList& slDisable);

    QStringList GetLotTypeID();
    void SetLotTypeID(const QStringList& slLotTypeID);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32MaxFace;           //最大面值
    qint32              m_i32MinFace;           //最小面值
    qint32              m_i32MaxNum;            //最大张数
    qint32              m_i32MinNum;            //最小张数
    qint32              m_i32MaxNote;           //最大本数
    qint32              m_i32MinNote;           //最小本数
    qint32              m_i32BoxNum;            //票箱数量    
    qint32              m_i32MaxNumOfOnce;      //单个出票模块的单次最大出票张数,最小为1,最大为100,默认值为50
    //模块索引从0开始,最大为7. 多个模块索引之间采用英文的双分号分隔.设备类型为L501时有效,为L500时未空值
    QStringList         m_slDisable;
    QStringList         m_slLotTypeID;          //票箱所卖的彩票类型
    
};

#endif // INI_PARAM_STATIC_LOTBOX_H
