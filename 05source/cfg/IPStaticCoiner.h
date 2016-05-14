#ifndef INI_PARAM_STATIC_COINER_H
#define INI_PARAM_STATIC_COINER_H

#include <QObject>
#include <QtCore/qstringlist.h>

class CIPStaticCoiner : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticCoiner(QObject *parent = 0);
    ~CIPStaticCoiner();
    
    //拷贝构造函数
    CIPStaticCoiner(const CIPStaticCoiner& src);
    //拷贝赋值函数
    CIPStaticCoiner& operator=(const CIPStaticCoiner& src);

public:
    qint32 GetCurFace() const;
    void SetCurFace(qint32 i32CurFace);

    qint32 GetMaxNum() const;
    void SetMaxNum(qint32 i32MaxNum);

    qint32 GetMinNum() const;
    void SetMinNum(qint32 i32MinNum);

    bool GetPerFlag() const;
    void SetPerFlag(bool bPerFlag);

    qint32 GetMaxInNumOfPer() const;
    void SetMaxInNumOfPer(qint32 i32MaxInNumOfPer);

    qint32 GetMaxOutNumOfPer() const;
    void SetMaxOutNumOfPer(qint32 i32MaxOutNumOfPer);

    void Clear();

signals:

public slots:

public:
    qint32              m_i32CurFace;           //当前面值
    qint32              m_i32MaxNum;            //最大数量
    qint32              m_i32MinNum;            //最小数量
    bool                m_bPerFlag;             //单次限制标记
    qint32              m_i32MaxInNumOfPer;     //单次最大入币数量
    qint32              m_i32MaxOutNumOfPer;    //单次最大出币数量

    
};

#endif // INI_PARAM_STATIC_COINER_H
