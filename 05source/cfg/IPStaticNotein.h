#ifndef INI_PARAM_STATIC_NOTEIN_H
#define INI_PARAM_STATIC_NOTEIN_H

#include <QObject>
#include <QtCore/qstringlist.h>

class CIPStaticNotein : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticNotein(QObject *parent = 0);
    ~CIPStaticNotein();

    //拷贝构造函数
    CIPStaticNotein(const CIPStaticNotein& src);
    //拷贝赋值函数
    CIPStaticNotein& operator=(const CIPStaticNotein& src);

public:
    QStringList GetFaceList();
    void SetFaceList(const QStringList& slFaceList);

    qint32 GetMaxNum() const;
    void SetMaxNum(qint32 i32MaxNum);

    qint32 GetMinNum() const;
    void SetMinNum(qint32 i32MinNum);

    qint32 GetMaxSum() const;
    void SetMaxSum(qint32 i32MaxSum);

    qint32 GetMinSum() const;
    void SetMinSum(qint32 i32MinSum);

    bool GetPerFlag() const;
    void SetPerFlag(bool bPerFlag);

    qint32 GetMaxNumOfPer() const;
    void SetMaxNumOfPer(qint32 i32MaxNumOfPer);

    qint32 GetMaxSumOfPer() const;
    void SetMaxSumOfPer(qint32 i32MaxSumOfPer);

    void Clear();
    
signals:
    
public slots:

public:
    QStringList         m_slFaceList;           //面值列表,各面值之间用英文逗号分隔
    qint32              m_i32MaxNum;            //最大数量
    qint32              m_i32MinNum;            //最小数量
    qint32              m_i32MaxSum;            //最大金额
    qint32              m_i32MinSum;            //最小金额
    bool                m_bPerFlag;             //单次限制标记
    qint32              m_i32MaxNumOfPer;       //单次最大投入数量
    qint32              m_i32MaxSumOfPer;       //单次最大投入总额
    
};

#endif // INI_PARAM_STATIC_NOTEIN_H
