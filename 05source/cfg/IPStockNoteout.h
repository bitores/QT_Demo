#ifndef INI_PARAM_STOCK_NOTEOUT_H
#define INI_PARAM_STOCK_NOTEOUT_H

#include <QObject>

class CIPStockNoteout : public QObject
{
    Q_OBJECT
public:
    explicit CIPStockNoteout(QObject *parent = 0);
    ~CIPStockNoteout();

    //拷贝构造函数
    CIPStockNoteout(const CIPStockNoteout& src);
    //拷贝赋值函数
    CIPStockNoteout& operator=(const CIPStockNoteout& src);

public:
    bool GetMultiBoxFlag() const;
    void SetMultiBoxFlag(bool bMultiBoxFlag);

    qint32 GetBoxNum() const;
    void SetBoxNum(qint32 i32BoxNum);

    qint32 GetCurBoxIndex() const;
    void SetCurBoxIndex(qint32 i32CurBoxIndex);

    qint32 GetAllNum() const;
    void SetAllNum(qint32 i32AllNum);

    qint32 GetAllSum() const;
    void SetAllSum(qint32 i32AllSum);

    void Clear();
    
signals:
    
public slots:

public:
    bool                m_bMultiBoxFlag;        //是否多钞箱标记
    qint32              m_i32BoxNum;            //钞箱数量
    qint32              m_i32CurBoxIndex;       //当前钞箱索引,从0开始
    qint32              m_i32AllNum;            //全部钞箱数量
    qint32              m_i32AllSum;            //全部钞箱总额
    
};

#endif // INI_PARAM_STOCK_NOTEOUT_H
